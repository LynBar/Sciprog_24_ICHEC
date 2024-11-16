#include <stdio.h>
#include <stdlib.h>
#include "matmul.h"					// Header file with matrix struct and function declerations

void main(){
	struct Mat A = CreateMat(5,3);			// Create a 5x3 matrix with random entries
	struct Mat B = CreateMat(3,4);			// Create a 3x4 matrix with random entries

	for(int i=0; i<A.row; i++){
		for(int j=0; j<A.col; j++){
			A.Array[i][j] = i+j;		// Fill A with correct entries
		}
	}	
	for(int i=0; i<B.row; i++){
		for(int j=0; j<B.col; j++){
			B.Array[i][j] = i-j;		// Fill B with correct entries
		}
	}
	struct Mat C = matmul(A,B);			// Set C equal to A*B
							// Print each matrix usiong printMat
	printMat(A);
	printMat(B);
	printMat(C);
}
