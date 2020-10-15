#include "shape.h"
#include "rectangle.h"
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

bool rectangle_ctor(rectangle_t *me, uint32_t position_x, uint32_t position_y, 
					uint32_t height, uint32_t width){



	me->super.position.x = position_x;
	me->super.position.y = position_y;
	me->height = height;
	me->width = width;



}



bool rectangle_rotate(rectangle_t *me, float angle){
	// Completar
}


uint32_t rectangle_get_area(rectangle_t *me){
	return me->height * me->width;
}
