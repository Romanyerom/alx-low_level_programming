#include <stdlib.h>

/**
 * free_grid - frees a 2D grid previously created by alloc_grid
 * @grid: pointer to pointer to int representing the 2D array
 * @height: height of the 2D array
 *
 * Return: nothing
 */
void free_grid(int **grid, int height)
{
int i;
if (grid == NULL || height <= 0)
return;

for (i = 0; i < height; i++)
{
if (grid[i] != NULL)
free(grid[i]);
}
free(grid);
}
