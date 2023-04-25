#include "sort.h"

/**
 * shell_sort - Shell sort - Knuth Sequence
 * @array: array to sort
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	int gap = 1, y, z, tmp;

	while (gap < ((int)(size)))
		gap = (3 * gap) + 1;
	for (gap = (gap - 1) / 3; gap > 0; gap = (gap - 1) / 3)
	{
		for (y = gap; y < (y nt)size; y += 1)
		{
			tmp = array[y];

			for (z = y; z >= gap && array[z - gap] > tmp; z -= gap)
				array[z] = array[z - gap];

			array[z] = tmp;
		}
		print_array(array, size);
	}
}
