#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
* advanced_binary_recursive - Searches for a value in a sorted array using
*                             advanced binary search algorithm.
* @array: Pointer to the first element of the [sub]array to search.
* @left: Start index of the [sub]array.
* @right: End index of the [sub]array.
* @value: Value to search for.
*
* Return: Index where the value is located, or -1 if not found.
*
* Description: Performs a recursive binary search on the sorted array.
* Prints the [sub]array being searched after each change.
*/
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
size_t i;

if (right < left)
return (-1);

printf("Searching in array: ");
for (i = left; i < right; i++)
printf("%d, ", array[i]);
printf("%d\n", array[i]);

i = left + (right - left) / 2;
if (array[i] == value && (i == left || array[i - 1] != value))
return (i);
if (array[i] >= value)
return (advanced_binary_recursive(array, left, i, value));
return (advanced_binary_recursive(array, i + 1, right, value));
}

/**
* advanced_binary - Searches for a value in a sorted array
*                   of integers using advanced binary search.
* @array: Pointer to the first element of the array to search.
* @size: Number of elements in the array.
* @value: Value to search for.
*
* Return: Index where the value is located, or -1 if not found.
*
* Description: Initiates the advanced binary search on the sorted array.
* Prints the [sub]array being searched after each change.
*/
int advanced_binary(int *array, size_t size, int value)
{
if (array == NULL || size == 0)
return (-1);

return (advanced_binary_recursive(array, 0, size - 1, value));
}

