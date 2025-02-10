// Jack Bailey
// 201509352

// pgmComp.h contains definitions and inclusions for pgmComp.c

// USER DEFINED HEADERS //
#include "pgmMessage.h"
#include "pgmImage.h"
#include "pgmIO.h"

// STANDARD LIBRARY HEADERS //
#include <stdio.h>

// Definition for the compare function so it can be used in any other module
int compare(pgmImage pgm1, pgmImage pgm2);