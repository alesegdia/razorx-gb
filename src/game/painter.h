#ifndef PAINTER_H
#define PAINTER_H

#include "brush.h"

typedef struct
{
	brush_t brushes[2];
} painter_t;

void painter_initialize( painter_t* painter )
{
	brush_initialize( painter->brushes[0], 1, 0x0300 );
	brush_initialize( painter->brushes[1], 0, 0x1000 );
}

void painter_scroll( painter_t* painter, UBYTE ypos )
{
	brush_linear_translation( painter->brushes );
	brush_paint( painter->brushes, ypos );
	brush_linear_translation( (&(painter->brushes[1])) );
	brush_paint( (&(painter->brushes[1])), ypos );
}

#endif
