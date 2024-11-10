#include <stdio.h>

// function initialisation
int gcd_recursive(int a, int b);
int gcd_iterative(int a, int b);

void main(){
	// variable intialisation
	int a,b,c,d; 			// finding gcd of a and b
	a = 8;
	b = 12;
	c = gcd_recursive(a,b); 	// GCD using recursive function call
	d = gcd_iterative(a,b);		// GCD using iterative function call
	printf("\n%d   %d \n", c, d); 	// printing results
	return;	
}

// gcd recursive funciton definition
int gcd_recursive(int a, int b){
	if(b==0){				// base case to stop recursion
		return a;
	}
	else{
		return gcd_recursive(b, a%b);	// if base case not satisfied call function again
	}
}

// gcd iterative function definition
int gcd_iterative(int a, int b){
	int temp;		// temp variable to store variable
	while(b!=0){		// using gcd alogorithm
		temp = b;
		b = a%b;
		a = temp;
	}
	return a;
}
