#include "sort.h"
/**
 * shell_sort - sort array
 *
 * @array: The array to be printed
 * @size: Number of elements in array
 */

void shell_sort(int *array, size_t size)
{
	size_t i, ga = 1, j;
	int b;

	if (array == NULL)
		return;
	while (ga < size)
		ga = 3 * ga + 1;
	if (ga >= size)
		ga = (ga - 1) / 3;
	while (ga > 0)
	{
		for (i = ga; i < size; i++)
		{
			b = array[i];
			for (j = i; j > (ga - 1) && (b < array[j - ga]); j -= ga)
			{
				array[j] = array[j - ga];
			}
			array[j] = b;
		}
		ga = (ga - 1) / 3;
		print_array(array, size);
	}
}