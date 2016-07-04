#include <stdio.h>
#include <gb/font.h>
#include <gb/console.h>
#include <gb/drawing.h>
#include <gb/gb.h>

#include "game/gameplay.h"
#include "game/splash.h"
#include "game/screen.h"

UBYTE ret;

screen_t gameplay_scrn;
screen_t splash_scrn;


// to be able to use WORD, we need to declare it
// outside the main function
screen_t* current_screen;

void main()
{
	gameplay_scrn.init_callback = game_start;
	gameplay_scrn.loop_callback = gameplay;

	splash_scrn.init_callback = splash_start;
	splash_scrn.loop_callback = splash_step;

	current_screen = &splash_scrn;
	screen_init( current_screen );

	while(1)
	{
		wait_vbl_done();
		ret = screen_loop( current_screen );

		switch( ret )
		{
		case 1:
			current_screen = &splash_scrn;
			screen_init( current_screen );
			break;
		case 2:
			current_screen = &gameplay_scrn;
			screen_init( current_screen );
			break;
		}
	}
}
