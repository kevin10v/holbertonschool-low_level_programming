#include "function_pointers.h"
#include <stddef.h>

/**
 * print_name - prints a name using a function pointer
 * @name: the name to print
 * @f: function that prints the name
 */
void print_name(char *name, void (*f)(char *))
{
if (name == NULL || f == NULL)
return;

f(name);
}
