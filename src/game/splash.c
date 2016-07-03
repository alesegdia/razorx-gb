
#include <stdio.h>

#include "splash.h"

void splash_start()
{

}

void splash_step()
{
	UBYTE joypad_state = joypad();

	if( joypad_state & J_A )
	{
		printf("meh");
	}
}
