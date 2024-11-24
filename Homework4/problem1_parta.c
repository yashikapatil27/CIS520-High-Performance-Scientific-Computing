#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>
#include "secret_function.h"

int main(int argc, char **argv)
{
    int rank, size;
    MPI_Init (&argc, &argv); 
    MPI_Comm_rank (MPI_COMM_WORLD, &rank); 
    MPI_Comm_size (MPI_COMM_WORLD, &size); 
    long N = atol(argv[1]);
    double max = -1;

    for (long int i = 1; i <= N; ++i)
    {
        double test = secret_function(100.0,100.0);
        if (max < test)
        {
            max = test;
        }
    }
    printf("secret_function(100.0,100.0) = %lf\n",max);
    return 0;
}
