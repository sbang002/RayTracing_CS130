#include "driver.h"

bool Driver::Render_More()
{
    if(state_j>=Pixel_Height()) return true;
	#ifndef __FAST__
	if (state_i >= Pixel_Width()) {
		state_i = 0;
		state_j++;
	} else {
		ivec2 pixel_index(state_i, state_j);
		world.Render_Pixel(pixel_index);
		state_i++;
	}
	#else 
    for(int i=0;i<Pixel_Width();i++){
        ivec2 pixel_index(i,state_j);
        world.Render_Pixel(pixel_index);
    }
    state_j++;
    #endif

    return false;
}
