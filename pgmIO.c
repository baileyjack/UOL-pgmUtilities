// Jack Bailey
// 201509352

// pgmIO provides reading and writing capabilities for a PGM file, both in ASCII and Binary forms

// DEFINITION AND FILE LINKER //
#include "pgmIO.h"


// FUNCTION TO READ IN A PGM IMAGE FILE //

int pgmReader(char *inputName, pgmImage *pgm){

	// FILE OPENING //

	FILE *inputFile = fopen(inputName, "rb"); // Open the given input file
	if (inputFile == NULL){ // if the file is non-existent
		// return the error code and print an error message
        printf(MESSAGE_BAD_FILE, inputName);
		return(EXIT_BAD_FILE);
    }

	// COPY MAGIC NUMBER TO PGM STRUCT //

    pgm->magic_number[0] = getc(inputFile);
	pgm->magic_number[1] = getc(inputFile);

	if ( (pgm->magic_number[0] != 'P') || ((pgm->magic_number[1] != '2') && (pgm->magic_number[1] != '5')) ) {
		// If the magic number is not valid return errors
		printf(MESSAGE_BAD_MAGIC_NUMBER, inputName);
		return(EXIT_BAD_MAGIC_NUMBER);
	}

	unsigned short *magic_Number = (unsigned short *) pgm->magic_number; // Check to ensure the magic number is viable
      
	int scanCount = fscanf(inputFile, " "); // Scan for whitespace
    
	// SCAN FOR A COMMENT LINE //

	char nextChar = fgetc(inputFile); // Reads the next character in the file
	if (nextChar == '#') { // If there is a #, there is a comment line        
		// Allocate memory for the comment line
		pgm->commentLine = (char *) malloc(MAX_COMMENT_LINE_LENGTH);
		if (pgm->commentLine == NULL){ // Check whether the memory allocation worked
			// If not, free the memory we allocated  and close the file             
			free(pgm->commentLine);         
			fclose(inputFile);
			// Print an error message and provide an error code
			printf(MESSAGE_BAD_MALLOC, inputName);	        
			return EXIT_BAD_MALLOC;
			}

		// Read a line of the file to capture the comment line
		char *commentString;
		for (int i = 0; i < MAX_COMMENT_LINE_LENGTH; i++){
			char character = fgetc(inputFile);
			if (character != '\n'){
				commentString = commentString + character;
			} else {
				i = MAX_COMMENT_LINE_LENGTH;
				ungetc(character, inputFile);
			}
		}
		char next = fgetc(inputFile);
		if (next != '\n' && next != "-" && next != "1" && next != "2" && next != "3" && next != "4" && next != "5" && next != "6" && next != "7" && next != "8" && next != "9") {
			printf(MESSAGE_BAD_COMMENT, inputName);	    
			return EXIT_BAD_COMMENT;
		} else {
			ungetc(next, inputFile);
		}
		if (commentString == NULL){ // If there is not a comment string returned by fgets
			// Free the memory we allocated and close the file
			free(pgm->commentLine);  
			fclose(inputFile);
			// Then print an error message and return an error code
			printf(MESSAGE_BAD_COMMENT, inputName);	    
			return EXIT_BAD_COMMENT;
		}
		pgm->commentLine = commentString;
	} else { // If there is no comment line
		// Return the grabbed character to the file          
		ungetc(nextChar, inputFile);
	}

	// READ IN WIDTH, HEIGHT, AND GRAYS //

	scanCount = fscanf(inputFile, " %u %u %u", &(pgm->width), &(pgm->height), &(pgm->maxGray)); // Whitespace is included to ensure no spaces are read and an incorrect error is thrown

	if ( pgm->maxGray != 255 ){ // If the max gray value of the image is not 255
		printf(MESSAGE_BAD_GRAY_VALUES, inputName);
		return EXIT_BAD_GRAY_VALUES;
		}

	if 	(
		(scanCount != 3							)   || // If there are not 3 values read in OR
		(pgm->width 	< MIN_IMAGE_DIMENSION	) 	|| // If the width is less than the minimum image dimension OR
		(pgm->width 	> MAX_IMAGE_DIMENSION	) 	|| // If the width is greater than the maximum image dimension OR
		(pgm->height	< MIN_IMAGE_DIMENSION   )   || // If the height is less than the minimum image dimension OR
		(pgm->height 	> MAX_IMAGE_DIMENSION	)      // If the height is greater than the maximum image dimension OR
		)
		{
		
		// Then print an error message and give an error message
		printf(MESSAGE_BAD_SIZE, inputName);

		// Free the memory we allocated to these values and close the file
		fclose(inputFile);	           

		return EXIT_BAD_SIZE;
		}  
	
	// ASSIGN MEMORY FOR IMAGE DATA READING //
            
	long nImageBytes = pgm->width * pgm->height * sizeof(unsigned char); // Allocate the data pointer for the number of image bytes
	pgm->imageData = (unsigned char *) malloc(nImageBytes);

	if (pgm->imageData == NULL){ // Check whether the memory allocation worked
		// If not, free the memory we allocated earlier and close the file             
		free(pgm->imageData);         
		fclose(inputFile);
		// Print an error message and provide an error code
		printf(MESSAGE_BAD_MALLOC, inputFile);	        
		return EXIT_BAD_MALLOC;
	}

	// READ MAGIC NUMBER AND READ DEPENDING ON FILE TYPE //

	if (*magic_Number == MAGIC_NUMBER_ASCII_PGM){ // If the magic number states the pgm file is in ASCII form
		unsigned char *nextGrayValue = pgm->imageData; // Pointer used to efficiently read code

		for (*nextGrayValue; nextGrayValue < pgm->imageData + nImageBytes; nextGrayValue++){ // For each item in the image
			int grayValue = -1; 
			int scanCount = fscanf(inputFile, " %u", &grayValue); // Scan the file for the next item
			if (scanCount == NULL){ // If the next piece of data read is NULL, there is too little data.
				printf(MESSAGE_BAD_WRITE_VALUES, inputFile);
				return EXIT_BAD_WRITE_VALUES;
			}

			if ((scanCount != 1) || (grayValue < 0) || (grayValue > 255)){ // If the read fails
				// Close the file
				fclose(inputFile);
				// Print an error message and return an error code
				printf(MESSAGE_BAD_WRITE_VALUES, inputName);	
				return EXIT_BAD_WRITE_VALUES;
			}
		*nextGrayValue = (unsigned char) grayValue; // Set the pixel value for each gray value
		}
	} else {
			char checkChar = fgetc(inputFile);
			if (checkChar != '\n'){
				ungetc(checkChar, inputFile);
			}
			checkChar = fgetc(inputFile);
			if (checkChar != '\n'){
				ungetc(checkChar, inputFile);
			}

			int t = fread(pgm->imageData, sizeof(unsigned char), pgm->width * pgm->height, inputFile);
			if (t != pgm->width * pgm->height){
				printf(MESSAGE_BAD_WRITE_VALUES, inputName);
				return EXIT_BAD_WRITE_VALUES;
			}
		}

	// Throw an error if there is more data to read
	if (*magic_Number == MAGIC_NUMBER_ASCII_PGM){
		char final = fgetc(inputFile);
	}
	if ((fread(pgm->imageData, sizeof(unsigned char), 1, inputFile) != NULL)){
		printf(MESSAGE_BAD_WRITE_VALUES, inputName);
		return EXIT_BAD_WRITE_VALUES;
	}
	

	fclose(inputFile); // CLose the file once we're finished
	return EXIT_SUCCESS; // And return the 0 Exit Code to say we succeeded
}





