#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    for (int k = 2; k <= 10; k++) {
        int N = 1;
        const float pi = 3.14159265358979323846;

        for (int i = 0; i < k; i++) {
            N *= 10;
        }

        srand((unsigned int)time(NULL));

        double count = 0;

        for (int i = 0; i < N; i++) {
            double x1 = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
            double x2 = ((double)rand() / RAND_MAX) * 2.0 - 1.0;

            if (x1 * x1 + x2 * x2 <= 1.0) {
                count++;
            }
        }

        double result = 4.0 * (double)count / N;
        double abs_error = fabs(pi - result);

        printf("%d %i %f %f\n", k, N, result, abs_error);
    }

    return 0;
}
