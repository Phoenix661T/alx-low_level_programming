#include "search_algos.h"

/**
 * print_array - Prints the array we are searching in
 * @array: Array where to print from
 * @left: Index to prinf from
 * @right: Max index to print
 */
void print_array(int *array, size_t left, size_t right)
{
char *sep;

sep = "";
printf("Searching in array: ");
while (left <= right)
{
printf("%s", sep);
printf("%d", array[left]);
left += 1;
sep = ", ";
}
printf("\n");
}
/**
 * binary_search - searches for a value in a sorted array of
 * integers using the Binary search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: first index where value is located
 * If value is not present in array or if array is NULL, return -1
 */

int binary_search(int *array, size_t size, int value)
{
size_t left = 0, right = 0, mid = 0;

if (!array)
return (-1);

right = size - 1;

while (left <= right)
{
/* Prints the array in which we are looking for */
print_array(array, left, right);
/*Assigns the value of mid */
if (left != right)
mid = left + ((right - left) / 2);
else
mid = right;
/* Compares the value in index mid with the value we are looking for*/
if (array[mid] == value)
return (mid);

/*Re-assigns left or right according to the each case*/
else if (array[mid] < value)
left = mid + 1;
else
right = mid - 1;
}
return (-1);
}
