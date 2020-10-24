#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "shape.h"
#include "line.h"


bool line_ctor(line_t *me, uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2){

	coordinates_array_t array;

	me->start.x = x1;
	me->start.y = y1;

	me->end.x = x2;
	me->end.y = y2;

    float m  = ((float)y2 - (float)y1)/((float)x2-(float)x1);
    float b = (float)y1 - ((((float)y2-(float)y1))/((float)x2-(float)x1))*(float)x1;

	int len = abs(x2-x1)+1;

	if(!(array.coordinates = (coordinate_t *) malloc(len*sizeof(coordinate_t)))){
		return false;
	}
	array.n_array = len;
	for(int i = 0; i < len; i++){
		if(x1 < x2){
			array.coordinates[i].x =  x1+i;
			array.coordinates[i].y = m * (x1+i) + b;
		} else {
			array.coordinates[i].x = x1-i;
			array.coordinates[i].y = m * (x1-i) + b;

		}
	}

	shape_ctor(&me->super, &array, x1, y1);
	free(array.coordinates);

	return true;
}

bool line_rotate(line_t *me, float angle){

	shape_rotate(&me->super, angle);

	int len = me->super.array.n_array;
	double x1_pivot = me->start.x;
	double y1_pivot = me->start.y;

	float c = cos((angle *3.14159)/180);
	float s = sin((angle *3.14159)/180);

    for(int i = 0; i < len; ++i){
    	double x2 = me->super.array.coordinates[i].x;
    	double y2 = me->super.array.coordinates[i].y;

    	x2 -= x1_pivot;
		y2 -= y1_pivot;

		me->super.array.coordinates[i].x = round(x2 * c - y2 * s + x1_pivot);
		me->super.array.coordinates[i].y = round(x2 * s + y2 * c + y1_pivot);
    }

    return true;

}


bool line_scale(line_t *me, float factor){


	int len = me->super.array.n_array;

	for(int i = 0; i < len; ++i){
		double x = me->super.array.coordinates[i].x;
		double y = me->super.array.coordinates[i].y;

		x = (x - me->super.position.x) * factor;
		y = (y - me->super.position.y) * factor;

		x = x + me->super.position.x;
		y = y + me->super.position.y;

		me->super.array.coordinates[i].x = round(x);
		me->super.array.coordinates[i].y = round(y);
	}

	me->start.x = round(me->start.x + 15);
	me->start.y = round(me->start.y + 15);
	me->end.x = round(me->end.x * factor);
	me->end.y = round(me->end.y * factor);

	return true;
}


float line_get_lenght(line_t *me){

	return sqrt( ( ((me->start.x)-(me->end.x)) * ((me->start.x)-(me->end.x)) ) + ( ((me->start.y)-(me->end.y)) * ((me->start.y)-(me->end.y)) ) );
}


