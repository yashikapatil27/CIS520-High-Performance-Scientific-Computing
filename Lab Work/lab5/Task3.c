#include <stdio.h>


// Function to calculate the matrix-vector dot product A · x and print the residual

void residual(double b[2], double x[2], double A[2][2]);


int main() {

    // Declare vectors and matrices

    double x[2], x1[2], x2[2], b[2];
    double A[2][2] = {{0.7073725, 0.5204556}, {0.8158208, 0.6002474}};

    // Set values for x, x1, x2, and b

    x[0] = 1.0;
    x[1] = -1.0;
    
    // Set arrays x1, x2, b

    x1[0] = 0.9999999;

    x1[1] = -1.0000001;

    x2[0] = 0.4073666;

    x2[1] = -0.1945277;

    b[0] = 0.1869169;

    b[1] = 0.2155734;


    // Calculate and print the residuals for x, x1, and x2

    printf("Residual for x:\n");
    residual(b, x, A);
    printf("\nResidual for x1:\n");
    residual(b, x1, A);
    printf("\nResidual for x2:\n");
    residual(b, x2, A);

    return 0;

}

// Function to calculate the matrix-vector dot product A · x and print the residual

void residual(double b[2], double x[2], double A[2][2]) {

    // Matrix-vector dot product

    double AX[2] = {0};

    // Calculate AX = A · x
    for (int i = 0; i < 2; i++) {

        for (int j = 0; j < 2; j++) {

            AX[i] += A[i][j] * x[j];

        }
    }

    // Print the residual

    for (int i = 0; i < 2; i++) {

        printf("residual [ %i ] = %1.10e\n", i, b[i] - AX[i]);
    }
}


