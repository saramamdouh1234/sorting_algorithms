#include "sort.h"
/**
 *bubble_sort - a funcation use bubble_sort
 *@array: array of integers
 *@size: size
 *Return: Nothing.
 */
void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t a, z;

	if (array == NULL || size == 0)
		return;

	for (a = 0; a < size; a++)
	{
		z = 0;
		while (z < size - 1)
		{
			if (array[z] > array[z + 1])
			{
				temp = array[z];
				array[z] = array[z + 1];
				array[z + 1] = temp;
				print_array(array, size);
			}
			z++;
		}
	}
}

