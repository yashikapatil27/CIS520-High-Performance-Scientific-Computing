#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double PartA(int N) {
    double count=0;
    for (int i = 0; i < N; i++) 
    {
        double x1 = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
        double x2 = ((double)rand() / RAND_MAX) * 2.0 - 1.0;

        if (x1 * x1 + x2 * x2 <= 1.0)
        {
            count++;
        }
    }

    double result = 4.0 * (double)count / N;
    
    return result;
}

int main(int argc, char *argv[]) {

    const float pi = 3.14159265358979323846;

    int N = atoi(argv[1]);

    double pi_approx = PartA(N);
    double abs_error = fabs(pi - pi_approx);

    printf("%d %e", N, abs_error);

    return 0;
}
