#include <stdio.h>
#include <stdlib.h>

int x = sizeof(int);

void push(int *arr, int size) {
	arr = realloc(arr, (1 + size) * x); 
}

int main() {
	printf("ints have size: %d\n", x);

	int *virgil = malloc(sizeof(int)*2);
	virgil[0] = 0;
	virgil[1] = 1;

	for (int i=0; i<50; i++){
		push(virgil, i + 2);
		virgil[i] = i;
		printf("last item: %d\n", virgil[i]);
	}
}
