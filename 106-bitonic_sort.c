#include "sort.h"

void swaps_int(int *a, int *b);
void bit_merge(int *array, size_t size, size_t start, size_t seq,
		char order);
void bit_seq(int *array, size_t size, size_t start, size_t seq, char order);
void bitonic_sort(int *array, size_t size);

/**
 * swaps_int - Swaps two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 *
 * Return: void
 */
void swaps_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bit_merge - Sorts a bitonic sequence inside an array.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence.
 * @seq: The size of the sequence to sort.
 * @order: The direction to sort in.
 *
 * Return: void
 */
void bit_merge(int *array, size_t size, size_t start, size_t seq,
		char order)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((order == UP && array[i] > array[i + jump]) ||
			    (order == DOWN && array[i] < array[i + jump]))
				swaps_int(array + i, array + i + jump);
		}
		bit_merge(array, size, start, jump, order);
		bit_merge(array, size, start + jump, jump, order);
	}
}

/**
 * bit_seq - Converts an array into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the block.
 * @seq: The size of the block
 * @order: The direction for sorting.
 *
 * Return: void
 */
void bit_seq(int *array, size_t size, size_t start, size_t seq, char order)
{
	size_t cut = seq / 2;
	char *str = (order == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bit_seq(array, size, start, cut, UP);
		bit_seq(array, size, start + cut, cut, DOWN);
		bit_merge(array, size, start, seq, order);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 * Return: void
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bit_seq(array, size, 0, size, UP);
}
