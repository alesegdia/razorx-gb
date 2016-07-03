#include <stdio.h>
#include <gb/font.h>
#include <gb/console.h>
#include <gb/drawing.h>
#include <gb/gb.h>

#include "game/gameplay.h"
#include "game/screen.h"

UBYTE joypad_state;

screen_t gameplay_scrn;

// to be able to use WORD, we need to declare it
// outside the main function


void main()
{
	gameplay_scrn.loop_callback = gameplay;
	gameplay_scrn.init_callback = game_start;

	screen_init( &gameplay_scrn );

	while(1)
	{
		wait_vbl_done();
		screen_loop( &gameplay_scrn );
	}
}
