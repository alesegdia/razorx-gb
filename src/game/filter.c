#include "filter.h"


void negate( unsigned char* data, UBYTE size )
{
	UBYTE i;
	for( i = 0; i < size; i++ )
	{
		data[i] = 0xff - data[i];
	}
}

void randomize( unsigned char* data, UBYTE size )
{
	UBYTE i;
	for( i = 0; i < size; i++ )
	{
		data[i] = data[i] & rand();
	}
}

void shuffle( unsigned char* data, UBYTE size )
{
	UBYTE d1, d2, tmp;
	UBYTE i;
	for( i = 0; i < size; i++ )
	{
		d1 = rand() % size;
		d2 = rand() % size;
		tmp = data[d1];
		data[d1] = data[d2];
		data[d2] = tmp;
	}
}
