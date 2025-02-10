// Jack Bailey
// 201509352

// pgmReduce.c will reduce a pgm image file by a given factor

// DEFINITION AND FILE LINKER //
#include "pgmReduce.h"


// A FUNCTION TO REDUCE A GIVEN PGM IMAGE BY A GIVEN FACTOR //

int main(int argc, char **argv){

    // ARGUMENT CHECKING //

    if (argc == 1){ // If there are not a correct number
        printf("Usage: ./pgmReduce inputImage.pgm reduction_factor outputImage.pgm\n");
        return 0;
    }
    if (argc != 4){	// If the number of command line arguments is wrong 
        // Printh an error message and exit with an error code
		printf(MESSAGE_WRONG_ARG_COUNT, argv[0]);
		return(EXIT_WRONG_ARG_COUNT);
    }

    if (argv[2][0] == '-' || argv[2] == '0'){
       printf(MESSAGE_MISC, "A Non-Positive Reduction Factor was provided.");
        return(EXIT_MISC);
    } else if (atoi(argv[2]) == 0){
       printf(MESSAGE_MISC, "A Non-Numeric reduction Factor was provided.");
        return(EXIT_MISC);
    }

    // SET VARIABLE VALUES BASED ON CLI ARGUMENTS //

    char *inputFileName = argv[1]; // Sets the input file name
    char *outputFileName = argv[3]; // Sets the output file name
    int reductionValue = atoi(argv[2]); // Sets the reduction valie

    // READ INPUT FILE //

	FILE *inputFile = fopen(inputFileName, "r"); // Read the file in ASCII mode

	if (inputFile == NULL){ // If the file could not be opened
        // Print an error message and return an error value
        printf(MESSAGE_BAD_FILE, argv[1]);
		return(EXIT_BAD_FILE);
    }

    pgmImage pgm; // Create a structure for the given pgm image
    pgmImage newpgm; // Create a structure for the new pgm image

    int errorvalue = pgmReader(inputFileName, &pgm); // Tries to read the data from the given pgm image file
    if (errorvalue != 0){ // If the return value from pgmReader is not 0 (indicating success)
        return errorvalue; // Return the error value to exit the program
    }

    // WRITE OUTPUT FILE //

    newpgm.width = (int) ceil(pgm.width / (float) reductionValue); // Set the new pgm file's width to the calculated value
    newpgm.height = (int) ceil(pgm.height / (float) reductionValue); // Set the new pgm file's height to the calculated value
    newpgm.commentLine = pgm.commentLine; // Copy the comment line
    newpgm.magic_number[0] = pgm.magic_number[0]; // Copy the magic number (1)
    newpgm.magic_number[1] = pgm.magic_number[1]; // Copy the magic number (2)
    newpgm.maxGray = 255;

    newpgm.imageData = (unsigned char*) malloc (newpgm.width * newpgm.height * sizeof(unsigned char)); // Allocate memory for the image data of the new file
    if (newpgm.imageData == NULL){
        printf(MESSAGE_BAD_MALLOC, argv[3]);
        return EXIT_BAD_MALLOC;
    }

    unsigned char pgm2D[pgm.height][pgm.width];
    unsigned char *nextGrayValue = pgm.imageData; // Allocate memory for efficient writing of values
    for (int i = 0; i < pgm.height; i++){
        for (int j = 0; j < pgm.width; j++){
            pgm2D[i][j] = *nextGrayValue;
            nextGrayValue++;
        }
    }
    *nextGrayValue = pgm.imageData;
    unsigned char *newImage = newpgm.imageData;

    for (int i = 0; i < pgm.height; i++){
        //printf(" Value i: %i / %i = %i \n", i, reductionValue, i%reductionValue);
        if (i % reductionValue == 0){
            for (int j = 0; j < pgm.width; j++){
                //printf("  Value j: %i / %i = %i \n", j, reductionValue, j%reductionValue);
                if (j % reductionValue == 0){
                    *nextGrayValue = pgm2D[i][j];
                    *newImage = *nextGrayValue;
                    //printf("\n WRITE VALUE %u \n", *nextGrayValue);
                    newImage++;
                }
            }
        }
    }
    int errorvalue2 = pgmWriter(argv[3], newpgm); // call pgmWriter to write the data from the pgm struct to outputFile
    if (errorvalue2 != 0){ // If a non-0 error code was returned by pgmIO, return it again here to terminate the program
        return errorvalue2;
    }
    
    // On successful execution, print a success message and return the 0 error code
    printf(MREDUCED);
    return EXIT_SUCCESS;

}