/*
 *  numdif.c
 *  Numerical Differential Eqautions Library
 * 
 *  Alex Hernandez
 *
 */
#include <stdio.h>
#include "numdif.h"

// cdf_3dF2d(double x_k, double y_k, double x_step, double (*F)(double, double)){
	double diff;
	diff = F(x_k + x_step, y_k) - F(x_k - x_step, y_k);
	return (diff / ( 2.0 * x_step));

}


// Huen's Method for ODEs that return a double
double heuns_3dF2d(double x_k, double y_k, double x_step, double (*differential)(double, doubel)){
	
	double k1, k2, half_step;

	half_step = x_step / 2.0;
	k1 = differential(x_k, y_k);
	k2 = differential(x_k + x_step, y_k + (x_step * k1));

	return ( y_k + half_step * (k1+k2) );	
	
}


// Runge-Kutta for ODEs that return a double
double rk_3dF2d(double x_k, double y_k, double x_step, double (*differential)(double,double) ){
	
	double k1, k2, k3, k4, half_step;
	
	half_step = x_step / 2.0;
	k1 = (*differential)(x_k, y_k);
	k2 = (*differential)( x_k + half_step, y_k + half_step * k1 );
	k3 = (*differential)( x_k + half_step, y_k + half_step * k2 );
	k4 = (*differential)( x_k + x_step, y_k + x_step * k3 ); 

	return(  y_k + (x_step / 6.0)*(k1 + (2*k2) + (2*k3) + k4) );
}

/***************************************************************
	A PROPERLY SETUP DIFFERENTIAL

where f(x,y(x)) only depends on y(x) such as y' = -ky
double f(double x, double y){
	// basically don't use x
	double k = -1.0;

	return (k * y);
}

where f(x,y(x)) only depends on y(x) such as y' = -kx
double f(double x, double y) {
	// basically ignore y
	double k = -1.0;

	return (k * x);
}

where f(x,y(x)) depends on both x and y(x) such as y' = -kxy
double f(double x, double y) {
	k = -1.0

	return (k * x * y);
}

****************************************************************/
/*
// Variable argument runge-kutta
void rk_vo(size_t vec_size, double * initial_conditions, double (* differential)(double, double), double * next_conditions){

 	int i,k1,k2,k3,k4;

	for(i = 0; i < vec_size; i++){
		k1 = differential( initial_conditions[0], 
		k2 =
		k3 = 
		k4 = 
	
		next_condition[i] = 
}
*/










