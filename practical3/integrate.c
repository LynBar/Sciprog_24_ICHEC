
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void){
	//initialise variables	
	int N;				// Number of steps				
	float sum,start,stop,step;

	N=100;				//Number of steps
	start=0;			//start point
	stop=M_PI/3.0;			//stop point
       	step = (stop - start)/(N);	//step size
//func(float  x) = (float) tan((double) x);

	sum = tan(start)+tan(stop);		//adding the end point values first
	for (int i=1; i<N; i++){
		sum=sum + 2.0*tan(start+step*i);//adding the values in the interval
	}
	sum = sum*step/2.0;		//Multiplying by overall factor b-a/2N
	printf("Num of steps: %d \n Step size is %.4f \n", N, step);
	printf("The integral is approximately %.4f, and exactly %.4f. \n", sum, log(2.0));
}


