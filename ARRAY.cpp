#include <stdio.h>
#include <stdlib.h>

#define N 100
#define LENGTH 10

void gen_random(int* RAND_ARRAY, int RAND_COUNT);
void ARRAY_PRINT(int* RAND_ARRAY, int RAND_LENGTH);
int  ARRAY_MAX (int* RAND_ARRAY,int RAND_LENGTH);

int main(int argc, char const *argv[])
{

	int i, histogram[LENGTH]={0};
	int a[N]={0};

	gen_random(a,N);
	
	for (i=0;i<N;i++){
		histogram[a[i]]++;

	}
	ARRAY_PRINT(histogram, LENGTH);
	return 0;
}
/*
该函数用来以直方图形式打印数组
先确定行数，第一个for循环用于遍历所有行数，第二个for循环用于遍历所有列数
如果ARRAY[j]大于当前行数，也就是当前行存在*，那么就打印*，否则打印空格
*/
void ARRAY_PRINT(int* RAND_ARRAY, int RAND_LENGTH){

	int MAX = ARRAY_MAX(RAND_ARRAY , RAND_LENGTH);

	printf("0 1 2 3 4 5 6 7 8 9\n");
	for (int i=0 ; i < MAX; i++){
	 	/* code */
		for (int j = 0; j < RAND_LENGTH ; j++){
			if( RAND_ARRAY[j] > i){
				printf("* \n");
			}	
			else
				printf("  \n");
		}
		printf("\n");
	 } 

}
/*
该函数用于生成随机数，生成一组随机数赋值给数组
*/
void gen_random(int* RAND_ARRAY, int RAND_COUNT){

	for ( int i=0; i<RAND_COUNT; i++ ){

		RAND_ARRAY[i] = rand() % LENGTH;

	}

}
/*
该函数用于求数组中最大的数，return最大的数
*/
int  ARRAY_MAX (int* RAND_ARRAY,int RAND_LENGTH){

	int MAX=RAND_ARRAY[0];
	for (int i=0 ; i < RAND_LENGTH ; i++){
		if (MAX < RAND_ARRAY[i])
			MAX = RAND_ARRAY[i];

	} 
	return MAX;

}
