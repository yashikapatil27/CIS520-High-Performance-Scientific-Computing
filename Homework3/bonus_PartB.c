#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <omp.h>

double function(double x[], int dim);
double sampleInterval(double, double);

int main(int argc, char **argv) {
    double startTime = omp_get_wtime();
    unsigned long long N = atoll(argv[1]);
    clock_t start_time = clock();
    double a = -1.0;
    double b = 1.0;
    const int dimension = atoll(argv[2]);
    double x[dimension];
    double V = 1024;
    double sum = 0.0;
    srand(time(NULL));
    unsigned long long i;
    int Num=pow(4,N);
    const int cores=atoll(argv[3]);
    omp_set_num_threads(cores);
    double sumi =0.0; 
    double actual_error=0.0;
    double estimated_error=0.0;
    double theoretical_error=0.0;
    double integral=0.0;
    double intg=0.0;

    for (i = 1; i <= Num; i++) 
    {

        for (int j = 0; j < dimension; j++) 
        {
            x[j] = sampleInterval(a, b);
        }

        double func_value = function(x, dimension);

        sum = sum + func_value;


       
        // Check if i is a multiple of 4^k+1 and output the values
        for(int k=1;k<=N;k++)
        {
            if(i == pow(4,k))
            {
                integral = (V / (i)) * (sumi + sum);
                actual_error=fabs(integral-pow(2,10));
                estimated_error=fabs(integral-intg);
                theoretical_error= pow(4,-1*(k/2));
                intg = integral;
                printf("%llu %f %f %f %f %f\n", i, integral, actual_error, estimated_error, theoretical_error, V);
                sumi+=sum;
                sum = 0;
            }
        }
        
    }

    
    double time = ((double)clock() - start_time) / CLOCKS_PER_SEC;
    double endTime = omp_get_wtime();
    //printf("N=%d  integral=%f volumn=%f,time=%e\n",Num,integral,V,endTime-startTime);
  //printf("Execution time:%f seconds\n",endTime-startTime);

    return 0;
}

double function(double x[], int dim) {
    double sum = 1.0;
    for (int i = 0; i < dim; i++) {
        sum = sum + x[i];
    }
    return sum;
}

double sampleInterval(double a, double b) {
    double x = ((double)(rand() / (double)RAND_MAX) * (b - a)) + a;
    return x;
}
