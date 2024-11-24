#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <omp.h>
 
double function(double *x, int dim);
 
int main(int argc, char **argv)
{
    fun();
 
  return 0;
}

void fun()
{
    double x[10]={0};
    double val=function(x,10);
    printf("Rosenbrock function: %f\n",val);
} 

double function(double *x, int dim)
{
  double f = 0.0;
  for(int i=0; i<dim-1; i++)
  {
    f += (-1*((pow(1-x[i],2) + 100*(pow(x[i+1]- pow(x[i],2),2)))));
  }
  return exp(f);
}
