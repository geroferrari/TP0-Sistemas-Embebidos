#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "image.h"



bool image_ctor(image_t *me, uint32_t n_rows, uint32_t n_cols){

	me->n_rows = n_rows; // guardo en los atributos el numero de filas y columnas
	me->n_cols = n_cols;

	// genero memoria para los datos de la imagen. creo para las columnas
	if ( !(me->data = (img_data_t **)malloc(sizeof(img_data_t *)*n_cols)) ){
		return false;
	}

	//genero memoria para las filas, mientras recorro las columnas.
	for(uint32_t i=0; i<n_cols; i++){
		if ( !(me->data[i] = (img_data_t *)malloc(sizeof(img_data_t)*n_rows)) ){
			return false;
		}
		for(uint32_t j=0; j<n_rows; j++){ //escribo la imagen en el espacio creado.
			image_write(me, i, j, LOW);
		}
	}

	return true;
}


void image_dtor(image_t *me){

	uint32_t n_cols = me->n_cols; //guardo en una variable local, la cantidad de columnas
	
	// libero memoria de las filas
	for(uint32_t i=0; i<me->n_cols; i++){
		free(me->data[i]);
	}

	free(me->data);
}


void image_write(image_t *me, uint32_t i, uint32_t j, img_data_t value){
	me->data[i][j] = value;
}	


img_data_t image_read(image_t *me, uint32_t i, uint32_t j){
	return me->data[i][j];
}


void image_to_file(image_t *me, const char *filename){

	uint32_t n_cols, n_rows;
	FILE *filename_ptr;

	n_rows = me->n_rows;
	n_cols = me->n_cols;

	filename_ptr = fopen(filename, "w+");

	fprintf(filename_ptr, "P1\n%d %d\n", n_cols, n_rows);
	for(uint32_t i=0; i<n_cols; i++){
		for(uint32_t j=0; j<n_rows; j++){
			fprintf(filename_ptr, "%d ", image_read(me, i, j) );
		}
		fprintf(filename_ptr, "\n");
	}

	fclose(filename_ptr);

}
