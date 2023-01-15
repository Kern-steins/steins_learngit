#include<stdio.h>

void test(int x){

	int a,b;
	a = (x%100)/10;
	b = x % 10;
	printf ("The ten digit of the number is %d,the one digit of the number is %d",a,b);

}
int main(){
	
	int x;
	x= 201;
	int a,b;
	a = (x%100)/10;
	b = x%10;

	printf ("The ten digit of the number is %d,the one digit of the number is %d",a,b);
	test(x);

	return 0;

}
