#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "shape.h"
#include "image.h"

bool shape_ctor(shape_t *me, coordinates_array_t *array, uint32_t position_x, uint32_t position_y){

	me->position.x = position_x;
	me->position.y = position_y;

	if (!(me->array.coordinates = (coordinate_t*)malloc(sizeof(coordinate_t)*array->n_array))){
			return false;
		}

	me->array.n_array = array->n_array;

	for( int i=0; i < me->array.n_array; i++){
		me->array.coordinates[i] = array->coordinates[i];
	}

	return true;
}


void shape_dtor(shape_t *me){


	free(me->array.coordinates);
}


bool shape_move(shape_t *me, uint32_t dx, uint32_t dy){

	me->position.x += dx;
	me->position.y += dy;

	return true;
}




bool shape_rotate(shape_t * me, float angle){

	int l = me->array.n_array;
	float c = cos((angle *3.14159)/180);
    float s = sin((angle *3.14159)/180);

    double x_pivot = me->position.x;
    double y_pivot = me->position.y;

    for(int i = 0; i < l; ++i){

		double x1 = me->array.coordinates[i].x;
		double y1 = me->array.coordinates[i].y;

		x1 -= x_pivot;
		y1 -= y_pivot;

		double x = x1 * c - y1 * s + x_pivot  ;
		double y = x1 * s + y1 * c + y_pivot ;

		me->array.coordinates[i].x = round(x);
		me->array.coordinates[i].y = round(y);
	}

	return true;
}



bool shape_plot(shape_t *me, image_t *image){

	for(int i = 0; i < me->array.n_array; ++i){
		int x = me->array.coordinates[i].x;
		int y = me->array.coordinates[i].y;
		if( x < image->n_cols && y < image->n_rows){
			image_write(image, x, y, HIGH);
		}
	}

	return true;
}


