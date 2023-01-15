#include<stdio.h>

void test(int x){

	int a,b;
	a = (x%100)/10;
	b = x % 10;
	printf ("The ten digit of the number is %d,the one digit of the number is %d\n",a,b);

}
int main(){
	
	double i = 20.0;
	double j = i / 7.0;
	if (j * 7.0 == i)
			printf ("Equal.\n");
	else
			printf ("Unequal.\n");	

	return 0;

}
