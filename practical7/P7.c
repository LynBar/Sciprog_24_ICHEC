#include <math.h>
#include <stdio.h>
#include <stdlib.h>
// Function declarations
// exp function for first part of practical
double exp_estimate(int n, double x);
// array functions for sencond part of practical
int *allocatearray(int n);
void fillwithones(int *array, int array_size);
void printarray(int *array, int array_size);
void freearray(int *array);

void main(){
	int n;							// initialise int to store order input
	printf("\n Enter order wanted: ");
	scanf("%d",&n);						// Get order wanted
	printf("\n%.20f", exp_estimate(n,1.0));			// print the estimate
	printf("\n%.20f", exp(1.0) - exp_estimate(n,1.0));	// print the difference with actual value
	
	// Difference is due to numericall accurayc using doubles and ints I think

	// Loop for calling array functions on different sized arrayd
	for(int m=1; m<5; m++){
		printf("\n Function calls on arrays of size %d", m);
		int *p = allocatearray(m);		// allocate memory for array and allocate pointer
		fillwithones(p,m);			// fill array with ones
		printarray(p,m);			// print array
		freearray(p);				// free array
	}
	return;
}

// function to calculate exp(x) using taylor series expansion up to order n
double exp_estimate(int n, double x){
	double *pol = malloc((n+1)*sizeof(double));	// initialise array of doubles of length n+1
	double temp = 1.0;				// initialise temp variable
	pol[0] = 1.0;					// set 0th order term to 1.0
	
	for(int i=1; i<=n; i++){
		temp = temp*x/((double) i);		// update temp to new value
		pol[i] = temp;				// set pol[i] to nth order term
	}	
	
	temp = 0.0;					// use temp to store sum
	for(int i=0; i<=n; i++){
		temp+=pol[i];				// loop through pol and add each order to temp
	}
	return temp;					// return estimate
}

// functions for second part of practical with arrays

// function returns pointer to array of ints of length n
int *allocatearray(int n){
	int *point = malloc(n*sizeof(int));		//use malloc to allocate memory
	return point;
}

void fillwithones(int *array, int array_size){		// need to give array size and pointer to array
	for(int i=0; i< array_size; i++){
		array[i] = 1;				//set each element to 1
	}
	return;
}

void printarray(int* array, int array_size){		// again, need both array, and array size
	for(int i=0; i<array_size; i++){
		printf("\n%d", array[i]);		// print each element
	}
	printf("\n");
	return;
}

void freearray(int *p){
	free(p);					// free the memory allocated to p
	return;
}
