#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
#include <math.h>
#include <omp.h>

double function(double x[], int dim);

double sampleInterval(double , double );

int main(int argc, char **argv)
{
  unsigned int seed = (unsigned int)time(NULL);
  double startTime = omp_get_wtime();
  omp_set_num_threads(4);
  unsigned long long N = atoll(argv[1]);
  clock_t start_time = clock();
  double a = -1.0;
  double b = 1.0;
  int dimension=atoll(argv[2]);
  double x[dimension];
  double V=1024;
  unsigned long long i;
  double func_value=0.0;
  double sum1 = 0.0;
  double integral=0.0;
  #pragma omp parallel for private(x) reduction(+:integral)
  for (i=0;i<N;++i)
  {
    double x[dimension];
    double sum = 1.0;
    for (int j=0;j<dimension;j++)
    {
      x[j]= ((double)(rand_r(&seed)/(double)RAND_MAX)*(b-a))+a;
      sum = sum + x[j]; 
    }

    integral +=  sum;
  }
    
  double integral1 = (V/N) * integral;  
  double time = ((double)clock() - start_time)/CLOCKS_PER_SEC;
  double endTime = omp_get_wtime();
  
  printf("%llu %f %f %f %f %d\n",N,integral1,V,time,endTime-startTime,omp_get_max_threads());
  
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
  double x;
  x = ((double)(rand()/(double)RAND_MAX)*(b-a))+a;
  return x;
  
}
