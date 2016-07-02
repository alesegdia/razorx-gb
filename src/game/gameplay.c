
#include <stdio.h>

#include "gameplay.h"
#include "game/defs.h"
#include "track.h"
#include "brush.h"

// graphics
#include "assets/razorx_gfx.h"
#include "assets/tiles_gfx.h"

// last y position of the brush
UBYTE last_brush_y;

// player x position in tiles
UBYTE player_x_tile;

// player y position in pixels; using fixed
fixed player_y;

// previous values of left and right buttons
UBYTE prev_left;
UBYTE prev_right;

// player vertical speed
fixed speed;

// used for not skipping a line in the painting
fixed scroll_counter;

// single brush to use (by now)
brush_t brush;

void game_start()
{
	// setup brushing
	brush_initialize( brush, 1, 0x0300 );
	scroll_counter.w = player_y.w;
	last_brush_y = 0;

	// setup player
	player_x_tile = PLAYER_START_X;
	speed.w = PLAYER_INITIAL_SPEED;

	// load background
	set_bkg_data(0, 2, maptiles);
	set_bkg_tiles(0, 0, lvl0_map.width, lvl0_map.height, lvl0_map.data);

	// load sprite
	set_sprite_data(0, 1, sprite);
	set_sprite_tile(0, 0);
}


unsigned char row[32] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

void clear_row()
{
	set_bkg_tiles( 1, -player_y.b.h / 8, 32, 1, row );
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
	UBYTE free_tile = 0;
	set_bkg_tiles( x, -player_y.b.h / 8, 1, 1, &free_tile );
}

void scroll()
{
	advance_brush_y();
	player_y.b.h = last_brush_y * 8;
	brush_linear_translation( &brush );
	clear_row();
	paint( brush.x.b.h );
}

void draw_player()
{
	move_sprite(0, player_x_tile * 8, PLAYER_Y * 8);
}


void gameplay(UBYTE joypad_state)
{
	UBYTE player_tile;

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
		speed.w += INCREASE_ACCEL;
	}
	else if( speed.w > PLAYER_INITIAL_SPEED )
	{
		speed.w -= DECREASE_ACCEL;
	}

	move_bkg(0, -player_y.b.h);

	draw_player();
}

