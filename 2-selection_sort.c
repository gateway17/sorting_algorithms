#include "sort.h"

/**
 * selection_sort - sort an array of integers in ascending order using the
 * Bubble sort algorithm
 *
 * @array: Pointer to  the beginning of an array
 * @size: The size of the array
 * Return: Always 0
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, tem, min;

	if (array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min])
				min = j;
		if (min != i)
		{
			tem = array[min];
			array[min] = array[i];
			array[i] = tem;
			print_array(array, size);
		}
	}
}
