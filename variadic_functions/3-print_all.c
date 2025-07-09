#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything
 * @format: list of types of arguments passed
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
switch (format[i])
{
case 'c':
printf("%s%c", sep, va_arg(args, int));
break;
case 'i':
printf("%s%d", sep, va_arg(args, int));
break;
case 'f':
printf("%s%f", sep, va_arg(args, double));
break;
case 's':
str = va_arg(args, char *);
if (str)
printf("%s%s", sep, str);
else
printf("%s(nil)", sep);
break;
}
if (format[i] == 'c' || format[i] == 'i' ||
format[i] == 'f' || format[i] == 's')
sep = ", ";
i++;
}

printf("\n");
va_end(args);
}
