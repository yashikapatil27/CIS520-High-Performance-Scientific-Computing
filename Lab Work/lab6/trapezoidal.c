// compute 
//
//           \int_{-1}^1 1 / (1+x^2) dx
//
// with the extended trapezoidal rule
//
//
#include <stdio.h>
#include <stdlib.h> // needed to use the function atoi
#include <math.h>


// this main program shows how to code the trapezoidal rule
// using if statements inside of the for loop
/*
int main(int argc, char **argv) {

  int N = atoi( argv[1] ); // convert command-line input to N = number of points
  //printf("N = %i\n",N);
  double dx = 2./(N-1); // \delta x spacing when interval is [-1,1]
  double integral = 0.0;

  for (int i=0;i<N;++i) {
    double x = -1. + dx*i; // compute x_i
    double f = 1. / (1. + x*x);  // compute f_i = f(x_i)

    // easy to code, but its generally better to aviod if statements
    // inside of a for-loop (slows down the code) 
    if(i==0 || i == N-1) { // end points of trapezoidal rule treated specially
      integral = integral + 0.5*dx*f; // or integral += 0.5*dx*f;
    } else {
      integral = integral + dx*f;
    }
    //integral += dx*f; // sneaky bug: will give first-order convergence

  }

  const double pi = 3.141592653589793;
  double absolute_error = fabs(integral - pi / 2.);
  //printf("%i %1.16lf\n",N, integral);
  printf("%i %1.2e\n",N,absolute_error);
  return 0;
}
*/

// this main program shows how to code the trapezoidal rule
// without using if statements inside of the for loop. In this case
// the special boundary points (x=-1,1) are treated differently
// from the other points
int main(int argc, char **argv) {

  int N = atoi( argv[1] ); // convert command-line input to N = number of points
  //printf("N = %i\n",N);
  double dx = 2./(N-1); // \delta x spacing when interval is [-1,1]
  double integral = 0.0;

  // add in contribution at x=-1
  double x = -1.0;
  double f = 1. / (1. + x*x);
  integral = integral + 0.5*dx*f;

  // add in contribution at x=1
  x = 1.0;
  f = 1. / (1. + x*x);
  integral = integral + 0.5*dx*f;  

  for (int i=1;i<N-1;++i) {
    x = -1. + dx*i; // compute x_i
    f = 1. / (1. + x*x);  // compute f_i = f(x_i)

    integral = integral + dx*f;

  }

  const double pi = 3.141592653589793;
  double absolute_error = fabs(integral - pi / 2.);
  //printf("%i %1.16lf\n",N, integral);
  printf("%i %1.2e\n",N,absolute_error);
  return 0;
}