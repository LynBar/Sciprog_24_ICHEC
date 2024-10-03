
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void){
	int N;
	float sum,start,stop,step;

	N=100;				//Number of steps
	start=0;			//start point
	stop=M_PI/3.0;			//stop point
       	step = (stop - start)/(N);	//step size
//func(float  x) = (float) tan((double) x);

	sum = tan(start)+tan(stop);		//adding boundary terms from start and finish
	for (int i=1; i<N; i++){
		sum=sum + 2.0*tan(start+step*i);//adding terms in interval at each step
	}
	sum = sum*step/2.0;			//Mulitplying by overall factor (b-a)/2N
	printf("Num of steps: %d \n Step size: %.4f \n", N, step);
	printf("The integral is approximately %.4f, and exactly %.4f. \n", sum, log(2.0));
}


