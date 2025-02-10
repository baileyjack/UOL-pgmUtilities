// Jack Bailey
// 201509352

// pgmComp.c compares two given pgm files to check whether they are logically equivalent

// DEFINITION AND FILE LINKER //
#include "pgmComp.h"


// FUNCTION TO COMPARE TWO PGM FILES FOR LOGICAL EQUIVALENCE //

int compare(pgmImage pgm1, pgmImage pgm2){

    if (pgm1.width != pgm2.width){ // If the files do not have the same width
        return 0; // Return 0 to the main function to state the files are not identical
    }

    else if (pgm1.height != pgm2.height){ // If the files do not have the same height
        return 0; // Return 0 to the main function to state the files are not identical
    }

    else if (pgm1.maxGray != pgm2.maxGray){ // If the files do not have the same maxGray values
        return 0; // Return 0 to the main function to state the files are not identical
    }

    int numOfCells = pgm1.width * pgm1.height; // Set the number of cells in the image to the width * height of the file(s)

	for (int i = 0; i < numOfCells; i++){ // For the number of cells in the file

        if (pgm1.imageData[i] != pgm2.imageData[i]){ // If the image data is not identical in both files
            return 0; // Return 0 to the main function to state the files are not identical
        }
    }
    return 1; // Provided the files are logically identical, return 1
}


// FUNCTION TO PREPARE FOR COMPARISON OF TWO PGM IMAGE FILES //

int main(int argc, char **argv){

    // ARGUMENT CHECKING //

    if (argc == 1){ // Check whether any arguments have been given
        // Print the Usage error if not
        printf("Usage: ./pgmComp inputImage.pgm inputImage.pgm\n");
        return 0;
    }
    if (argc != 3){	// Check whether the correct number of arguments have been given
        // Print an error message and exit if there are an incorrect number of arguments
		printf(MESSAGE_WRONG_ARG_COUNT, argv[0]);
		return(EXIT_WRONG_ARG_COUNT);
    }


    // READ BOTH PGM FILES //

    pgmImage pgm1; // Create a new pgmImage struct for the first image

    int errorvalue = pgmReader(argv[1], &pgm1); // call pgmReader to read in the data from file 1
    if (errorvalue != 0){ // If a non-0 error code was returned by pgmIO return it here to terminate the program
        return errorvalue;
    }

    pgmImage pgm2; // Create a new pgmImage struct for the second image

    int errorvalue2 = pgmReader(argv[2], &pgm2); // call pgmReader to read in the data from file 2
    if (errorvalue2 != 0){ // If a non-0 error code was returned by pgmIO return it here to terminate the program
        return errorvalue2;
    }



    
    // RUN COMPARISON //

    if (compare(pgm1, pgm2) == 1){ // Call the compare() function, giving it both pgm files to work with
        // If the compare function returns 1, the files are identical
        printf(MIDENTICAL); // Print this fact and return the success code (0)
        return EXIT_SUCCESS;
    } else { // if the compare function returns any other value (namely 0), the pgm files are different
        printf(MDIFFERENT); // Print this fact and return the success code
        return EXIT_SUCCESS;
    }
}