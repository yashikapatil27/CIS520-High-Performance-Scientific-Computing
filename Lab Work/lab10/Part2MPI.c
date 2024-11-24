
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <mpi.h>

void sample_rand(const double a, const double b, const int dim, double *x);
double f(double *x);
int main(int argc, char **argv)
{
    int rank, size;
    MPI_Init (&argc, &argv); // initializes MPI
    MPI_Comm_rank (MPI_COMM_WORLD, &rank); // get current MPI-process ID. O, 1, ...
    MPI_Comm_size (MPI_COMM_WORLD, &size); // get the total number of processes
 

    long N = atol(argv[1]);
    srand(time(NULL) * rank); // each MPI process gets a unique seed
    const int dim = 2; // dimension of function to optimize (x1,x2)
    double x[dim];     // array of random numbers
    // search for the function's maximum
    double max = -1;
    for (long int i = 1; i <= N; ++i)
    {
        sample_rand(-1.0, 1.0, dim, x);
        double f_i = f(x);
        // printf("Process %d : sample number %ld of %ld, f_i = %le \n",rank,i, N, f_i);
        if (f_i > max)
        {
            max = f_i;
        }
    }
    printf("Process %d of local max = %1.5e\n",rank, max);

    
    double send_number = 9.0; // THIS NUMBER WILL NEED TO BE CHANGED
    double rec_number;
    MPI_Status status;
   
    double process_local_max = max;// this is the maximum found by the process
    double process_global_max=-100; // processor 0 will hold the global maximum
    MPI_Reduce(&process_local_max,&process_global_max,1,MPI_DOUBLE,MPI_MAX,0,MPI_COMM_WORLD);
    printf("Process ID %i, x = %f, max x = %f\n",rank, process_local_max, process_global_max);
    printf("Process %i send %1.3e and recieved %1.3e\n", rank, send_number, rec_number);

    MPI_Finalize(); // programs should always perform a "graceful" shutdown
    if(rank==0)
    {
        printf("Final global Max value taken over all the processes: %1.3e\n",process_global_max);
    }
    return 0;
}
// will sample any dim-dimensional box of size [a,b]^dim
// the random point is stored in the array x
void sample_rand(const double a, const double b, const int dim, double *x)
{
    for (int i = 0; i < dim; ++i)
    {
        double tmp = ((double)rand()) / ((double)RAND_MAX);
        x[i] = (b - a) * tmp + a;
    }
}
// pass array x, and unpack its elements inside the function
// NOTE: this is a way to pass an array of arbitrary size into a function
double f(double *x)
{
    double x1 = x[0];
    double x2 = x[1];
    return exp(-(1. - x1) * (1. - x1) - 100. * (x2 - x1 * x1) * (x2 - x1 * x1));
}
