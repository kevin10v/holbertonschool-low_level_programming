#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - Prints the sum of the two diagonals of a square matrix.
 * @a: Pointer to the start of the matrix (1D array treated as 2D).
 * @size: Size of the matrix (number of rows/columns).
 */

void print_diagsums(int *a, int size)
{
int sum1, sum2 = 0;
int i;

for (i = 0; i < size * size; i += size + 1)
sum1 = sum1 + a[i];

for (i = size - 1; i < (size * size) - 1; i += size - 1)
sum2 = sum2 + a[i];

printf("%d, %d\n", sum1, sum2);
}
