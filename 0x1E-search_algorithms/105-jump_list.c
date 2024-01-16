#include "search_algos.h"
#include <math.h>

/**
* jump_list - Searches for a value in a sort list using Jump search algorithm.
* @list: Pointer to the head of the list to search in.
* @size: Number of nodes in the list.
* @value: Value to search for.
*
* Return: Pointer the first node where value is located, or NULL if not found.
*
* Description: Uses the square root of the size of the list as the jump step.
* Prints the value every time it is compared in the list.
*/
listint_t *jump_list(listint_t *list, size_t size, int value)
{
size_t step, prev, i;
listint_t *current;

if (list == NULL || size == 0)
return (NULL);

step = sqrt(size);
prev = 0;
current = list;

while (current != NULL && current->n < value)
{
printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);

prev = current->index;
for (i = 0; i < step && current->next != NULL && current->next->n < value; i++)
current = current->next;

if (i < step)
break;  /* Found the right block */
}

printf("Value found between indexes [%lu] and [%lu]\n", prev, current->index);

while (prev < current->index && prev < size)
{
printf("Value checked at index [%lu] = [%d]\n", prev, current->n);
if (current->n == value)
return (current);

prev++;
current = current->next;
}

printf("Value checked at index [%lu] = [%d]\n", prev, current->n);
return (NULL);
}

