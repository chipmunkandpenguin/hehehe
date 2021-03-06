#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void change();
double distance(double a[2], double b[2]);

// define void function to dynamically allocate array
void push(double *arr, int ind){
	arr = (double *) realloc(arr, sizeof(double) * ind * 4 + sizeof(double) * 4);
	// printf("block size: %d\n", sizeof(double) * ind * 4 + sizeof(double) * 4);
}

// define global variables
double step = 0.05;
double a[2] = {0, 0};
double b[2] = {9, 0};
double u = 1.7;
double v = 2;

int main () {
	int x = sizeof(double);
	printf("the size of a double is: %d\n", x);

	// define dynamic array to store historical data
	double *hist = malloc(4 * sizeof(double));

	// using flag technique
	long flag = 0;
	while (flag != -1){

	printf("now the distance is: %lf\n", distance(a, b));

		// update vectors
		change();

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
		if (distance(a, b) < 2 * (step * (v - u))) {
			flag = -1;
		}
		
	}

	return 0;
}

double distance(double a[2], double b[2]) {
  double result, sq1, sq2;
  double dx = fabs(a[0] - b[0]);
  double dy = fabs(a[1] - b[1]);
  result = sqrt((dx * dx) + (dy * dy));
  return result;
}

void change() {
  double dx = b[0] - a[0];
  double dy = b[1] - a[1];
  double hypotenuse = distance(a, b);

  a[0] += (dx / hypotenuse) * step * v;
  a[1] += (dy / hypotenuse) * step * v;
  b[1] += step * u;
}





















