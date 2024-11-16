// Struct to hold matrix information
struct Mat {
	int col;		// no. of columns
	int row;		// no. of rows
	double **Array;		// An array of pointers (one for each row), with each pointer pointing to an array of double pointers (col entry for each row)
};
struct Mat CreateMat(int row, int col);			// Returns a Mat struct with a given number of rows and columns
struct Mat matmul(struct Mat A,struct Mat B);		// Returns a Mat struct A*B
void printMat(struct Mat A);				// Prints a Mat struct one row at a time

