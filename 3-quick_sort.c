#include "sort.h"

/**
 * swap_values - swap values
 * @a: value 1
 * @b: value 2
*/
void swap_values(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
* split_arrays - splits arrays
* @arr:	array
* @lw: lowest value
* @h: highest value
* @s: size
* Return: Returns two partitions
*/
int split_arrays(int *arr, int lw, int h, int s)
{
	int x = 0, y = 0, pivot = 0;

	pivot = arr[h];

	x = lw;

	for (y = lw; y < h; y++)
	{
		if (arr[y] <= pivot)
		{
			if (y != x)
			{
				swap_values(&arr[y], &arr[x]);
				print_array(arr, s);
			}
			x++;
		}
	}
	if (x != h)
	{
		swap_values(&arr[x], &arr[h]);
		print_array(arr, s);
	}
	return (x);
}

/**
 * recurs - sort the array using recursion
 * @arr: array
 * @lw: lowest index
 * @h: highest index
 * @s: size
*/
void recurs(int *arr, int lw, int h, size_t s)
{
	if (lw < h)
	{
		int indx = split_arrays(arr, lw, h, s);

		recurs(arr, lw, indx - 1, s);
		recurs(arr, indx + 1, h, s);
	}
}

/**
 * quick_sort - sort an array using the quick sort algorithm
 * @array: array
 * @size: size
*/
void quick_sort(int *array, size_t size)
{
	recurs(array, 0, (int)size - 1, size);
}
