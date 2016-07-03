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

void screen_loop( screen_t* screen )
{
	screen->loop_callback();
}

void screen_change( screen_t* new_screen )
{
	current_screen = new_screen;
	screen_init( current_screen );
}

