#include <stdio.h>


void change_array(int array[], int n);
void change_array_point(int *array, int n);

int main(int argc, char const *argv[])
{
	int a[3] = { 0, 1, 2 };
	printf("a[0] = %d a[1] = %d a[2] = %d \n", a[0], a[1], a[2]);
	change_array(a, 3);
	printf("a[0] = %d a[1] = %d a[2] = %d \n", a[0], a[1], a[2]);
	change_array_point(a, 3);
	printf("a[0] = %d a[1] = %d a[2] = %d \n", a[0], a[1], a[2]);
	return 0;
}

void change_array(int array[], int n)
{

	for (int i = 0; i < n; i++)
		array[i] = i + 3;
	printf("array[0] = %d array[1] = %d array[2] = %d \n", array[0],
	       array[1], array[2]);
}


void change_array_point(int *array, int n)
{

	for (int i = 0; i < n; i++)
		array[i] = i + 4;

	printf("array[0] = %d array[1] = %d array[2] = %d \n", array[0],
	       array[1], array[2]);
}
