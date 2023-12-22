#include "sort.h"

/**
 * shell_sort - sort an array using shell sort algorithm
 * @array: array
 * @size: size
 *
 * Return: void
*/
void shell_sort(int *array, size_t size)
{
	int temp;
	size_t x, y, hol = 1;

	if (size <= 1)
		return;
	while (hol < size / 3)
	{
		hol = hol * 3 + 1;
	}

	for (; hol > 0; hol = (hol - 1) / 3)
	{
		for (x = hol; x < size; x++)
		{
			temp = array[x];
			for (y = x; (y >= hol && array[y - hol] > temp); y -= hol)
			{
				array[y] = array[y - hol];
			}
			array[y] = temp;
		}
		print_array(array, size);
	}
}
