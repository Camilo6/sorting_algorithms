#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * quick_sort - is a sorting algorithm
 * @array: Array of the integer list
 * @size: Size of the array
 *
 * Return: void function
 */

void quick_sort(int *array, size_t size)
{
	size_t start = 0;
	size_t end = size - 1;

	if (array != NULL || size > 1)
		recursive_sort(array, size, start, end);

}
/**
 * recursive_sort - recursive function for partition
 * @arr: Array of the integer list
 * @size: Size of the array
 * @min: value min
 * @max: value max
 *
 * Return: void function
 */
void recursive_sort(int arr[], size_t size, int min, int max)
{
	int part;

	if (min < max)
	{
		part = partition(arr, size, min, max);

		recursive_sort(arr, size, min, part - 1);
		recursive_sort(arr, size, part + 1, max);
	}
}



/**
 * partition - partitions array
 * @arr: Array of the integer list
 * @size: Size of the array
 * @low: low of array
 * @high: high of array
 * Return: void function
 */

int partition(int arr[], size_t size, int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1), j;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap_value(&arr[i], &arr[j]);
			if (i != j)
				print_array(arr, size);
		}
	}
	i++;
	swap_value(&arr[i], &arr[high]);
	if (i != j)
		print_array(arr, size);
	return (i);
}

/**
 * swap_value - swap two elements of array
 * @a: first element
 * @b: second element
 *
 * Return: void function
 */


void swap_value(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
