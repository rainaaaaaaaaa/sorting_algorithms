#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using
 * the Selection sort algorithm
 * @array: array
 * @size: size
 */
void selection_sort(int *array, size_t size)
{
	size_t x, y, index;
	int temp;

	if (!array)
		return;

	for (x = 0; x < (size - 1); x++)
	{
		index = x;
		for (y = x + 1; y < size; y++)
			if (array[index] > array[y])
				index = y;

		if (x != index)
		{
			temp = array[x];
			array[x] = array[index];
			array[index] = temp;
			print_array(array, size);
		}
	}
}
