// Jack Bailey
// 201509352

// The pgmMessage.h Header contains definitions for all messages and codes in the program
// This ensures that if an error occurs or the program exits successfully
// the program will exit with a meaningful error code and a sensible message

// SUCCESS EXIT CODES //
#define EXIT_SUCCESS 0
#define ECHOEDM "ECHOED\n"
#define MIDENTICAL "IDENTICAL\n"
#define MDIFFERENT "DIFFERENT\n"
#define MREDUCED "REDUCED\n"
#define MCONVERTED "CONVERTED\n"


// ERROR CODES AND CORRESPONDING MESSAGES
#define EXIT_WRONG_ARG_COUNT 1
    #define MESSAGE_WRONG_ARG_COUNT "ERROR: Bad Argument Count\n"
#define EXIT_BAD_FILE 2
    #define MESSAGE_BAD_FILE "ERROR: Bad File Name (%s)\n"
#define EXIT_BAD_MAGIC_NUMBER 3
    #define MESSAGE_BAD_MAGIC_NUMBER "ERROR: Bad Magic Number (%s)\n"
#define EXIT_BAD_COMMENT 4
    #define MESSAGE_BAD_COMMENT "ERROR: Bad Comment Line (%s)\n"
#define EXIT_BAD_SIZE 5
    #define MESSAGE_BAD_SIZE "ERROR: Bad Dimensions (%s)\n"
#define EXIT_BAD_GRAY_VALUES 6
    #define MESSAGE_BAD_GRAY_VALUES "ERROR: Bad Max Gray Value (%s)\n"
#define EXIT_BAD_MALLOC 7
    #define MESSAGE_BAD_MALLOC "ERROR: Image Malloc Failed (%s)\n"
#define EXIT_BAD_WRITE_VALUES 8
    #define MESSAGE_BAD_WRITE_VALUES "ERROR: Bad Data (%s)\n"
#define EXIT_BAD_OUTPUT_FILE 9
    #define MESSAGE_BAD_OUTPUT_FILE "ERROR: Output Failed (%s)\n"
#define EXIT_MISC 100
    #define MESSAGE_MISC "ERROR: Miscellaneous (%s)\n"