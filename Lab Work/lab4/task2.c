#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char **argv)
{
	int N = atoi(argv[1]);
	double dx = 2.0/(N-1);
	double integral = 0.0;

	for (int i=0; i<N; ++i)
	{
		double x_i = -1 + dx*i;
		double fi = 1/(1+ (x_i*x_i));

		if (i==0 || i==N-1)
		{
			integral = integral + (fi*dx)/2.0;
		}
		else
		{
			integral = integral + fi*dx;
		}
	}

	const double pi = 3.141592653589793;
	double absolute_error = fabs(integral - pi/2.);
	printf("%d %e \n", N, absolute_error);
	//printf("integral: %f`", integral);

}
