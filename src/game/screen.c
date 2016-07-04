#include "screen.h"


void screen_init( screen_t* screen )
{
	disable_interrupts();
	DISPLAY_OFF;
	SPRITES_8x8;

	screen->init_callback();

	SHOW_BKG;
	SHOW_SPRITES;
	DISPLAY_ON;

	enable_interrupts();
}

UBYTE screen_loop( screen_t* screen )
{
	return screen->loop_callback();
}

