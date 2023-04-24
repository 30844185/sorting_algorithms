
#include "sort.h"

/**
 * selection_sort - A function that use selection sort algorithm.
 * @array: An array to sort.
 * @size: The size of the array.
 * Return: Nothing.
 */
void selection_sort(int *array, size_t size)
{
	int aux = 0;
	size_t y = 0, z = 0, pos = 0;

	if (array == NULL || size == 0)
		return;

	for (; y < size - 1; y++)
	{
		pos = y;
		for (z = y + 1; z < size; z++)
		{
			if (array[z] < array[pos])
				pos = z;
		}
		if (pos != y)
		{
			aux = array[y];
			array[y] = array[pos];
			array[pos] = aux;
			print_array(array, size);
		}
	}
}
