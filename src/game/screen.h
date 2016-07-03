#ifndef SCREEN_H
#define SCREEN_H

#include <gb/gb.h>

typedef void (*screen_callback)();

typedef struct
{
	screen_callback init_callback;
	screen_callback loop_callback;
} screen_t;

void screen_init( screen_t* screen );
void screen_loop( screen_t* screen );
void screen_change( screen_t* new_screen );

screen_t* current_screen;

#endif
