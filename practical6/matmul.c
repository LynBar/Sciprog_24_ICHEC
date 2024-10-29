#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "matmul.h"
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

// Fucntion to return the matrix product of Mat A and Mat B
struct Mat matmul(struct Mat A, struct Mat B){
	if(A.col != B.row){		// Make sure that the dimensions allow for matrix multiplication
		printf("\nDimensions are incorrect, %d, %d. \n", A.col, B.row);
		return A;
	}

	struct Mat AB = CreateMat(A.row, B.col);					// Initialise AB with correct dimensions to store A*B
	for(int i=0; i<AB.row; i++){
		for(int j=0; j<AB.col; j++){
			AB.Array[i][j] = 0.0;						// Set AB[i][j] to zero
			for(int k=0; k<A.col; k++){
				AB.Array[i][j] += A.Array[i][k]*B.Array[k][j];		// Set AB[i][j] to Sum(A[i][k]*B[k][j]) with sum over k, (Matrix multiplication)
			}
		}
	}
	return AB;									// Return AB
}

// Function ot print out a Mat struct in a nice way, with each row printed out on a seperate line
void printMat(struct Mat A){
	for(int i=0; i< A.row; i++){
		printf("\n");
		for(int j=0;j<A.col; j++){
			printf(" %.2f ", A.Array[i][j]);
		}
	}
	printf("\n");
}

