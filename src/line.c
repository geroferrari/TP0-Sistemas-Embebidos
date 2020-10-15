#include "shape.h"
#include "line.h"
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

bool line_ctor(line_t *me, uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2){


	me->start.x = x1;
	me->start.y = y1;
	me->end.x = x2;
	me->end.y = y2;

    float m  = (y2 - y1)/((float)x2-x1);
    float b = y1 - ((y2-y1))/((float)x2-x1)*x1;

	int l = abs(y2-y1) + 1;

	// mem alloc for line coordinates
	if (!(me->super.array.coordinates = (coordinate_t*)malloc(sizeof(coordinate_t)*l))){
		return false;
	}

	me->super.array.n_array = l;

	for(int i = 0; i < l; i++){
		if(x1 < x2){
			me->super.array.coordinates[i].x = x1+i;
			me->super.array.coordinates[i].y = m * (x1+i) + b;
		} else {
			me->super.array.coordinates[i].x = x1-i;
			me->super.array.coordinates[i].y = m * (x1-i) + b;
		}
	}
	return true;
}


bool line_rotate(line_t *me, float angle){

	uint32_t x1 = me->start.x;
	uint32_t y1 = me->start.y;

	uint32_t x2 = me->end.x;
	uint32_t y2 = me->end.y;

	x1 = x1*cos(angle) - y1*sin(angle);
	y1 = y1*cos(angle) + x1*sin(angle);
	x2 = x2*cos(angle) - y2*sin(angle);
	y2 = y2*cos(angle) + x2*sin(angle);

	//incompleto
}


bool line_scale(line_t *me, float factor){
	me->start.x = me->start.x * factor;
	me->start.y = me->start.y * factor;
	me->end.x = me->end.x * factor;
	me->end.y = me->end.y * factor;

	return true;
}


float line_get_lenght(line_t *me){

	return sqrt( ( ((me->start.x)-(me->end.x)) * ((me->start.x)-(me->end.x)) ) + ( ((me->start.y)-(me->end.y)) * ((me->start.y)-(me->end.y)) ) );
}


