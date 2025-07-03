#include <stdlib.h>
#include <string.h>
#include "dog.h"

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

name_len = strlen(name);
owner_len = strlen(owner);

name_copy = malloc(name_len + 1);
if (name_copy == NULL)
{
free(new_dog);
return (NULL);
}
strcpy(name_copy, name);

owner_copy = malloc(owner_len + 1);
if (owner_copy == NULL)
{
free(name_copy);
free(new_dog);
return (NULL);
}
strcpy(owner_copy, owner);

new_dog->name = name_copy;
new_dog->age = age;
new_dog->owner = owner_copy;

return (new_dog);
}
