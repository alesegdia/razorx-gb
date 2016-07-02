#ifndef BRUSH_H
#define BRUSH_H

#include <gb/gb.h>

typedef struct
{
	fixed x;
	UBYTE sign;
} brush_t;

#define brush_initialize(b, s, v) \
	b.sign = s; \
	b.x.w = v

void brush_linear_translation( brush_t* brush );

#endif
