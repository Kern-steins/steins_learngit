#ifndef SORT_H
#define SORT_H

void array_swap(int *rand_array, int Num_1, int Num_2);
void insertion_sort(int *array, int ARRAY_LENGTH);
void array_print(int *rand_array, int RAND_LENGTH);
void array_merge(int *array, int array_start, int array_mid,
		 int array_end);
void merge_sort(int *array, int start, int end);
int partition(int *array, int start, int end);
void quicksort(int *array, int start, int end);


#endif
