
#include <stdio.h>

#include "splash.h"

void splash_start()
{

}

UBYTE splash_step()
{
	UBYTE joypad_state = joypad();
	if( joypad_state & J_A )
	{
		return 2;
	}
	return 0;
}
