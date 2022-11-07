#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

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

/**
 * bubble_sort - a function that sorts an array by bubbling it
 * @array: pointer to array to be sorted
 * @size: the size of the array to be sorted
 */

void bubble_sort(int *array, size_t size)
{
	int swapped;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 1; i < size; i++)
	{
		swapped = 0;
		for (j = 1; j < size; j++)
		{
			if (array[j] < array[j - 1])
			{
				swap(&array[j], &array[j - 1]);
				swapped = 1;
				print_array(array, size);
			}
		}
		if (!swapped)
			break;
	}
}
