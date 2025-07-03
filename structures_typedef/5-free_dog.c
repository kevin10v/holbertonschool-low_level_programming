#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - frees memory of a dog_t struct
 * @d: pointer to dog_t to free
 *
 * Description: Frees name, owner, and the struct itself.
 */
void free_dog(dog_t *d)
{
if (d == NULL)
return;

free(d->name);
free(d->owner);
free(d);
}
