#include <stdio.h>
#include <gb/font.h>
#include <gb/console.h>
#include <gb/drawing.h>
#include <gb/gb.h>

#include "game/gameplay.h"
#include "game/splash.h"
#include "game/screen.h"

UBYTE joypad_state;

screen_t gameplay_scrn;
screen_t splash_scrn;


// to be able to use WORD, we need to declare it
// outside the main function

void main()
{
	gameplay_scrn.init_callback = game_start;
	gameplay_scrn.loop_callback = gameplay;

	splash_scrn.init_callback = splash_start;
	splash_scrn.loop_callback = splash_step;

	screen_change( &gameplay_scrn );

	while(1)
	{
		wait_vbl_done();
		screen_loop( &gameplay_scrn );
		//screen_loop( current_screen );
	}
}
