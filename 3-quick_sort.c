#include "sort.h"

/**
 * partition - partitioning scheme for the quicksort algorithm
 *
 * @array: Pointer to  the beginning of an array
 * @lo: lowest index of array
 * @hi: highest index of array
 * @size: The size of the array
 * Return: index of pivot
 */

int partition(int *array, int lo, int hi, size_t size)
{
	int piv, swap;
	int i, j;

	piv = array[hi];
	i = lo - 1;
	for (j = lo; j < hi; j++)
	{
		if (array[j] < piv)
		{
			i++;
			if (i != j)
			{
				swap = array[i];
				array[i] = array[j];
				array[j] = swap;
				print_array(array, size);
			}
		}
	}
	if (array[hi] < array[i + 1])
	{
		swap = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = swap;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_s - Quicksort recurssive funtion
 *
 * @array: Pointer to  the beginning of an array
 * @lo: lowest index of array
 * @hi: highest index of array
 * @size: The size of the array
 * Return: index of pivot
 */

void quick_s(int *array, int lo, int hi, size_t size)
{
	int piv;

	if (lo < hi)
	{
		piv = partition(array, lo, hi, size);
		quick_s(array, lo, piv - 1, size);
		quick_s(array, piv + 1, hi, size);
	}
}

/**
 * quick_sort - sort array using quicksort algorithm
 *
 * @array: Pointer to  the beginning of an array
 * @size: The size of the array
 * Return: index of pivot
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_s(array, 0, size - 1, size);
}
