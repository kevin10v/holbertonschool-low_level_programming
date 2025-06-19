#include "main.h"

/**
* puts_half - prints second half of the string
* @str : string
*/

void puts_half(char *str)
{
int length, n;
for (length = 0; str[length] != 0; length++)
{

}
if (length % 2 == 0)
{
n = length / 2;
}
else
{
n = (length + 1) / 2;
}
while (n < length)
{
_putchar(str[n]);
n++;
}
_putchar('\n');
}
