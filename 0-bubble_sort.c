#include "sort.h"

/**
 * bubble_sort - sorts array of integers in ascending order
 * @array: array
 * @size: size
 */
void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t x, y;
	bool swap;

	if (!array)
		return;

	swap = 1;
	for (x = 0; x < (size - 1) && swap; x++)
	{
		swap = 0;
		for (y = 0; y < (size - 1 - x); y++)
		{
			if (array[y] > array[y + 1])
			{
				tmp = array[y];
				array[y] = array[y + 1];
				array[y + 1] = tmp;

				swap = 1;
				print_array(array, size);
			}
		}
	}
}
