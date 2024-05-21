#include "search_algos.h"
#include <stdio.h> /* Assurez-vous d'inclure stdio.h pour printf */

int advanced_binary(int *array, size_t size, int value)
/*function for search number*/
{
	int mid;
	int mid_value;
	size_t i;

	if (array == NULL || size == 0)
		return (-1);

	mid = (size - 1) / 2;
	mid_value = array[mid];

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i != size - 1)
			printf(", ");
	}
	printf("\n");

	if (mid_value == value)
	{
		if (mid == 0 || array[mid - 1] != value)
			return (mid);
		else
			return (advanced_binary(array, mid + 1, value));
	}
	else if (mid_value > value)
	{
		return (advanced_binary(array, mid + 1, value));
	}
	else

	{
		int result = advanced_binary(array + mid + 1, size - mid - 1, value);

		if (result == -1)
			return (-1);
		else
			return (result + mid + 1);
	}
}
