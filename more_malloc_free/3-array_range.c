#include <stdlib.h>
#include "main.h"
/**
* array_range - creates array of integers from min to max
* @min: minimum value
* @max: maximum value
* Return: pointer to array or NULL
*/
int *array_range(int min, int max)
{
int *arr;
int i;
if (min > max)
return (NULL);
arr = malloc(sizeof(int) * (max - min + 1));
if (arr == NULL)
return (NULL);
for (i = 0; min <= max; i++, min++)
arr[i] = min;
return (arr);
}
