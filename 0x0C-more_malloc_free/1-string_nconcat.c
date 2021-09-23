#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat -  concatenates two strings
 * @s1: String one
 * @s2: String two
 * @n: number of bytes for s2
 *
 * Return: Pointer
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
char *c;
unsigned int i, j, k, l;

if (s1 == NULL)
{
s1 = "";
}
if (s2 == NULL)
{
s2 = "";
}
for (i = 0; s1[i]; i++)
{}
for (j = 0; s2[j]; j++)
{}
if (j > n)
{
j = n;
}
else
{
n = j;
}
k = i + j + 1;
c = malloc(k * sizeof(char));
if (c == NULL)
return (NULL);
for (l = 0; l < k - 1; l++)
{
if (l < i)
{
c[l] = s1[l];
}
else
{
c[l] = s2[l - i];
}
}
c[k] = '\0';
return (c);
}
