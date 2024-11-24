#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> // Include the math header

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

int main(int argc, char **argv)
{
    int N = atoi(argv[1]);
    srand(time(NULL));

    double sum = 0;
	double V = 2.0;
	double dx = 2.0/ (double)(N);
	double func_value = 0;
	double integral = 0;
    

    for (int i = 0; i < N; i++)
    {
        double xi = (((double)rand() / (double)RAND_MAX) * 2) - 1;
        double func_value = 1 / (1 + (xi * xi));
        sum = sum + func_value;
        // printf("Iteration %d: xi = %f func_value = %f sum = %f\n", i, xi, func_value, sum);
    }
    
	double true_integral = M_PI / 2.0;
	integral = sum * (V/N);

    double absolute_error = fabs(true_integral - integral);
    printf("%d %f\n", N, absolute_error);

	return 0;
}
