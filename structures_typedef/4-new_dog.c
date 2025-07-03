#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - calculates length of a string
 * @s: string to measure
 * Return: length of string
 */
int _strlen(char *s)
{
int i = 0;
while (s[i] != '\0')
i++;
return (i);
}

/**
 * _strcpy - copies a string to a buffer
 * @dest: destination buffer
 * @src: source string
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
int i = 0;
while (src[i] != '\0')
{
dest[i] = src[i];
i++;
}
dest[i] = '\0';
return (dest);
}

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to new dog_t, or NULL if it fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *new_dog;
char *name_copy, *owner_copy;
int name_len, owner_len;

if (name == NULL || owner == NULL)
return (NULL);

new_dog = malloc(sizeof(dog_t));
if (new_dog == NULL)
return (NULL);

name_len = _strlen(name);
owner_len = _strlen(owner);

name_copy = malloc(name_len + 1);
if (name_copy == NULL)
{
free(new_dog);
return (NULL);
}
_strcpy(name_copy, name);

owner_copy = malloc(owner_len + 1);
if (owner_copy == NULL)
{
free(name_copy);
free(new_dog);
return (NULL);
}
_strcpy(owner_copy, owner);

new_dog->name = name_copy;
new_dog->age = age;
new_dog->owner = owner_copy;

return (new_dog);
}
