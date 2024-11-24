#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>
#include "secret_function.h"


void sample_rand(const double a, const double b ,const int dim, double *x) 
{
    for(int i=0;i<dim;++i) 
    {
        double tmp = ((double) rand())/((double) RAND_MAX);
        x[i] = (b-a)*tmp + a;
    }
}

int main(int argc, char **argv)
{
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    long N = atol(argv[1]);
    srand(time(NULL) * rank);
    
    const int dim=2;
    double x[dim];

    double min=10000;
    for(long int i =1; i<=N; ++i)
    {
        sample_rand(-512., 512., dim, x);
        
        double f_i = secret_function(x[0], x[1]);
        if (f_i<min)
        {
            min = f_i;
        }
        MPI_Barrier(MPI_COMM_WORLD);
        printf("Process %d: sample number %ld of %ld, f_i = %e\n",rank, i, N, f_i);

    }
    

    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize();
    printf("Process %d of %d min = %1.3e\n", rank, size, min);
    return 0;
}
