#include <stdlib.h>
#include "main.h"
/**
* _calloc - allocates memory for an array using malloc and sets it to zero
* @nmemb: number of elements
* @size: size of each element
*
* Return: pointer to allocated memory or NULL on failure
*/
void *_calloc(unsigned int nmemb, unsigned int size)
{
unsigned int i;
char *ptr;
if (nmemb == 0 || size == 0)
return (NULL);
ptr = malloc(nmemb * size);
if (ptr == NULL)
return (NULL);
for (i = 0; i < nmemb * size; i++)
ptr[i] = 0;
return (ptr);
}
