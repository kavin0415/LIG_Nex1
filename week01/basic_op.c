#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "basic_op.h"

int scanf_ary(int *arr, int size) {
	for (int i = 0; i < size; i++)
	{
		(void)scanf("%d", arr + i);
	}
	return 1;
}
int print_ary(int* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	return 1;
}
int findmax_ary(int* arr, int size) {
	int max = 0x80000000;
	for (int i = 0; i < size; i++)
	{
		if (max < *(arr + i)) {
			max = *(arr + i);
		}
	}
	return max;
}
int findmin_ary(int* arr, int size) {
	int min = 0x7FFFFFFF;
	for (int i = 0; i < size; i++)
	{
		if (min > *(arr + i)) {
			min = *(arr + i);
		}
		
	}
	return min;
}

int sum_ary(int* arr, int size) {
	int total = 0;
	for (int i = 0; i < size; i++)
	{
		total += arr[i];
	}
	return total;
}
double avg_ary(int* arr, int size) {

	return (float)sum_ary(arr,size) / size;
}
#endif