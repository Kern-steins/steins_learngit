#include <stdio.h>
#include <stdlib.h>

#define N 100
#define LENGTH 4

void gen_random(int *RAND_ARRAY, int RAND_COUNT);
void ARRAY_CHART(int *RAND_ARRAY, int RAND_LENGTH);
void ARRAY_PRINT(int *RAND_ARRAY, int RAND_LENGTH);
int ARRAY_MAX(int *RAND_ARRAY, int RAND_LENGTH);
void ARRAY_SWAP(int *RAND_ARRAY, int Num_1, int Num_2);
void ARRAY_Permutation(int *RAND_ARRAY, int RAND_LENGTH, int start);

int main(int argc, char const *argv[])
{

	int array[LENGTH] = { 1, 2, 3, 4 };
	ARRAY_Permutation(array, LENGTH, 0);

	return 0;
}

/*
该函数用来以直方图形式打印数组
先确定行数，第一个for循环用于遍历所有行数，第二个for循环用于遍历所有列数
如果ARRAY[j]大于当前行数，也就是当前行存在*，那么就打印*，否则打印空格
*/
void ARRAY_CHART(int *RAND_ARRAY, int RAND_LENGTH)
{

	int MAX = ARRAY_MAX(RAND_ARRAY, RAND_LENGTH);

	printf("0 1 2 3 4 5 6 7 8 9\n");
	for (int i = 0; i < MAX; i++) {
		/* code */
		for (int j = 0; j < RAND_LENGTH; j++) {
			if (RAND_ARRAY[j] > i) {
				printf("* ");
			} else
				printf("  ");
		}
		printf("\n");
	}

}

//该函数用于打印数组的所有元素
void ARRAY_PRINT(int *RAND_ARRAY, int RAND_LENGTH)
{

	for (int i = 0; i < RAND_LENGTH; i++) {
		if (i != RAND_LENGTH - 1) {
			printf("%d\t", RAND_ARRAY[i]);

		} else
			printf("%d\n", RAND_ARRAY[i]);
	}

}

/*
该函数用于生成随机数，生成一组随机数赋值给数组
*/
void gen_random(int *RAND_ARRAY, int RAND_COUNT)
{

	for (int i = 0; i < RAND_COUNT; i++) {

		RAND_ARRAY[i] = rand() % LENGTH;

	}

}

/*
该函数用于求数组中最大的数，return最大的数
*/
int ARRAY_MAX(int *RAND_ARRAY, int RAND_LENGTH)
{

	int MAX = RAND_ARRAY[0];
	for (int i = 0; i < RAND_LENGTH; i++) {
		if (MAX < RAND_ARRAY[i])
			MAX = RAND_ARRAY[i];

	}
	return MAX;

}

//交换数组的元素
void ARRAY_SWAP(int *RAND_ARRAY, int Num_1, int Num_2)
{
	int temp = 0;
	temp = RAND_ARRAY[Num_1];
	RAND_ARRAY[Num_1] = RAND_ARRAY[Num_2];
	RAND_ARRAY[Num_2] = temp;

}

//数组全排列
void ARRAY_Permutation(int *RAND_ARRAY, int RAND_LENGTH, int start)
{

	if (start == RAND_LENGTH) {
		ARRAY_PRINT(RAND_ARRAY, RAND_LENGTH);
	} else {
		for (int i = start; i < RAND_LENGTH; i++) {

			ARRAY_SWAP(RAND_ARRAY, i, start);
			ARRAY_Permutation(RAND_ARRAY, RAND_LENGTH,
					  start + 1);
			ARRAY_SWAP(RAND_ARRAY, i, start);
		}
	}


}
