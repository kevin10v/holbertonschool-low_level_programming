#include <stdlib.h>
#include "main.h"
/**
* free_grid - frees a 2D grid previously created by alloc_grid
* @grid: pointer to the 2D array
* @height: number of rows in the grid
*/
void free_grid(int **grid, int height)
{
int i;
for (i = 0; i < height; i++)
free(grid[i]);
free(grid);
}
