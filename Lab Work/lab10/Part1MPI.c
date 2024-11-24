
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
    // This next if-statement implements the ring topology
    // the last process ID is size-1, so the ring topology is: 0->1, 1->2, ... size-1->0
    // rank 0 starts the chain of events by passing to rank 1
    if (rank == 0)
    {
        // only the process with rank ID = 0 will be in this block of code.
        // send data to process 1
        send_number=max;
        printf("Number decided to send: %1.3e\n",send_number);
        MPI_Send(&send_number, 1, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD);
        // receive data from process size-1
        MPI_Recv(&rec_number, 1, MPI_DOUBLE, size - 1, 0, MPI_COMM_WORLD, &status);
    }
    else if (rank == size - 1)
    {
        // receive data from process rank-1 (it "left" neighbor")
        MPI_Recv(&rec_number, 1, MPI_DOUBLE, rank - 1, 0, MPI_COMM_WORLD, &status);
        if(rec_number>max)
        {
            send_number = rec_number;
        }
        else
        {
            send_number=max;
        }
        printf("Number decided to send: %1.3e\n",send_number);
        // send data to its "right neighbor", rank 0
        MPI_Send(&send_number, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    }
    else
    {
        // receive data from process rank-1 (it "left" neighbor")
        MPI_Recv(&rec_number, 1, MPI_DOUBLE, rank - 1 , 0, MPI_COMM_WORLD, &status);
        
        if(rec_number>max)
        {
            send_number = rec_number;
        }
        else
        {
            send_number=max;
        }
        
        printf("Number decided to send: %1.3e\n",send_number);
    
        // send data to its "right neighbor" (rank+1)
        MPI_Send(&send_number, 1, MPI_DOUBLE, rank + 1, 0, MPI_COMM_WORLD);
    }
    
    printf("Process %i send %1.3e and recieved %1.3e\n", rank, send_number, rec_number);
    MPI_Finalize(); // programs should always perform a "graceful" shutdown
    
    if(rank==0)
    {
        printf("Final global Max value taken over all the processes: %1.3e\n",rec_number);
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
