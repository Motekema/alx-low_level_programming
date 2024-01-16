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
size_t step, prev;

if (array == NULL)
return -1;

step = sqrt(size);
prev = 0;

while (array[custom_min(step, size) - 1] < value)
{
printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);

prev = step;
step += sqrt(size);

if (prev >= size)
break;
}

printf("Value found between indexes [%lu] and [%lu]\n", prev - step, prev);

for (; prev < custom_min(step, size); prev++)
{
printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
if (array[prev] == value)
return prev;
}

return -1;
}

/**
* custom_min - Returns the minimum of two values
* @a: First value
* @b: Second value
*
* Return: The minimum of a and b
*/
size_t custom_min(size_t a, size_t b)
{
return (a < b) ? a : b;
}

