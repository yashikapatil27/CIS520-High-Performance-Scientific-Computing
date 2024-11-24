#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<mpi.h>

void sample_rand(const double a, const double b ,const int dim, double *x) 
{
    for(int i=0;i<dim;++i) 
    {
        double tmp = ((double) rand())/((double) RAND_MAX);
        x[i] = (b-a)*tmp + a;
    }
}

double f(double *x) 
{
    double x1 = x[0];
    double x2 = x[1];
    return exp(-(1.-x1)*(1.-x1) - 100.*(x2-x1*x1)*(x2-x1*x1));
}

int main( int argc, char **argv)
{
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    long N = atol(argv[1]);
    srand(time(NULL) * rank);

    const int dim=2;
    double x[dim];

    double max = -1;
    for(long int i =1; i<=N; ++i)
    {
        sample_rand(-1., 1., dim, x);
        double f_i = f(x);
        if (f_i>max)
        {
            max = f_i;
        }
        //printf("Process %d: sample number %ls of %ld, f_i = %e\n", rank, i, N, f_i);
    }
    printf("Process %d of %d local max = %1.3e\n", rank, size, max);

    double send_number = 9.0;
    double rec_number;
    MPI_Status status;

    double process_local_max = max;// this is the maximum found by the process
    double process_global_max=-100; // processor 0 will hold the global maximum
    MPI_Reduce(&process_local_max,&process_global_max,1,MPI_DOUBLE,MPI_MAX,0,MPI_COMM_WORLD);
    printf("Process ID %i, x = %f, max x = %f\n",rank, process_local_max, process_global_max);
    
    /////////////////// RING PASSING
    // if (rank==0)
    // {
    //     send_number=max;
    //     printf("Number decided to send: %1.3e\n", send_number);
    //     MPI_Send(&send_number, 1, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD);
    //     MPI_Recv(&rec_number, 1, MPI_DOUBLE, size-1, 0, MPI_COMM_WORLD, &status);
    // }
    // else if(rank==size-1)
    // {
    //     MPI_Recv(&rec_number, 1, MPI_DOUBLE, rank-1, 0, MPI_COMM_WORLD, &status);
        
    //     if(rec_number<max)
    //     {
    //         send_number = max;
    //     }
    //     else
    //     {
    //         send_number = rec_number;
    //     }
    //     printf("Number decided to send: %1.3e\n", send_number);
    //     MPI_Send(&send_number, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    // }
    // else
    // {
    //     MPI_Recv(&rec_number, 1, MPI_DOUBLE, rank-1, 0, MPI_COMM_WORLD, &status);

    //     if(rec_number>max)
    //     {
    //         send_number = rec_number;
    //     }
    //     else
    //     {
    //         send_number = max;
    //     }
    //     printf("Number decided to send: %1.3e\n", send_number);

    //     MPI_Send(&send_number, 1, MPI_DOUBLE, rank+1, 0, MPI_COMM_WORLD);
    // }

    printf("Process %i send %1.3e and recieved %1.3e\n", rank, send_number, rec_number);

    MPI_Finalize();

    if(rank==0)
    {
        printf("Global maximum: %1.3e\n", process_global_max);
    }
    return 0;
}