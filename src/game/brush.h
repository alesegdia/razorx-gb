#ifndef BRUSH_H
#define BRUSH_H

#include <gb/gb.h>

typedef struct
{
	fixed x;
	UBYTE sign;
} brush_t;

void brush_initialize( brush_t* brush );
void brush_linear_translation( brush_t* brush );

#endif
