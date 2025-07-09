#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_strings - prints strings separated by a separator
 * @separator: string to print between the strings
 * @n: number of strings passed to the function
 *
 * Return: void
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
va_list args;
unsigned int i;
char *str;

va_start(args, n);

for (i = 0; i < n; i++)
{
str = va_arg(args, char *);
if (str == NULL)
printf("(nil)");
else
printf("%s", str);
if (separator != NULL && i < n - 1)
printf("%s", separator);
}

printf("\n");

va_end(args);
}
