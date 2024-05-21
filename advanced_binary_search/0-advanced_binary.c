#include "search_algos.h"
#include <stdio.h> /* Assurez-vous d'inclure stdio.h pour printf */


/*
 * Fonction : advanced_binary
 * Description : Cette fonction effectue une recherche binaire avancée dans un tableau trié à la recherche d'une valeur spécifique.
 * Paramètres :
 *   - array : Un pointeur vers le début du tableau d'entiers dans lequel la recherche doit être effectuée.
 *   - size : La taille du tableau.
 *   - value : La valeur entière à rechercher dans le tableau.
 * Retour :
 *   - L'indice de l'élément recherché dans le tableau si celui-ci est trouvé.
 *   - -1 si l'élément n'est pas trouvé dans le tableau.
 */
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
