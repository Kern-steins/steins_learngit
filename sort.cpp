#include <stdio.h>

#define LENGTH 20

void array_swap(int *rand_array, int Num_1, int Num_2);
void insertion_sort(int *array, int ARRAY_LENGTH);
void array_print(int *rand_array, int RAND_LENGTH);

int main(void)
{
	int array[LENGTH] = { 0 };
	srand(time(NULL));
	gen_random(array, LENGTH, 10);
	merge_sort(array, 0, LENGTH - 1);
	array_print(array, LENGTH);

	return 0;
}

void array_swap(int *rand_array, int Num_1, int Num_2)
{
	int temp = 0;
	temp = rand_array[Num_1];
	rand_array[Num_1] = rand_array[Num_2];
	rand_array[Num_2] = temp;

}

/*
 * 插入排序，时间复杂度为n方 
 * 第一参数为数组指针，第二参数为数组长度
 * 使用函数后会将int型数组元素从小到大排序 
 * 函数将依次从第一个元素开始排序，将最小的元素放到第一个
 * 然后递归判断剩下的子数组
 * 
 * */

void insertion_sort(int *array, int ARRAY_LENGTH)
{
	for (int i = 0; i < ARRAY_LENGTH; i++) {
		for (int j = i + 1; j < ARRAY_LENGTH; j++) {
			if (array[i] > array[j])
				array_swap(array, i, j);
		}
	}
}

void array_print(int *rand_array, int RAND_LENGTH)
{

	for (int i = 0; i < RAND_LENGTH; i++) {
		if (i != RAND_LENGTH - 1) {
			printf("%d\t", rand_array[i]);

		} else
			printf("%d\n", rand_array[i]);
	}

}

/**
 * 该函数用于合并两个有序数列 
 * 输入参数为数组地址，起始坐标，中点坐标，结束坐标
 * 若数组选择段中前半段和后半段均为从小到大排列的
 * 那么该函数将使数组的选择段以从小到大排列
 * */

void array_merge(int *array, int array_start, int array_mid, int array_end)
{
	int n1 = array_mid - array_start + 1;
	int n2 = array_end - array_mid;
	int left[n1] = { 0 };
	int right[n2] = { 0 };
	int i, j, k;

	for (i = 0; i < n1; i++)
		left[i] = array[i + array_start];

	for (j = 0; j < n2; j++)
		right[j] = array[j + array_mid + 1];

	i = j = 0;
	k = array_start;

	while (i < n1 && j < n2) {
		if (left[i] < right[j]) {
			array[k++] = left[i++];
		} else {
			array[k++] = right[j++];
		}
	}
	while (i < n1)
		array[k++] = left[i++];
	while (j < n2)
		array[k++] = right[j++];
}

/**
 * 
 * 合并排序，时间复杂度为O(nlgn)
 * 输入参数为数组地址，要排序的起始坐标和终点坐标
 * 采用将数组不断二分成子序列，每层操作均为n次
 * 有lgn层，所以时间复杂度为O(nlgn)
 * 
 * */

void merge_sort(int *array, int start, int end)
{
	int mid = 0;
	if (start < end) {
		mid = (start + end) / 2;
		merge_sort(array, start, mid);
		merge_sort(array, mid + 1, end);
		array_merge(array, start, mid, end);
	}
}
