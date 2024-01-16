#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
* binary_search - Searches for a value in a sorted array using Binary search
* @array: Pointer to the first element of the array to search in
* @size: Number of elements in the array
* @value: Value to search for
*
* Return: Index where value is locat, or -1 if not present or if array is NULL
*/
int binary_search(int *array, size_t size, int value)
{
if (array == NULL || size == 0)
return (-1);

printf("Searching in array: %d", array[0]);
for (size_t i = 1; i < size; i++)
printf(", %d", array[i]);
printf("\n");

size_t left = 0;
size_t right = size - 1;
size_t mid;

while (left <= right)
{
mid = (left + right) / 2;
printf("Searching in array: %d", array[left]);
for (size_t i = left + 1; i <= right; i++)
printf(", %d", array[i]);
printf("\n");

if (array[mid] == value)
return (mid);

if (array[mid] < value)
left = mid + 1;
else
right = mid - 1;
}

return (-1);
}
