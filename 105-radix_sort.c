#include "sort.h"

int find_max(int *array, int size);
void radix_count(int *array, size_t size, int sigd, int *buff);
void radix_sort(int *array, size_t size);

/**
 * find_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int find_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * radix_count - Sorts the significant digits of an array in ascending order.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sigd: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 *
 * Return: void
 */
void radix_count(int *array, size_t size, int sigd, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sigd) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / sigd) % 10] - 1] = array[i];
		count[(array[i] / sigd) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: uses the LSD radix sort algo and Prints the resulting arrays.
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int max, sigd, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = find_max(array, size);
	for (sigd = 1; max / sigd > 0; sigd *= 10)
	{
		radix_count(array, size, sigd, buff);
		print_array(array, size);
	}

	free(buff);
}
