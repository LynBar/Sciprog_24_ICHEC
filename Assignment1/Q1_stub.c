// TODO: Complete the inclusion of necessary libraries
#include <stdio.h>
#include <math.h>


int main() {

//TODO: Complete variable declarations
	int n;
	float alpha, beta, sum_x=0, sum_y=0, sum_xy=0, sum_xx=0, sum_yy=0;
// TODO: Enter the number of data points  
	n=4;
	float x[n],y[n];

// TODO: Enter (xi, yi) values i=1, 2, ..., n
//       Note that C array indices start from 0
	x[0] = 1.0; x[1] = 2.0; x[2] = 3.0;x[3] = 4.0;
	y[0] = 2.0; y[1] = 4.0; y[2] = 3.0;y[3] = 5.0;

/*
TODO: Calculate alpha and beta formulas
      Use the pow() function for the calculation of power of 2 in the formula.
      Check and exit the code if the denominator for a is equal to zero.
*/
	//Computing the relevant quantities to calculate alpha and beta
	for(int i=0; i<n; i++){
		sum_x = sum_x + x[i];
		sum_y = sum_y + y[i];
		sum_xx = sum_xx + pow(x[i],2);
		sum_yy = sum_yy + pow(y[i],2);
		sum_xy = sum_xy + x[i]*y[i];
	}
	if((float) n *sum_xx - pow(sum_x,2)==0){ // Using == here as division by zero will cause fatal errors
		printf("\n Denominator of aplha is zero");
		return 1;
	}
	// computing alpha and beta in terms of the sums
	alpha = ((float) n * sum_xy - sum_x*sum_y)/((float) n *sum_xx - pow(sum_x,2));
	beta = (sum_y - alpha*sum_x)/((float) n);

//TODO: Print the equation of the line 
	printf("\n y = (%.3f)x + (%.3f)\n", alpha, beta);
	return 0;
}

