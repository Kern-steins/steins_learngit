#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i = 0;
	unsigned int sum = 0;
	for (; i < 16; i++){
		sum = sum + 1U<<i;
	}
	return 0;
}
