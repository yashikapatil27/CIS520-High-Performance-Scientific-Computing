#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char **argv)
{
	srand(time(NULL));

	int N = atoi(argv[1]);
	for (int i=0; i<N; ++i)
	{
		int rand_int = rand();
		double x = (double)rand()/RAND_MAX;
		printf("%lf\n", x);
	}
	return 0;
}
