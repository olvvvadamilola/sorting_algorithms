#include "sort.h"

/**
 * switch_int - Swap two integers in an array.
 * @a: int 1
 * @b: int 2
 */
void switch_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Partition an array using the Lomuto partition scheme.
 * @array: array of integers.
 * @size: size of the array.
 * @l: The starting index of the array partition to order.
 * @r: The ending index of the array partition to order.
 *
 * Return: The index of the pivot.
 */
int lomuto_partition(int *array, size_t size, int l, int r)
{
	int *pivot, up, down;

	pivot = array + r;
	for (up = down = l; down < r; down++)
	{
		if (array[down] < *pivot)
		{
			if (up < down)
			{
				switch_int(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[up] > *pivot)
	{
		switch_int(array + up, pivot);
		print_array(array, size);
	}

	return (up);
}

/**
 * lomuto_sort - Sort an array of integers using the Lomuto partition scheme.
 * @array: An array of integers.
 * @size: The size of the array.
 * @l: The starting index of the array partition to order.
 * @r: The ending index of the array partition to order.
 */
void lomuto_sort(int *array, size_t size, int l, int r)
{
	int i;

	if (r - l > 0)
	{
		i = lomuto_partition(array, size, l, r);
		lomuto_sort(array, size, l, i - 1);
		lomuto_sort(array, size, i + 1, r);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending order
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
