#include <stdlib.h>
#include "sort.h"

/**
 * swap - this function swaps two items in a array
 * @a: the first item to be swapped
 * @b: the second item to be swapped
 */

void swap(int *a, int *b)
{
	int tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - function sorts elements in an array using selection sort
 * @array: array to be sorted
 * @size: the size of the array to be sorted
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t min_idx;
	int min_change;

	for (i = 0; i < size; i++)
	{
		min_idx = i;
		min_change = 0;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min_idx])
			{
				min_idx = j;
				min_change = 1;
			}
		if (min_change)
		{
			swap(&array[i], &array[min_idx]);
			print_array(array, size);
		}
	}
}
