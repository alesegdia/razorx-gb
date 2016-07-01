
#include <stdio.h>

#include "gameplay.h"
#include "game/defs.h"
#include "track.h"

// graphics
#include "assets/razorx_gfx.h"
#include "assets/tiles_gfx.h"

fixed player_y;
fixed scroll_counter;
UBYTE player_x_tile;
UBYTE free_tile;
fixed speed;
fixed last_tile_pos;
unsigned char player_tile;

void game_start()
{
	last_tile_pos.w = 0;
	free_tile = 0;
	player_x_tile = PLAYER_START_X;
	scroll_counter.w = 0;
	speed.w = 0x0050;

	// load background
	set_bkg_data(0, 2, maptiles);
	set_bkg_tiles( 0, 0, lvl0_map.width, lvl0_map.height, lvl0_map.data);

	// load sprite
	set_sprite_data(0, 1, sprite);
	set_sprite_tile(0, 0);
}


UBYTE prev_left;
UBYTE prev_right;


unsigned char row[32] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};


void scroll()
{
	set_bkg_tiles( 1, -player_y.b.h / 8, 32, 1, row );
	set_bkg_tiles( last_tile_pos.b.h, -player_y.b.h / 8, 1, 1, &free_tile );
	last_tile_pos.w += 0x50;
	if( last_tile_pos.w > 0x0800 )
	{
		last_tile_pos.w = 0x0100;
	}
}

void draw_player()
{
	move_sprite(0, player_x_tile * 8, PLAYER_Y * 8);
}


void gameplay(UBYTE joypad_state)
{
	if(joypad_state & J_LEFT)
	{
		if( !prev_left && player_x_tile > 1 )
		{
			player_x_tile--;
		}
		prev_left = 1;
	}
	else
	{
		prev_left = 0;
	}

	if(joypad_state & J_RIGHT)
	{
		if( !prev_right && player_x_tile < 20 )
		{
			player_x_tile++;
		}
		prev_right = 1;
	}
	else
	{
		prev_right = 0;
	}

	player_y.w += speed.w;
	scroll_counter.w += speed.w;

	while( scroll_counter.w > 0x0800 )
	{
		scroll_counter.w -= 0x0800;
		scroll();
	}

	get_bkg_tiles( player_x_tile, player_y.b.h / 8, 1, 1, &player_tile );
	move_bkg(0, -player_y.b.h);

	draw_player();
}

