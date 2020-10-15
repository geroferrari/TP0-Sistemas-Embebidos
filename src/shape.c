#include <stdlib.h>
#include "shape.h"
#include "image.h"

bool shape_ctor(shape_t *me, coordinates_array_t *array, uint32_t position_x, uint32_t position_y){

	me->position.x = position_x;
	me->position.y = position_y;

	/* pido memoria para el array dinamico de coordenadas */
	if ((me->array.coordinates = (coordinate_t*)malloc(sizeof(coordinate_t)*array->n_array)) == NULL){
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


bool shape_rotate(shape_t *me, float angle){
	// Completar
}

float shape_distance_from(shape_t *me, shape_t *shape){
	// Completar
}

bool shape_plot(shape_t *me, image_t *image){

	for(int i = 0; i < me->array.n_array; i++){
		uint32_t x = me->array.coordinates[i].x;
		uint32_t y = me->array.coordinates[i].y;
		if( x < image->n_cols && y < image->n_rows){
			image_write(image, x, y, HIGH);
		}
	}

	return true;
}


