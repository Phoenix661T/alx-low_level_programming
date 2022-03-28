#include "search_algos.h"
#include <math.h>
/**
 * jump_search - searches for a value in a sorted array of
 * integers using the Jump search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: first index where value is located
 * If value is not present in array or if array is NULL, return -1
 */

int jump_search(int *array, size_t size, int value)
{
size_t jump = 0, prev = 0, next = 0;

if (!array || size == 0)
return (-1);

jump = sqrt(size);

while (next < size && array[next] < value)
{
printf("Value checked array[%lu] = [%d]\n", next, array[next]);
/*
*if (array[prev] == value)
*return (prev);
*/
prev = next;
next = next + jump;
}
printf("Value found between indexes [%lu] and [%lu]\n", prev, next);
while (array[prev] <= value && prev <= next && prev < size)
{
printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
if (array[prev] == value)
return (prev);
prev += 1;
}
return (-1);
}
