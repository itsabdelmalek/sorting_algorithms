#include "sort.h"

void merge_arrays(int *merge_arr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_rec(int *merge_arr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_arr - Sort a subarray of integers.
 * @merge_arr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted subarray.
 * @front: The front index of the array.
 * @mid: The middle index of the array.
 * @back: The back index of the array.
 */
void merge_arrays(int *merge_arr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(merge_arr + front, mid - front);

	printf("[right]: ");
	print_array(merge_arr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (merge_arr[i] < merge_arr[j]) ? merge_arr[i++] : merge_arr[j++];
	for (; i < mid; i++)
		buff[k++] = merge_arr[i];
	for (; j < back; j++)
		buff[k++] = merge_arr[j];
	for (i = front, k = 0; i < back; i++)
		merge_arr[i] = buff[k++];

	printf("[Done]: ");
	print_array(merge_arr + front, back - front);
}

/**
 * merge_sort_rec - Implement the merge sort algorithm through recursion.
 * @merge_arr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void merge_sort_rec(int *merge_arr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_rec(merge_arr, buff, front, mid);
		merge_sort_rec(merge_arr, buff, mid, back);
		merge_arrays(merge_arr, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_rec(array, buff, 0, size);

	free(buff);
}
