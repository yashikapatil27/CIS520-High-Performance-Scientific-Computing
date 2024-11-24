#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
        printf("x passed to program = %s \n", argv[1]);
        double x = strtod(argv[1], NULL);

        printf("x = %f \n",x);
        
	
	if(x<2)
        {
                printf("Low CPU Usage! \n");
        }
        else if(x>10)
        {
                printf("High CPU Usage! \n");

        }
        else
        {
                printf("Moderate CPU Usage! \n");
        }
        return 0;
	
}

