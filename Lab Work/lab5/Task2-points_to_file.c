#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(int argc, char **argv)
{
	srand(time(NULL));
	int N = atoi( argv[1] );
	
	FILE *file = fopen("file.txt", "w");
	for (int i=0; i<N; ++i)
	{
		int rand_int = rand();
		double x = (double)rand()/RAND_MAX;
		fprintf(file,"%lf \n", x);
	}

	fclose(file);

	return 0;

}

