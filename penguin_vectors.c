#include <stdio.h>
#include <math.h>

/*The direction vector that gets updated*/
double direction[2];

double distance(double a[2], double b[2]);
void change(double a[2], double b[2]);

int main() {
  /*testing stuff idk how else to do this*/
  double n1[2];
  double n2[2];
  int blank;
  scanf("%lf", &n1[0]);
  scanf("%lf", &n1[1]);
  scanf("%lf", &n2[0]);
  scanf("%lf", &n2[1]);
  printf("The distance is: %lf\n", distance(n1, n2));
  change(n1, n2);
  printf("The direction in the X direction is: %lf\n", direction[0]);
  printf("The direction in the Y direction is: %lf\n", direction[1]);
}


/*Distance function*/
double distance(double a[2], double b[2]) {
  double result, sq1, sq2;
  double dx = fabs(a[0] - b[0]);
  double dy = fabs(a[1] - b[1]);
  result = sqrt((dx * dx) + (dy * dy));
  return result;
}




/*Direction function*/
/*Changes the value of the global variable*/
void change(double a[2], double b[2]) {
  /*assumes it's the same orientation we did in the drawing*/
  double dx = b[0] - a[0];
  double dy = b[1] - a[1];
  double hypotenuse = distance(a, b);

  direction[0] = dx / hypotenuse;
  direction[1] = dy / hypotenuse;
}

