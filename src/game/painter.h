#ifndef PAINTER_H
#define PAINTER_H

#include "brush.h"

typedef struct
{
	brush_t brushes[2];
} painter_t;

void painter_initialize( painter_t* painter );
void painter_scroll( painter_t* painter, UBYTE ypos );

#endif
