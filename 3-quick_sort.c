#include "sort.h"

/**
 * quick_sort - function that sorts an array of integers
 *              in ascending order using the Quick sort algorithm
 * @array: array
 * @size: array's size
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_s(array, 0, size - 1, size);
}

/**
 * partition - partition
 * @array: array
 * @lo: lower
 * @hi: higher
 * @size: array's size
 * Return: y
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int y = lo - 1, z = lo;
	int pivot = array[hi], aux = 0;

	for (; z < hi; z++)
	{
		if (array[z] < pivot)
		{
			y++;
			if (array[y] != array[z])
			{
				aux = array[y];
				array[y] = array[z];
				array[z] = aux;
				print_array(array, size);
			}
		}
	}
	if (array[y + 1] != array[hi])
	{
		aux = array[y + 1];
		array[y + 1] = array[hi];
		array[hi] = aux;
		print_array(array, size);
	}
	return (y + 1);
}

/**
 * quick_s - quick sort
 * @array: given array
 * @lo: lower
 * @hi:higher
 * @size: array's size
 * Return: void
 */
void quick_s(int *array, int lo, int hi, size_t size)
{
	int pivot;

	if (lo < hi)
	{
		pivot = partition(array, lo, hi, size);
		quick_s(array, lo, pivot - 1, size);
		quick_s(array, pivot + 1, hi, size);
	}
}
