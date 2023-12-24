#include <stdio.h>

int main(){
	int x, y, *px, *py;

	x = 10;
	y = 20;
	px = &x;
	py = &y;


	printf("Value of x: %d\n", x);
	printf("Value of y: %d\n", y);
	printf("Value of *px: %d\n", (void *) *px);
	printf("Value of *py: %d\n", (void *) *py);

	int arr[10] = {1,2,3,4,5,6,7,8,9};

	printf("Value of arr[0]: %d\n", arr[0]);
	printf("Value of arr[9]: %d\n", arr[9]);

	printf("Address of x: %p\n", (void *) &x);
	printf("Address of y: %p\n", (void *) &y);
	printf("Address of *px: %p\n", (void *) px);
	printf("Address of *py: %p\n", (void *) py);
	printf("Address of arr[0]: %p\n", (void *) &arr[0]);

	int *ptr = &arr[0];

	for (int i = 0; i < 10; i++) {
		printf("arr[%d]: %d\n", i, arr[i]);
}
	return 0;
}
