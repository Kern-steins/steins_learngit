#include <stdio.h>

#define LENGTH 10

void array_print(int *array, int ARRAY_LENGTH);


int main(int argc, char const *argv[])
{
	int a[LENGTH] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	array_print(a, LENGTH);
	return 0;

}
