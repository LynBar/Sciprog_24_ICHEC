#include <stdio.h>
#include <math.h>

void FibIter(int *n, int *m);
double artanh1UserInput(double x);		//arcTan using Maclaurin series with user input tolerance
double artanh1(double x, double delta);		//arcTan using Maclaurin series 
double artanh2(double x);			//arcTan using logs

int main(void){
	int temp, N, n, m;				//Initalisng variables
	N = 10; n = 0; m = 1;				//N for series length, n m for intial Fib values
	for(int k=2; k<=N; k++){
		FibIter(&n, &m);			//Modify n.m
	}

	//arctan part of main
	double x = -0.9;				//Initialising variables, x start point
	N = 180;					//No of points
	double delta = 1e-10;				//Precision
	double TanMc[N], TanLn[N];			//Arrays for holding arcTan values
	for(int i=0; i<=N; i++){
		TanMc[i] = artanh1(x,delta);		//Storing values
		TanLn[i] = artanh2(x);
		printf("\n%.2f",x);			//Printing stuff out
		// Here the difference is multiplied by 1e10 to make it easier to read
		printf("\nDifference in two methods:%.4f", (TanMc[i] - TanLn[i])*1e10);
		x = x + 0.01;				//Update x
	}
	return 1;
}

void FibIter(int *n, int *m){ 				//Updates given Fib values
	int temp = *m;					//Temp to store m
	*m = *m + *n;					//Update m
	*n = temp;					//Update n
	printf("\nFib number: %d", *m);
}
	
double artanh1(double x, double delta){			//Maclaurin series with specified tolerance
	double temp, sum;				//Initialising variables
	int n = 1;
	while(1){					//Keeo going until tolerance is reached
		temp = pow(x,2*n+1)/(2*(float) n +1.0);	//Next term is series
		if(fabs(temp)<delta){
			return x+sum;			//If tol reached return x+sum
		}
		if(n>10000){
			return(x);			//If its caught in infinite loop return
		}
		n=n+1;	
		sum = sum + temp;			//update sum
	}
	return(x);
}

double artanh1UserInput(double x){			//Take users input for tol
	double delta;
	printf("\nEnter a percision:\n");
	scanf("%lf",&delta);
	if(delta <=0.0){
		printf("give a positive percision \n");//Make sure its >0
	}
	return artanh1(x, delta);			//Use function above
}


double artanh2(double x){				//Use logs to calc arcTan
	x = (log(x+1.0) - log(1.0-x))/2.0;
	return x;
}
