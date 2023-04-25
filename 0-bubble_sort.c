#include "sort.h"

/**
  * bubble_sort - A function for bubble sorting.
  * @array: The array to sort.
  * @size: THe length of the aaray.
  * Return: Nothing.
  */
void bubble_sort(int *array, size_t size)
{
	size_t y = 0, z = 0;
	int aux = 0;

	if (array == NULL || size == 0)
		return;
	for (; y < size - 1; y++)
	{
		for (z = 0; z < size - y - 1; z++)
		{
			if (array[z] > array[z + 1])
			{
				aux = array[z + 1];
				array[z + 1] = array[z];
				array[z] = aux;
				print_array(array, size);
			}
		}
	}
}
