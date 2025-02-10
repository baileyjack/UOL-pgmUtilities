// Jack Bailey
// 201509352

// pgmEcho takes a pgm file and echoes it to another pgm file with a given name.

// DEFINITION AND FILE LINKER //
#include "pgmEcho.h"


// FUNCTION TO ECHO A PGM IMAGE FILE TO A GIVEN OUTPUT FILE

int main(int argc, char **argv){

    // ARGUMENT CHECKING //
    
    if (argc == 1){ // Check whether any arguments have been given
        // Print the Usage error if not
        printf("Usage: ./pgmEcho inputImage.pgm outputImage.pgm\n");
        return 0;
    }
    if (argc != 3){ // Check whether the correct number of arguments have been given
        // Print an error message and exit if there are an incorrect number of arguments
		printf(MESSAGE_WRONG_ARG_COUNT, argv[0]);
		return(EXIT_WRONG_ARG_COUNT);
    }

    // READ AND WRITE OF PGM //

    pgmImage pgm; // Create a new pgm image structure to store the data from the inputFile

    int errorvalue = pgmReader(argv[1], &pgm); // call pgmReader to read in the data from inputFile
    if (errorvalue != 0){ // If a non-0 error code was returned by pgmIO, return it again here to terminate the program
        return errorvalue;
    }

    int errorvalue2 = pgmWriter(argv[2], pgm); // call pgmWriter to write the data from the pgm struct to outputFile
    if (errorvalue2 != NULL){ // If a non-0 error code was returned by pgmIO, return it again here to terminate the program
        return errorvalue2;
    }

    // RETURN ON SUCCESS //

    printf(ECHOEDM); // With no returned error codes, exit with the 'ECHOED' success message
    return EXIT_SUCCESS; // and return code 0
}