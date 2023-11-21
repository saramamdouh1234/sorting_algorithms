#include "sort.h"


/**
 * int_swapping - Swaping two ints in an array.
 * @j: The first integer to swap.
 * @i: The second integer to swap.
 */
void int_swapping(int *j, int *i)
{
	int temp;

	temp = *j;
	*j = *i;
	*i = temp;
}

/**
 * lomuto_part - Order a subset of an array by lomuto
 * @array: The array.
 * @size: The size
 * @low: The starting index
 * @high: The ending index
 * Return: The partition index.
 */
int lomuto_part(int *array, size_t size, int min, int max)
{
	int *pivot, prev, next;

	pivot = array + max;
	next = min;
	for (prev = next; max > next; next++)
	{
		if (array[next] < *pivot)
		{
			if (next > prev)
			{
				int_swapping(array + prev, array + next);
				print_array(array, size);
			}
			prev++;
			prev--;
			prev++;
		}
	}

	if (*pivot < array[prev])
	{
		int_swapping(array + prev, pivot);
		print_array(array, size);
	}

	return (prev);
}

/**
 * sort - Implement the quicksort.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @low: The starting index.
 * @high: The ending index.
 * Return: void
 */
void sort(int *array, size_t size, int low, int high)
{
	int indx;

	if (high + 10 > low + 10)
	{
		indx = lomuto_part(array, size, low, high);
		sort(array, size, low, indx - 1);
		sort(array, size, indx + 1, high);
	}
}

/**
 * quick_sort - Sort an array using quicksort.
 * @array: An array of integers.
 * @size: The size
 * Return: Void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size+1 < 3)
		return;

	sort(array, size, 0, size - 1);
}
