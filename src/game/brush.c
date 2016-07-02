#include "brush.h"

void brush_initialize( brush_t* brush )
{
	brush->sign = 1;
	brush->x.w = 0x0800;
}

void brush_linear_translation( brush_t* brush )
{
	if( brush->sign == 0 )
	{
		brush->x.w += 0x10;
	}
	else
	{
		brush->x.w -= 0x10;
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

