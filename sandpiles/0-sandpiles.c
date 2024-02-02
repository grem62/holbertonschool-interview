#include <stdlib.h>
#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
{
    int i, j;
    int grid3[3][3];

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid3[i][j] = grid1[i][j] + grid2[i][j];
        }
    }

    printf("=\n");
    print_grid(grid3);
}
