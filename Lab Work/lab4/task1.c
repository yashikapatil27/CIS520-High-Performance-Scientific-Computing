#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char **argv)
{
	int N = atoi(argv[1]);
	printf("i = %i \n", N);

	double dx = 2.0/ (N-1);
	for (int i=0; i<N; ++i)
	{
		double x = -1 + dx*i;
		printf("x = %e \n", x);
	}
	return 0;
}
