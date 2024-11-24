#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

double snowfall(double S) {
    if (S >= 0 && S <= 10) {
        return exp(-fabs(S - 2) * fabs(S - 2) / 2) / 2.4496028273129427;
    } else {
        return 0.0;
    }
}

int main() {
    srand(time(NULL));
    double sum = 0;
    int N = 100;

    for (int i = 0; i < N; i++) {
        double S = ((double)rand() / (double)RAND_MAX) * 10; 
        double func_value = snowfall(S);
        sum += S*func_value;
    }

    int V = 10;
    double integral = (sum / N) * V;
    double expected_average_snowfall = integral;

    printf("Expected Average Snowfall: %f\n", expected_average_snowfall);

    return 0;
}
