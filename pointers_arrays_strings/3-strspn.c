#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: the main string to scan
 * @accept: the string of accepted characters
 *
 * Return: the number of bytes in s that match only accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j, count;

	count = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		int found = 0;

		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				found = 1;
				break;
			}
		}

		if (found == 0)
			break;

		count++;
	}

	return (count);
}
