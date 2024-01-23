#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */

void quick_sort(int *array, size_t size)
{
	if (size <= 1)
	{
		return;
	}

	int pivot_index = size - 1;
	int j = 0;
	int temp;
	int i;

	for (i = 0; i < pivot_index; i++)
	{
		if (array[i] <= array[pivot_index])
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			j++;
		}
		print_array(array, size);
	}
	temp = array[j];

	array[j] = array[pivot_index];
	array[pivot_index] = temp;

	quick_sort(array, j);
	quick_sort(array + j + 1, size - j - 1);
}
