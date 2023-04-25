#include "sort.h"
/**
 * radix_sort - Sort an array of integers in ascending order using the
 *              Radix sort algorithm
 *
 * @array: Array of integers to sort
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int *output;
	int max_value, exp, j;

	if (array == NULL || size < 2)
		return;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	max_value = array[0];
	for (j = 1; j < (int)size; j++)
	{
		if (array[j] > max_value)
			max_value = array[j];
	}

	for (exp = 1; max_value / exp > 0; exp *= 10)
	{
		int count[10] = {0};

		for (j = 0; j < (int)size; j++)
			count[(array[j] / exp) % 10]++;

		for (j = 1; j < 10; j++)
			count[j] += count[j - 1];

		for (j = size - 1; j >= 0; j--)
		{
			output[count[(array[j] / exp) % 10] - 1] = array[j];
			count[(array[j] / exp) % 10]--;
		}

		for (j = 0; j < (int)size; j++)
			array[j] = output[j];

		print_array(array, size);
	}

	free(output);
}
