#include "brush.h"

void brush_paint( brush_t* brush, UBYTE ypos )
{
	UBYTE free_tile = 0;
	set_bkg_tiles( brush->x.b.h, ypos, 1, 1, &free_tile );
	set_bkg_tiles( brush->x.b.h+1, ypos, 1, 1, &free_tile );
	set_bkg_tiles( brush->x.b.h-1, ypos, 1, 1, &free_tile );
}

void brush_linear_translation( brush_t* brush )
{
	if( brush->sign == 0 )
	{
		brush->x.w += 0x27;
	}
	else
	{
		brush->x.w -= 0x27;
	}

	if( brush->sign == 0 && brush->x.w >= 0x1200 )
	{
		brush->sign = 1;
		brush->x.w = 0x1200;
	}

	if( brush->sign == 1 && brush->x.w < 0x0100 )
	{
		brush->sign = 0;
		brush->x.w = 0x0100;
	}
}

