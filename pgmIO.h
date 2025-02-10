// Jack Bailey
// 201509352

// pgmIO.h contains definitions and inclusions for pgmIO.c

// USER DEFINED HERADERS //
#include "pgmImage.h"
#include "pgmMessage.h"

// STANDARD LIBRARY HEADERS //
#include <stdio.h>
#include <stdlib.h>

// REQUIRED DEFINITIONS FOR PGM READING //
#define MAGIC_NUMBER_RAW_PGM 0x3550
#define MAGIC_NUMBER_ASCII_PGM 0x3250
#define MIN_IMAGE_DIMENSION 1
#define MAX_IMAGE_DIMENSION 65535
#define MAX_COMMENT_LINE_LENGTH 128

// Definition of pgmReader so it can be used in any other module
int pgmReader(char *inputName, pgmImage *pgm);

// Definition of pgmWriter so it can be used in any other module
int pgmWriter(char *outName, pgmImage pgm);