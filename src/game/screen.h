#ifndef SCREEN_H
#define SCREEN_H

#include <gb/gb.h>

typedef void (*screen_init_callback)();
typedef UBYTE (*screen_loop_callback)();

typedef struct
{
	screen_init_callback init_callback;
	screen_loop_callback loop_callback;
} screen_t;

void screen_init( screen_t* screen );
UBYTE screen_loop( screen_t* screen );

#endif
