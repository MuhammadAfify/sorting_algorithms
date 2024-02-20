#include "sort.h"

void _swap(int *a, int *b);
int partition(int *array, size_t size, int left, int right);
void _sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * partition - Order a subset of an array of integers
 *
 * @array: The array of integers
 * @size: The size of the array
 * @left: The starting index of the subset to order
 * @right: The ending index of the subset to order
 * Return: The final partition index
 */
int partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				_swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}
	if (array[above] > *pivot)
	{
		_swap(array + above, pivot);
		print_array(array, size);
	}
	return (above);
}

/**
 * _sort - Implement the quicksort algorithm through recursion
 *
 * @array: An array of integers to sort
 * @size: The size of the array
 * @left: The starting index of the array partition to order
 * @right: The ending index of the array partition to order
 */
void _sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = partition(array, size, left, right);
		_sort(array, size, left, part - 1);
		_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *
 * @array: An array of integers
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	_sort(array, size, 0, size - 1);
}
