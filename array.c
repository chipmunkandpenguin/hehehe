#include <stdio.h>
#include <stdlib.h>

// define void function to dynamically allocate array
void push(double *arr, int ind){
	realloc(arr, sizeof(double)*ind*4 + sizeof(double)*4);
}

// define global variables
double step = 1;
double l = 1;
double a[2];
double b[2];

int main () {
	// define dynamic array to store historical data
	double *hist = malloc(4*sizeof(double));

	// using flag technique
	long flag = 0;
	while (flag != -1){
		// update vectors
		change(a, b);

		// dynamically allocate more space in history 
		push(hist, flag);

		// update histories
		int pos = 4*flag;
		hist[pos] = a[0];
		hist[pos+1] = a[1];
		hist[pos+2] = b[0];
		hist[pos+3] = b[1];

		// flag and raise if necessary
		flag++;
		if (dist(a, b) < step) {
			flag = -1;
		}
		
	}

	return 0;
}
