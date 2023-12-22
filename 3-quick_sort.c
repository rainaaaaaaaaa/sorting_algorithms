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
				swap_values(y, x);
			x++;
		}
	}
	if (x != h)
		swap_values(x, h);
	return (x);
}

/**
 * recursion - sort the array using recursion
 * @arr: array
 * @lw: lowest index
 * @h: highest index
 * @s: size
*/
void recursion(int *arr, int lw, int h, size_t s)
{
	if (lw < h)
	{
		int indx = split_values(arr, lw, h, s);

		recursion(arr, lw, indx - 1, s);
		recursion(arr, indx + 1, h, s);
	}
}

/**
 * quick_sort - sort an array using the quick sort algorithm
 * @arr: array
 * @s: size
*/
void quick_sort(int *arr, size_t s)
{
	recursion(arr, 0, (int)s - 1, s);
}
