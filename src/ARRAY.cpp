#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define LENGTH 20

void gen_random(int *RAND_ARRAY, int RAND_COUNT, int R_LENGTH);
void ARRAY_CHART(int *RAND_ARRAY, int RAND_LENGTH);
void ARRAY_PRINT(int *RAND_ARRAY, int RAND_LENGTH);
int ARRAY_MAX(int *RAND_ARRAY, int RAND_LENGTH);
void ARRAY_SWAP(int *RAND_ARRAY, int Num_1, int Num_2);
void ARRAY_Permutation(int *RAND_ARRAY, int RAND_LENGTH, int start);

int main(int argc, char const *argv[])
{
    int array[LENGTH] = { 0 };
    int a[N] = { 0 };
    int i = 0;
    srand(time(NULL));
    gen_random(a, N, LENGTH);
    for (i = 0; i < N; i++)
        array[a[i]]++;
    ARRAY_CHART(array, LENGTH);
    return 0;
}

/*
*	该函数用来以直方图形式打印数组
*	输入参数为数组地址和数组长度
*	先打印数组元素个数0-RAND_LENGTH
*	然后以直方图形式打印元素数量
*/
void ARRAY_CHART(int *RAND_ARRAY, int RAND_LENGTH)
{

    int MAX = ARRAY_MAX(RAND_ARRAY, RAND_LENGTH);

    for (int a = 0; a < RAND_LENGTH; a++) {
        if (a == RAND_LENGTH - 1) {
            printf("%d\n", a);
        } else
            printf("%d\t", a);
    }
    for (int i = 0; i < MAX; i++) {
        /* code */
        for (int j = 0; j < RAND_LENGTH; j++) {
            if (RAND_ARRAY[j] > i) {
                printf("*\t");
            } else
                printf(" \t");
        }
        printf("\n");
    }

}

/*	该函数用于打印数组的所有元素
*	输入第一个参数为数组地址，第二个是数组长度
*	逐个打印数组元素
*/
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
void gen_random(int *RAND_ARRAY, int RAND_COUNT, int R_LENGTH)
{

    for (int i = 0; i < RAND_COUNT; i++) {

        RAND_ARRAY[i] = rand() % R_LENGTH;

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

/*
 * 数组全排列，输入参数为数组地址，数组长度，以及当前排列位置
 * 将数组元素全部交换后达到base case表明已排列完成，输出数组
 */
void ARRAY_Permutation(int *RAND_ARRAY, int RAND_LENGTH, int start)
{

    if (start == RAND_LENGTH) {
        ARRAY_PRINT(RAND_ARRAY, RAND_LENGTH);
    } else {
        for (int i = start; i < RAND_LENGTH; i++) {

            ARRAY_SWAP(RAND_ARRAY, i, start);
            ARRAY_Permutation(RAND_ARRAY, RAND_LENGTH, start + 1);
            ARRAY_SWAP(RAND_ARRAY, i, start);
        }
    }


}
