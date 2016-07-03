#ifndef SCREEN_H
#define SCREEN_H

#include <gb/gb.h>

typedef void (*screen_init_callback)();
typedef void (*screen_loop_callback)(UBYTE);

typedef struct
{
	screen_loop_callback loop_callback;
	screen_init_callback init_callback;
} screen_t;

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
	UBYTE joypad_state = joypad();
	gameplay(joypad_state);
}

#endif
