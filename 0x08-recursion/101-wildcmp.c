#include "main.h"

int wildcmp_local(char *s1, char *s2, int i, int j, int wildIndex, int isWild);
/**
 * wildcmp - compare two strings
 * @s1: the first string
 * @s2: the second string
 *
 * Return: 1 if equal and 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
return (wildcmp_local(s1, s2, 0, 0, -1, 0));
}


/**
 * wildcmp_local - compare two strings
 * @s1: the first string
 * @s2: the second string
 * @i: the first string current index
 * @j: the second string current index
 * @wildIndex: the index of the wild card
 * @isWild: wild card status for the second string
 *
 * Return: 1 if equal and 0 otherwise
 */
int wildcmp_local(char *s1, char *s2, int i, int j, int wildIndex, int isWild)
{
if (s1[i] == '\0')
{
if (s2[j] == '\0')
return (1);
if (s2[j] == '*')
return (wildcmp_local(s1, s2, i, j + 1, j, 1));
return (0);
}

if (isWild)
{
if (s2[j] == '\0')
return (1);
else if (s2[j] == '*')
return (wildcmp_local(s1, s2, i, j + 1, j, 1));
else if (s1[i] == s2[j])
return (wildcmp_local(s1, s2, i + 1, j + 1, wildIndex, 0));
else
return (wildcmp_local(s1, s2, i + 1, j, wildIndex, 1));
}

if (s2[j] == '\0')
return (0);

if (s2[j] == '*')
return (wildcmp_local(s1, s2, i, j + 1, j, 1));
else if (s1[i] == s2[j])
return (wildcmp_local(s1, s2, i + 1, j + 1, wildIndex, 0));
return (wildcmp_local(s1, s2, i + 1, wildIndex + 1, wildIndex, 1));
}
