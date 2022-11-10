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
	size_t k = 0, j, l, m, n;

	while (k < size)
		k = 3 * k + 1;
	k = (k - 1) / 3;

	for (k = (k - 1) / 3; k >= 1; k = (k - 1) / 3)
	{
		if (k != 1)
		{
			for (l = k; l < size; l++)
			{
				j = 0;
				if (array[l] < array[j])
				{
					swap(&array[j], &array[l]);
					j++;
				}
			}
		}
		else
		{
			for (m = 0; m < size; m++)
				for (n = m + 1; n < size; n++)
					if (array[n] < array[m])
						swap(&array[n], &array[m]);
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
