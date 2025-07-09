#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything based on format string
 * @format: list of types of arguments passed
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
va_list args;
unsigned int i = 0;
char *str;
char *sep = "";

va_start(args, format);

while (format && format[i])
{
if (format[i] != 'c' && format[i] != 'i' &&
format[i] != 'f' && format[i] != 's')
{
i++;
continue;
}

printf("%s", sep);
if (format[i] == 'c')
printf("%c", va_arg(args, int));
if (format[i] == 'i')
printf("%d", va_arg(args, int));
if (format[i] == 'f')
printf("%f", va_arg(args, double));
if (format[i] == 's')
{
str = va_arg(args, char *);
if (str == NULL)
printf("(nil)");
else
printf("%s", str);
}

sep = ", ";
i++;
}

printf("\n");
va_end(args);
}
