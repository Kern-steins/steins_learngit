#include <stdio.h>

#define LENGTH 20

void array_swap(int *rand_array, int Num_1, int Num_2);
void insertion_sort(int *array, int ARRAY_LENGTH);
void array_print(int *rand_array, int RAND_LENGTH);
void array_merge(int *array, int array_start, int array_mid,
		 int array_end);
void merge_sort(int *array, int start, int end);
int partition(int *array, int start, int end);
void quicksort(int *array, int start, int end);

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

/**
 * 
 * 该函数用于检索第一个元素在数组所选段中的坐标 
 * 输入参数为数组地址，起始坐标和终点坐标
 * 该函数将数组[start～end]重新排列
 * 比array[start]小的排在前面，大的排在后面
 * 返回array[start]的新坐标array[mid]
 * 
 * */

int partition(int *array, int start, int end)
{
	int mid = 0;
	int i, j, k;
	int pivot = array[start];
	int lenth = end - start + 1;
	int temp[lenth] = { 0 };

	j = 0;
	k = lenth - 1;

	for (i = 0; i < lenth; i++) {
		temp[i] = array[i + start];
	}
	for (i = 0; i < lenth; i++) {
		if (temp[i] < pivot) {
			array[start + j] = temp[i];
			j++;
		} else if (temp[i] > pivot) {
			array[start + k] = temp[i];
			k--;
		}

	}
	mid = (j + k) / 2;
	while (j <= k) {
		array[j + start] = pivot;
		j++;
	}
	return mid + start;
}

/**
 * 
 * 快速排序，从小到大排序
 * 平均情况下的时间复杂度也是O(nlgn)，比归并排序有更小的时间常数
 * 输入参数为数组地址，起始地址，终点地址
 * 通过递归将数组重新排列(改变数组元素)
 * 
 * 
 * */

void quicksort(int *array, int start, int end)
{
	int mid = 0;
	if (end > start) {
		mid = partition(array, start, end);
		quicksort(array, start, mid - 1);
		quicksort(array, mid + 1, end);
	}

}

/**
 * 有bug，会陷入死循环
 * 该函数为查找函数，找出数组中第k小的元素
 * 输入参数为数组地址，起始地址，结束地址，第k小
 * 会将数组先排序，后找到第k小元素后return该元素
 * */

int order_statistic(int *array, int start, int end, int k)
{
	int i = partition(array, start, end) + 1;

	if (k == i)
		return array[i];

	else if (k > i) {

		return order_statistic(array, i + 1, end, k - i);

	} else {

		return order_statistic(array, start, i - 1, k);
	}

}
