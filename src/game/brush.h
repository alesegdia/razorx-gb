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

void brush_paint( brush_t* brush, UBYTE ypos )
{
	UBYTE free_tile = 0;
	set_bkg_tiles( brush->x.b.h, ypos, 1, 1, &free_tile );
	set_bkg_tiles( brush->x.b.h+1, ypos, 1, 1, &free_tile );
	set_bkg_tiles( brush->x.b.h-1, ypos, 1, 1, &free_tile );
}

#endif
