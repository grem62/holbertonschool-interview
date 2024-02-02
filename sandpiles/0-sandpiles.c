#include "sandpiles.h"

/**
 * sandpiles_sum - calcule la somme de deux tas de sable
 * @grid1: premier tas de sable
 * @grid2: deuxième tas de sable
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	// Ajoute les valeurs des deux tas de sable
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	// Tant que le tas de sable n'est pas stable, le renverse et l'affiche
	while (!is_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1);
	}
}

/**
 * print_grid - Affiche un tas de sable 3x3
 * @grid: Tas de sable 3x3
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_stable - Vérifie si le tas de sable est stable
 * @grid: Tas de sable à vérifier
 * Return: 1 si stable, 0 sinon
 */
int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * topple - Renverse le tas de sable
 * @grid: Tas de sable à renverser
 */
void topple(int grid[3][3])
{
	int i, j;
	int tmp[3][3];

	add_grids(grid, tmp);
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			if (tmp[i][j] > 3)
			{
				grid[i][j] -= 4;

				if (i - 1 >= 0)
					grid[i - 1][j] += 1;
				if (j - 1 >= 0)
					grid[i][j - 1] += 1;
				if (i + 1 < 3)
					grid[i + 1][j] += 1;
				if (j + 1 < 3)
					grid[i][j + 1] += 1;
			}
	}
}

/**
 * add_grids - Ajoute deux tas de sable
 * @grid1: premier tas de sable
 * @grid2: deuxième tas de sable
 */
void add_grids(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid2[i][j] = grid1[i][j];
		}
	}
}
