#include<omp.h>
#include<stdio.h>

int main()
{
    int NumThreads = 10;
    //omp_set_num_threads(NumThreads);

    #pragma omp parallel
    {
        printf("Hello world from thread %d\n", omp_get_thread_num());
    }
    return 0;
}