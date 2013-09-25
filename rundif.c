/*
 * 	rundif.c
 *
 * RUN DIF
 *	Runs the NUM DIF library
 *
 * By Alex Hernandez
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "numdif.h"

double test_rk(double x, double y) {
	// printf("Inside test_rk: x=%f y=%f\n",x,y);
	return (-2.0 * x * y * y);
}

double baseline_rk(double t) {

	return ( 1 / (1 + (t*t)) );
} 


int main(int argc, char * argv[]){

	double i, x_start, x_end, old_y, x_step, next_y;

	if( argc != 3 + 1) {
		printf("Usage: ./rundif y_at_start x_start x_step x_end");
		exit(-1);
	}

	sscanf(argv[1], "%lf", &old_y );
	sscanf(argv[2], "%lf", &x_start );
	sscanf(argv[3], "%lf", &x_step );
	sscanf(argv[4], "%lf", &x_end );

	for( i= x_start; i < x_end + x_step; i+= x_step  ){		
		next_y = rk_2d( i, old_y, x_step, test_rk );
		printf("%f %f %f\n", i, next_y, baseline_rk(i));
		old_y = next_y;
	}

	exit(0);
} 
	 
