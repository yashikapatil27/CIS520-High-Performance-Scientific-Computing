#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
#include <math.h>
#include <omp.h>


double function(double x[], int dim);

double sampleInterval(double , double );

int main(int argc, char **argv)
{
  double startTime = omp_get_wtime();
  unsigned long long N = atoll(argv[1]);

  double a = -1.0;
  double b = 1.0;

  const int dimension=atoll(argv[2]);
  double x[dimension];
  double V=1024;
  double sum = 0.0;
  srand(time(NULL));
  unsigned long long i;

  for (i=0;i<N;++i)
  {
    for (int j=0;j<dimension;j++)
    {
      x[j] = sampleInterval(a,b);
    }

    double func_value  = function(x,dimension);
    
    sum = sum + func_value;
    
  }
  
  double integral =  (V/N) * sum;
  double endTime = omp_get_wtime();
  printf("%llu %f %f %f\n",N,integral,V,endTime-startTime);

  return 0;
}

double function(double x[], int dim) 
{
  double sum = 1.0;
  for (int i=0;i<dim;i++)
  {
    sum = sum + x[i];
  }
  return sum;
}


double sampleInterval(double a, double b) 
{
  double x = ((double)(rand()/(double)RAND_MAX)*(b-a))+a;
  return x;
}
