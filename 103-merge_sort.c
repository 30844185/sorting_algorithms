#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _merge_sort - initiate merge sort
 * @array: array to be sorted
 * @temp: temporary array for holding sorted elements
 * @size: size of the array
 */
void _merge_sort(int *array, int *temp, size_t size)
{
	size_t half = size / 2, y = 0, z = 0, k;

	if (size < 2)
		return;

	_merge_sort(array, temp, half);
	_merge_sort(array + half, temp + half, size - half);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, half);
	printf("[right]: ");
	print_array(array + half, size - half);
	for (k = 0; k < size; k++)
		if (z >= size - half || (y < half && array[y] < (array + half)[z]))
		{
			temp[k] = array[y];
			y++;
		}
		else
		{
			temp[k] = (array + half)[z];
			z++;
		}
	for (k = 0; k < size; k++)
		array[k] = temp[k];
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - initiate merge sort
 * @array: array to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;

	temp = malloc(sizeof(*temp) * size);
	if (!temp)
		return;

	_merge_sort(array, temp, size);
	free(temp);
}
