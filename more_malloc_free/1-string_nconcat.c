#include <stdlib.h>
#include "main.h"
/**
* string_nconcat - Concatenates two strings using at most n bytes of s2
* @s1: first string
* @s2: second string
* @n: maximum number of bytes of s2 to use
*
* Return: pointer to newly allocated space with s1 + first n of s2
*         NULL on failure
*/
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
unsigned int i = 0, j = 0, len1 = 0, len2 = 0;
char *ptr;
if (s1 == NULL)
s1 = "";
if (s2 == NULL)
s2 = "";
while (s1[len1])
len1++;
while (s2[len2])
len2++;
if (n >= len2)
n = len2;
ptr = malloc(sizeof(char) * (len1 + n + 1));
if (ptr == NULL)
return (NULL);
for (i = 0; i < len1; i++)
ptr[i] = s1[i];
for (j = 0; j < n; j++)
ptr[i + j] = s2[j];
ptr[i + j] = '\0';
return (ptr);
}

