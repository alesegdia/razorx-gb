
#include <stdio.h>

#include "splash.h"

void splash_start()
{

}

UBYTE b = 0;

UBYTE splash_step()
{
	UBYTE joypad_state = joypad();
	if( !b )
	{
		b = 1;
		printf("Press A to start.\n");
	}

	if( joypad_state & J_A )
	{
		return 2;
	}
	return 0;
}
