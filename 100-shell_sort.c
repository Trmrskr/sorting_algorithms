#include "sort.h"
#include <stdlib.h>

void swap(int *a, int *b);

/**
 * shell_sort - function sorts an array using shell sort algorithm
 * @array: array to be sorted
 * @size: the size of the @array
 */

void shell_sort(int *array, size_t size)
{
	size_t kth_seq, i, j;

	if (array == NULL || size < 2)
		return;

	for (kth_seq = 1; kth_seq < (size / 3);)
		kth_seq = kth_seq * 3 + 1;

	for (; kth_seq >= 1; kth_seq /= 3)
	{
		for (i = kth_seq; i < size; i++)
		{
			j = i;
			while (j >= kth_seq && array[j - kth_seq] > array[j])
			{
				swap(&array[j], &array[j - kth_seq]);
				j -= kth_seq;
			}
		}
		print_array(array, size);
	}
}

/**
 * swap - a function to swap two values
 * @a: the first value to be swapped
 * @b: the second value to be swapped
 */

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
