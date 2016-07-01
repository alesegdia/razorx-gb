
#include <stdio.h>

#include "gameplay.h"
#include "game/defs.h"
#include "track.h"

// graphics
#include "assets/razorx_gfx.h"
#include "assets/tiles_gfx.h"

UBYTE last_brush_y;
UBYTE player_x_tile;
UBYTE free_tile;
unsigned char player_tile;
fixed speed;
fixed last_brush_x;
fixed player_y;
fixed scroll_counter;

void game_start()
{
	last_brush_x.w = 0;
	free_tile = 0;
	player_x_tile = PLAYER_START_X;
	scroll_counter.w = player_y.w;
	last_brush_y = 0;
	speed.w = 0x0900;

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

#define USE_BRUSH_Y 0

void clear_row()
{
#ifdef USE_BRUSH_Y
	set_bkg_tiles( 1, -last_brush_y, 32, 1, row );
#else
	set_bkg_tiles( 1, -player_y.b.h / 8, 32, 1, row );
#endif
}

void advance_brush_y()
{
	last_brush_y += 1;
	if( last_brush_y >= 32 ) last_brush_y = 0;
}

/**
 * Paints a tile in the track with y fixed to @last_brush_y value
 */
void paint( UBYTE x )
{
#ifdef USE_BRUSH_Y
	set_bkg_tiles( x, -last_brush_y, 1, 1, &free_tile );
#else
	set_bkg_tiles( x, -player_y.b.h / 8, 1, 1, &free_tile );
#endif
}

void linear_brush_translation()
{
	last_brush_x.w += 0x10;
	if( last_brush_x.w > 0x0800 )
	{
		last_brush_x.w = 0x0100;
	}
}

void scroll()
{
	advance_brush_y();
	clear_row();
	paint( last_brush_x.b.h );

	// brush translation
	linear_brush_translation();
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

	get_bkg_tiles( player_x_tile, -player_y.b.h / 8, 1, 1, &player_tile );

	if( player_tile == 0 )
	{
		//speed.w += 0x0010;
	}
	else if( speed.w > 0x0050 )
	{
		//speed.w -= 0x0001;
	}

	move_bkg(0, -player_y.b.h);

	draw_player();
}

