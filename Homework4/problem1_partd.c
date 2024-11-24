#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>
#include "secret_function.h"
#include <omp.h>

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
    ////////// TIMER 1
    double startTime = omp_get_wtime();
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
        
        //printf("Process %d: sample number %ls of %ld, f_i = %e\n", rank, i, N, f_i);
        MPI_Barrier(MPI_COMM_WORLD);
        printf("Process %d: sample number %ld of %ld, f_i = %e\n", rank, i, N, f_i);

    }

    double process_local_min = min;
    double process_global_min = 10000;

    ///////// TIMER 2
    double startTime1 = omp_get_wtime();
    MPI_Reduce(&process_local_min, &process_global_min, 1, MPI_DOUBLE, MPI_MIN, 0, MPI_COMM_WORLD);
    double endTime1 = omp_get_wtime();
    

    MPI_Barrier(MPI_COMM_WORLD);
    printf("Process ID %i, x = %f, min x = %f\n", rank, process_local_min, process_global_min);
    
    MPI_Finalize();

    if(rank==0)
    {
        printf("Global minimum: %1.3e\n", process_global_min);
        double endTime = omp_get_wtime();
        printf("Reduction Time: %f\n", endTime1-startTime1);
        printf("Total Time: %f\n", endTime-startTime);
    }

    
    return 0;
}
