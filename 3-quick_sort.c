#include "sort.h"

void swaps_int(int *a, int *b);
int lomuto_part(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swaps_int - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swaps_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_part - Orders a subset of an array of integers following
 *               the lomuto partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_part(int *array, size_t size, int left, int right)
{
	int *piv, upper, lower;

	piv = array + right;
	for (upper = lower = left; lower < right; lower++)
	{
		if (array[lower] < *piv)
		{
			if (upper < lower)
			{
				swaps_int(array + lower, array + upper);
				print_array(array, size);
			}
			upper++;
		}
	}

	if (array[upper] > *piv)
	{
		swaps_int(array + upper, piv);
		print_array(array, size);
	}

	return (upper);
}

/**
 * lomuto_sort - Implements the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 * Return: void
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_part(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme.
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
