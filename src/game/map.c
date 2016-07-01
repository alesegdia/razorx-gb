#include "map.h"

unsigned char get_tilemap_tile( map_t* map, int x, int y )
{
	/*
	if( (WORD)x < 0 )
	{
		//x += 63;
	}
	*/
	if( x >= 0 && x < map->width && y >= 0 && y < map->height )
	{
		int index = map->width * y + x;
		return map->data[index];
	}
	return 0;
}

unsigned char* get_tilemap_data_ptr( map_t* map, int x, int y )
{
	return map->data + (map->width * y + x);
}
