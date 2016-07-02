#ifndef PAINTER_H
#define PAINTER_H

#include "brush.h"

typedef struct
{
	brush_t brushes[1];
} painter_t;

void painter_initialize( painter_t* painter )
{
	brush_initialize( painter->brushes[0], 1, 0x0300 );
}

void painter_scroll( painter_t* painter, UBYTE ypos )
{
	brush_linear_translation( painter->brushes );
	brush_paint( painter->brushes, ypos );
}

#endif
