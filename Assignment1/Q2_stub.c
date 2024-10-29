#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// I tried to make this determinant function how I would in other coding languages, using 
// recursive function calls. The only way I could figure out to do this was through 
// stucts. Using the Matrix struct that I used for practical 6 I made a recursive determinant
// function, a printMat function to print the matrices nicely, and a minor function to get
// the Minors of a matrix.

//Matrix struct
struct Mat{
	int row;		//no. of rows
	int col;		//no. of cols
	double **Array;		//array of pointers, which point to arrays of double pointers.
	// Array[i] is an array of double pointers that point to the contents of the ith row.
	// So A[i][j] points to the content of the ith row and jth column as expected.
};

//TODO Complete variable declarations

//function intialisation
struct Mat CreateMat(int row, int col);		// create matrix with given rows and colums, intialised with 0.0 in each position
struct Mat Minor(int m, struct Mat M);		// return the [0,m] minor of M
double Det(struct Mat A);			// Recursive function to calculate det of A
void printMat(struct Mat A);			// Print A row by row


void main(){
//TODO Initialise Hilbert matrix and print
	struct Mat A = CreateMat(4,4);		// Init 4x4 matrix
	for(int i=0; i<A.row; i++){
		for(int j=0; j<A.col; j++){
			A.Array[i][j] = 1/((double) i+j+1);	//Fill A with correct entries
		}
	}
	printMat(A);				// Print A
	
//TODO Find determinant of 4x4 Hilbert matrix using Cramer rule	
	double det = Det(A);			// Calculate the det of A
	
//TODO Print calculated determinant	
	printf("\n%.10f \n",det);		// Print out det(A)
}

//TODO Complete function definition to get determinant

// function to intiialise a Mat struct with a given number of rows and columns
struct Mat CreateMat(int row, int col){
	struct Mat A;							// Initialise new Mat A
	A.row = row;							// Set number of rows and cols
	A.col = col;

	double **array = calloc(row, sizeof(double *));			// Use calloc to allocate memory for and initialise an array of double pointers with (row) pointers
	for(int i=0; i<row; i++){
		array[i] = calloc(col, sizeof(double));			// For each pointer in **array use calloc to allocate memory for and intialise an array with (col) doubles 
	}
	A.Array = array;						// Set A.Array equal to array
	return A;							// Return the Mat A
};

// function to return the [0,m] minor of M
struct Mat Minor(int m, struct Mat A){
	struct Mat M = CreateMat(A.row - 1, A.col - 1);			// Init Mat of correct dimensions for Minor
	int k = 0;							// Int for col number of Minor
	for(int i=0; i<A.col; i++){
		if(i!=m){						// Skip the mth column
			for(int j=0; j<A.row-1; j++){
				M.Array[j][k] = A.Array[j+1][i];	// Assign Minor values
			}	
		k+=1;							// Only increment k if i!=m
		}
	}
	return M;							// Return Minor
}

// Fucntion to calculate determinant of A using recursive function calls
double Det(struct Mat A){
	double det = 0.0;				// Initialise det
	if(A.col != A.row){				// Make sure Matrix is square
		printf("Matrix not square");
		return 0.0;
	}
	if(A.col == 1){					// If Matrix is 1x1 just return as double
		det = A.Array[0][0];
	}
	else{
	for(int i=0; i<A.col; i++){
		det+=pow(-1,i)*Det(Minor(i,A))*A.Array[0][i];	// Expand determinant across top row
	}}
	return det;
}	

// Function ot print out a Mat struct in a nice way, with each row printed out on a seperate line
void printMat(struct Mat A){
	for(int i=0; i< A.row; i++){
		printf("\n");
		for(int j=0;j<A.col; j++){
			printf(" %.4f ", A.Array[i][j]);
		}
	}
	printf("\n");
}

