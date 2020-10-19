#include "sort.h"

/**
 * bubble_sort - is a simple sorting algorithm that repeatedly steps
 * through the list, compares adjacent elements and swaps them if they
 * are in the wrong order.
 *
 * @array: Array of the integer list
 * @size: Size of the array
 *
 * Return: void function
 */

void bubble_sort(int *array, size_t size)
{
	size_t a, b;
	int tmp;

	if (size == 0)
		return;
	for (a = 0; a < size - 1; a++)
	{
		for (b = 0; b < size - 1 ; b++)
		{
			if (array[b] > array[b + 1])
			{
				tmp = array[b];
				array[b] = array[b + 1];
				array[b + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
