#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to be sorted
 * @size: No of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}


/**
 * quick_sort_helper - Helper function for quick_sort
 * @array: The array to be sorted
 * @l: Left index
 * @r: right index
 * @size: Number of elements in the array
 */
void quick_sort_helper(int *array, int l, int r, size_t size)
{
	int pivot;
	int i, j;
	int tmp;

	if (l >= r)
		return;

	pivot = array[l];
	i = l + 1;
	j = r;

	while (i <= j)
	{
		if (array[i] < pivot && array[j] > pivot)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}

		if (array[i] >= pivot)
			i++;

		if (array[j] <= pivot)
			j--;
	}

	tmp = array[l];
	array[l] = array[j];
	array[j] = tmp;

	quick_sort_helper(array, l, j - 1, size);
	quick_sort_helper(array, j + 1, r, size);
}
