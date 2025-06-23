#include "main.h"

/**
 * _strchr - locates a character in a string
 * @s: the string to search in
 * @c: the character to find
 *
 * Return: pointer to the first occurrence of c in s, or NULL if not found
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
			return (&s[i]);
	}

	if (c == '\0')  /* if we're looking for the end of the string */
		return (&s[i]);

	return (0);  /* return NULL if character is not found */
}
