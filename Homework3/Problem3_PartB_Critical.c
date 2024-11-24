#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <omp.h>
 
double function(double *x, int dim);
 
int main(int argc, char **argv)
{
  unsigned int seed = time(NULL);
  double startTime = omp_get_wtime();
  unsigned long long N = atoll(argv[1]);
  double a = -1.0;
  double b = 1.0;
  int dimension=atoll(argv[2]);
  double x[10] = {0};
  double V=1024;
  unsigned long long i;
  int cores=atoll(argv[3]);
  double integral=0.0;
  double f =0.0;
 
  #pragma omp parallel for private(x,f)
  for (i=0;i<N;++i)
  {
    for (int j=1;j<10;j++)
    {
      x[j]= ((double)(rand_r(&seed)/(double)RAND_MAX)*(b-a))+a;
            
    }
    f = function(x, dimension);
    #pragma omp critical
    integral += f;
  }

  double integral1 = (V/N) * integral;
  double endTime = omp_get_wtime();
  printf("%llu %f %f\n",N,integral1,endTime-startTime);
 
  return 0;
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
