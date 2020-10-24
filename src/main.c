#include <stdio.h>
#include "image.h"
#include "line.h"
#include "rectangle.h"


#define MAX_IMG_NAME	20

#define N_ROWS			200 	// Cantidad de filas
#define N_COLS			200		// Cantidad de columnas


/* Ejemplo de uso de las funciones de la clase "imagen" */

int main(void){
	

	image_t img;
	int img_count=0;
	char img_name[MAX_IMG_NAME];

	line_t line1;
	line_t line2;
	line_t line3;
	line_t line4;
	line_t line5;
	line_t line6;
	line_t line7;
	line_t line8;

	rectangle_t rect1;
	rectangle_t rect2;
	rectangle_t rect3;
	rectangle_t rect4;

	double angle1 = 0;
	double angle2 = 45;
	double angle3 = 90;
	double angle4 = 135;
	double angle5 = 180;
	double angle6 = 235;
	double angle7 = 270;
	double angle8 = 315;


	for(int i=0; i<90; i++){

		line_ctor(&line1,85,85,140,100);
		line_ctor(&line2,85,85,140,100);
		line_ctor(&line3,85,85,140,100);
		line_ctor(&line4,85,85,140,100);
		line_ctor(&line5,85,85,140,100);
		line_ctor(&line6,85,85,140,100);
		line_ctor(&line7,85,85,140,100);
		line_ctor(&line8,85,85,140,100);

		rectangle_ctor(&rect1,10,10,10,10);
		rectangle_ctor(&rect2,25,175,10,10);
		rectangle_ctor(&rect3,175,25,10,10);
		rectangle_ctor(&rect4,170,170,10,10);

		image_ctor(&img,N_ROWS,N_COLS);

		if((i%2) == 0 ){
			line_scale(&line1,0.5);
			line_scale(&line2,2);
			line_scale(&line3,0.5);
			line_scale(&line4,2);
			line_scale(&line5,0.5);
			line_scale(&line6,2);
			line_scale(&line7,0.5);
			line_scale(&line8,2);
			rectangle_scale(&rect1,0.5);
			rectangle_scale(&rect4,0.5);

		} else {
			line_scale(&line1,2);
			line_scale(&line2,0.5);
			line_scale(&line3,2);
			line_scale(&line4,0.5);
			line_scale(&line5,2);
			line_scale(&line6,0.5);
			line_scale(&line7,2);
			line_scale(&line8,0.5);
			rectangle_scale(&rect1,2);
			rectangle_scale(&rect4,2);
		}

		line_rotate(&line1, angle1);
		line_rotate(&line2, angle2);
		line_rotate(&line3, angle3);
		line_rotate(&line4, angle4);
		line_rotate(&line5, angle5);
		line_rotate(&line6, angle6);
		line_rotate(&line7, angle7);
		line_rotate(&line8, angle8);
		rectangle_rotate(&rect2, angle8);
		rectangle_rotate(&rect3, angle8);


		shape_plot(&line1.super, &img);
		shape_plot(&line2.super, &img);
		shape_plot(&line3.super, &img);
		shape_plot(&line4.super, &img);
		shape_plot(&line5.super, &img);
		shape_plot(&line6.super, &img);
		shape_plot(&line7.super, &img);
		shape_plot(&line8.super, &img);
		shape_plot(&rect1.super, &img);
		shape_plot(&rect2.super, &img);
		shape_plot(&rect3.super, &img);
		shape_plot(&rect4.super, &img);

		angle1+=3;
		angle2+=3;
		angle3+=3;
		angle4+=3;
		angle5+=3;
		angle6+=3;
		angle7+=3;
		angle8+=3;

		sprintf(img_name,"./images/img%.3d.pbm",img_count);
		image_to_file(&img,img_name);

		image_dtor(&img);
		shape_dtor((shape_t *)&line1);
		shape_dtor((shape_t *)&line2);
		shape_dtor((shape_t *)&line3);
		shape_dtor((shape_t *)&line4);
		shape_dtor((shape_t *)&line5);
		shape_dtor((shape_t *)&line6);
		shape_dtor((shape_t *)&line7);
		shape_dtor((shape_t *)&line8);
		shape_dtor((shape_t *)&rect1);
		shape_dtor((shape_t *)&rect2);
		shape_dtor((shape_t *)&rect3);
		shape_dtor((shape_t *)&rect4);

		++img_count;
	}


	return 0;
	}

