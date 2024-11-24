#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <omp.h>
 
double function(double *x, int dim);
 
double variable(double , double, unsigned int *);
 
int main(int argc, char **argv)
{
  double startTime = omp_get_wtime();
  int cores = atoi(argv[3]);
  srand(time(NULL));
  omp_set_num_threads(cores);
  unsigned long long N = atoll(argv[1]);
  clock_t start_time = clock();
  double a = -1.0;
  double b = 1.0;
  int dimension=atoll(argv[2]);
  double x[10];
  double V=1024;
  double sum_thread[4] = {0};
  double func_value=0.0;
  double sum1 = 0.0;
  double integral=0.0;
  double f =0.0;
 
  #pragma omp parallel private(x,f)
  {
    unsigned int seed = cores + 1;
    #pragma omp for reduction(+:integral)
    for (long long int i = 0;i<N;++i)
    {
      for (int j=0;j<10;j++)
      {
            //x[j]= ((double)(rand_r(&seed)/(double)RAND_MAX)*(b-a))+a;
            x[j]=variable(a,b,&seed);
      }

      f = function(x, dimension);
      integral += f;
    }
  }
     
  double integral1 = (V/N) * integral;
 
  double time = ((double)clock() - start_time)/CLOCKS_PER_SEC;

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
 
double variable(double a, double b, unsigned int *seed)
{
  double x;
  x = ((double)(rand_r(seed)/(double)RAND_MAX)*(b-a))+a;
  return x;
 
}