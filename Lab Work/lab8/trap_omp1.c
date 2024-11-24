#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<omp.h>

int main(int argc, char **argv) {
    omp_set_num_threads(4);

    int N = atoi(argv[1]);
    double dx = 2.0 / (N - 1);
    double integral = 0.0;
    double x = -1.0;
    double f = 1.0 / (1.0 + x * x);
    integral = integral + 0.5 * dx * f;
    x = 1.0;
    f = 1.0 / (1.0 + x * x);
    integral = integral + 0.5 * dx * f;

    #pragma omp parallel for private(x, f) 
    for (int i = 1; i < N - 1; ++i) {
        x = -1. + dx * i;
        f = 1.0 / (1.0 + x * x);
        //#pragma omp atomic
        #pragma omp critical
        integral = integral + dx * f;
        //printf("thread %i, x = %f, f = %f\n", omp_get_thread_num(), x, f);
    }

    const double pi = 3.141592653589793;
    double absolute_error = fabs(integral - pi / 2.0);
    printf("%i %1.2e\n", N, absolute_error);
    return 0;
}
