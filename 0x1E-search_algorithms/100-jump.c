#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
* jump_search - Searches for a value in a sorted array using Jump search
* @array: Pointer to the first element of the array to search in
* @size: Number of elements in the array
* @value: Value to search for
*
* Return: Index where value is locat, or -1 if not present or if array is NULL
*/
int jump_search(int *array, size_t size, int value)
{
if (array == NULL)
return -1;

size_t step = sqrt(size);
size_t prev = 0;

printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
while (array[min(step, size) - 1] < value)
{
prev = step;
step += sqrt(size);
if (prev >= size)
return -1;
printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
}

printf("Value found between indexes [%lu] and [%lu]\n", prev, step);

for (; prev < min(step, size); prev++)
{
printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
if (array[prev] == value)
return prev;
}

return -1;
}

/**
* min - Returns the minimum of two values
* @a: First value
* @b: Second value
*
* Return: The minimum of a and b
*/
size_t min(size_t a, size_t b)
{
return (a < b) ? a : b;
}
