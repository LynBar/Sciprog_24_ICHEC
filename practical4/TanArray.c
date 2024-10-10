
#include <stdio.h>
#include <math.h>
#include <string.h>

//Function Declarations
float degtorad(float arg);
float IntegrateTanRad(float start, float stop, int N);
float IntegrateTanDeg(float start, float stop, int N);

int M=12;				//length of Tan array
float TanValues[13];			//Intialise global Tan array of correct length


int main(void){
	int N;
	float start,stop;

	N=100;				//Number of steps for integration
	start=0;			//start point of integration
	stop=60.0;			//stop point of integration
	IntegrateTanDeg(start,stop,N);  //Integrate tan over interval
					
	float deg, rad;			//Initialising variables for tan array

	for(int i=0; i<=M; i++){
		deg = (float) i *60.0/(float) M;		//degree value in [0,60]
		rad = degtorad(deg);				//Convert deg to Radians
		TanValues[i] = tan(rad);			//Asign tan(rad) to global  array
	}
		
	// printing the Tan array with corresponding degree values
	for(int i=0; i<=M; i++){
		deg = (float) i *60.0/(float) M;
		printf("\nDegree value: %.3f",deg);
		printf("\nTan value: %.3f",TanValues[i]);

	}
	printf("\n");
}


//Function Definitions
float IntegrateTanRad(float start, float stop, int N){	// Fuction to integrate using Radian Values
	float step, sum;

	step = (stop - start)/N;			//Step size

	sum = tan(start)+tan(stop);			//adding boundary terms from start and finish
	
	for (int i=1; i<N; i++){
		sum=sum + 2.0*tan(start+step*i);	//adding terms in interval at each step
	}

	sum = sum*step/2.0;				//Mulitplying by overall factor (b-a)/2N

	printf("Num of steps: %d \nStep size: %.4f \n", N, step);
	printf("The integral is approximately %.4f, and exactly %.4f. \n", sum, log(2.0));
return sum;
}

float degtorad(float arg){
	return((M_PI*arg)/180.0); 			//Function to convert deg to Rad using M_PI the maths package stored value of Pi. Could also set pi =  arccos(1)
}

float IntegrateTanDeg(float start, float stop, int N){	//Function to integrate tan using degree values
	return IntegrateTanRad(degtorad(start), degtorad(stop), N);
}
