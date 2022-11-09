#include "sort.h"

void sort_quick(int *array, int start, int end, size_t size);
int lomuto_partition(int *array, int start, int end, size_t size);
void swap(int *array, int *a, int *b, size_t size);

/**
 * quick_sort - calls the sort_quick function
 * @array: the array to be sorted
 * @size: the size of the array to be sorted
 */

void quick_sort(int *array, size_t size)
{
	int start = 0, end = size - 1;

	if (array == NULL || size < 2)
		return;

	sort_quick(array, start, end, size);
}

/**
 * sort_quick - function that sorts an array using the quick sort algorithm
 * @array: the array to be sorted
 * @start: the start index of the array
 * @end: the last index of the array
 * @size: the size of the array
 */

void sort_quick(int *array, int start, int end, size_t size)
{
	int pivot;

	if (start < end)
	{
		pivot = lomuto_partition(array, start, end, size);
		sort_quick(array, start, pivot - 1, size);
		sort_quick(array, pivot + 1, end, size);
	}
}

/**
 * lomuto_partition - function applies the lomuto partition to
 * partition the array
 * @array: the array to be partitioned
 * @start: the start index of the array
 * @end: the end index of the array
 * @size: the size of the array
 * Return: the chosen pivot of the partition
 */

int lomuto_partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end], i;
	int t_idx = start;

	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			swap(array, &array[i], &array[t_idx], size);
			t_idx = t_idx + 1;
		}
	}
	swap(array, &array[t_idx], &array[end], size);
	return (t_idx);
}

/**
 * swap - swaps items of given array
 * @array: array which elements are to be swapped, used by
 * the print array function
 * @a: the first element to be swapped
 * @b: the second element to be swapped
 * @size: the size of the array, used to print the array
 */

void swap(int *array, int *a, int *b, size_t size)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	print_array(array, size);
}
