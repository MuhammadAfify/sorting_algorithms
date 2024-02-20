#include "sort.h"

/**
 * _swap - Swap two integers
 *
 * @x: The first integer to swap.
 * @y: The second integer to swap.
 */
void _swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *
 * @array: array of integers
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			_swap(array + i, min);
			print_array(array, size);
		}
	}
}
