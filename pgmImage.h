// Jack Bailey
// 201509352

// pgmImage.h defines a struct to hold image data.

#ifndef PGMIMAGE_H
#define PGMIMAGE_H

// STANDARD LIBRARY HEADER //
#include <stddef.h>

typedef struct pgmImage{ // A struct to store the data from a pgm file

    // The magic number
	// Raw:    0x5035 or P5
	// ASCII:  0x5032 or P2
    unsigned char magic_number[2];
	unsigned short *magic_Number;

    // One Comment Line
	char *commentLine;

	// The logical width & height
	unsigned int width;
    unsigned int height;

	// Assumed maximum gray value as an integer
	unsigned int maxGray;

	// Pointer to the raw image data
	unsigned char *imageData;

} pgmImage; // Defines this struct as a type pgmImage

#endif