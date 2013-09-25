/*
 * 	rundif.c
 *
 * RUN DIF
 *	Runs the NUM DIF library on the differential equation of y' = -2xy^2 with y(0) = 1
 *      and is compared to the exact solution.
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

	double i, x_start, x_end, old_rky, x_step, next_y;

	if( argc != 2 + 1) {
		printf("Usage: ./rundif x_step x_end\n");
		exit(-1);
	}

	old_rky = 1.0;
	x_start = 0.0;
	sscanf(argv[1], "%lf", &x_step );
	sscanf(argv[2], "%lf", &x_end );

	for( i= x_start; i < x_end + x_step; i+= x_step  ){		
		printf("%f %f %f\n", i, old_rky, baseline_rk(i));
		old_rky = rk_3dF2d( i, old_rky, x_step, test_rk );
	}

	exit(0);
} 
	 
