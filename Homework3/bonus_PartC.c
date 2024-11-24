#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <omp.h>
 
double function(double x[], int dim);
double variable(double a, double b, unsigned int *seed);
 
int main(int argc, char **argv) {
    double startTime = omp_get_wtime();
    unsigned long long N = atoll(argv[1]);
 
    double a = -1.0;
    double b = 1.0;
   
    const int dimension = atoll(argv[2]);
    double x[dimension];
    double V = 1024;
    unsigned int seed = (unsigned int)time(NULL);
    //unsigned long long i;
    unsigned long long Num = pow(4, N);
    const int cores = atoll(argv[3]);
    omp_set_num_threads(cores);
    double sumi = 0.0;
    double integral = 0.0;
    double intg = 0.0;
    unsigned long long count = 0;
 
    #pragma omp parallel private(x ,seed) reduction(+: sumi, integral, intg)
    {
        double sum = 0.0;
 
        #pragma omp for
        for (unsigned long long i = 1; i < Num; ++i) {
            for (int j = 0; j < dimension; j++) {
                x[j] = variable(a, b, &seed);
            }
 
            double func_value = function(x, dimension);
 
            sum += func_value;
            #pragma omp critical
            for (int k = 1; k <= N; k++) {
                if (i == pow(4, k)) {
                    
                    {
                        integral = (V / (i)) * (sumi + sum);
                        double estimated_error = fabs(integral-intg); 
                        intg = integral;
                        //printf("%llu %f %f\n", i, integral, V);
                        printf("MC Points = %llu, Integral = %f, Estimated Error (for i = %llu) = %f, V = %f\n", i, integral, count, estimated_error, V);
                        count = i;
                        sumi += sum;
                        sum = 0.0; // Reset private sum for each thread
                    }
                }
            }
        }
    }
 
    double endTime = omp_get_wtime();
    return 0;
}
 
double function(double x[], int dim) {
    double sum = 1.0;
    for (int i = 0; i < dim; i++) {
        sum = sum + x[i];
    }
    return sum;
}
 
double variable(double a, double b, unsigned int *seed) {
    double x = ((double)(rand_r(seed) / (double)RAND_MAX) * (b - a)) + a;
    return x;
}