// FUNCTION TO WRITE A PGM IMAGE FILE

int pgmWriter(char *outName, pgmImage pgm){

	// FILE OPENING //

	FILE *outputFile = fopen(outName, "wb"); // Open the given output file
	if (outputFile == NULL){ // If the output file is not valid
		// Print an error message and return an error code
		printf(MESSAGE_BAD_OUTPUT_FILE, outName);	
		return EXIT_BAD_OUTPUT_FILE;
	}
	
	// WRITE MAGIC NUMBER AND GRAY VALUES //

	unsigned short *magic_Number = (unsigned short *) pgm.magic_number; // Assign memory for the magic number
	size_t nBytesWritten = fprintf(outputFile, "P%c\n%d %d\n%d\n", pgm.magic_number[1], pgm.width, pgm.height, pgm.maxGray); // Write the MN, W, H, MG values to the file

	if (nBytesWritten < 0) { // If the number of bytes written to the file is less than 0 (so the write failed)
		// Free memory
		free(pgm.magic_Number);

		// Print an error message and return an error code
		printf(MESSAGE_BAD_WRITE_VALUES, outName);	
		return MESSAGE_BAD_WRITE_VALUES;
	}

		// WRITE THE IMAGE DATA DEPENDING ON MAGIC NUMBER //

		long nImageBytes = pgm.width * pgm.height * sizeof(unsigned char); // Create a variable for the number of bytes we need to write

		if (*magic_Number == MAGIC_NUMBER_ASCII_PGM){ // If the magic number states the pgm file is in ASCII form
			unsigned char *nextGrayValue = pgm.imageData; // Allocate memory for efficient writing of values

        	for (*nextGrayValue; nextGrayValue < pgm.imageData + nImageBytes; nextGrayValue++){ // For each gray value
				// Write the values to the pgm file
				int nextCol = (nextGrayValue - pgm.imageData + 1) % pgm.width; 
				nBytesWritten = fprintf(outputFile, "%d%c", *nextGrayValue, (nextCol ? ' ' : '\n'));

					if (nBytesWritten < 0){ // If no bytes have been written, the write has failed
						// Print an error message and return an error code
						printf(MESSAGE_BAD_WRITE_VALUES, outName);	
						return MESSAGE_BAD_WRITE_VALUES;
					}
			} 
		}

		if (*magic_Number == MAGIC_NUMBER_RAW_PGM){ // If the magic number states that the pgm file is in binary form
			// Write the raw binary to the file
			fwrite(pgm.imageData, sizeof(unsigned char), nImageBytes, outputFile);
		}

	return EXIT_SUCCESS; // Return the exit code 0 to state the write finished sucessfully. 
}