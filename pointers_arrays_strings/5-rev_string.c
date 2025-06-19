#include "main.h"

/**
* rev_string - mirrors the string down the middle
* @s : string
*/

void rev_string(char *s)
{
int length, l_idx, tmp;
for (length = 0; s[length] != 0; length++)
{

}
l_idx = length - 1;
while (l_idx >= length / 2)
{
tmp = s[l_idx];
s[l_idx] = s[length - 1 - l_idx];
s[length - 1 - l_idx] = tmp;
l_idx--;
}
}
