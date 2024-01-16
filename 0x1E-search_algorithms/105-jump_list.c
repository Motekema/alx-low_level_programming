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
	size_t step, step_size;
	listint_t *node, *jump;

	if (list == NULL || size == 0)
		return (NULL);

	step = 0;
	step_size = sqrt(size);
	for (node = jump = list; jump->index + 1 < size && jump->n < value;)
	{
		node = jump;
		for (step += step_size; jump->index < step; jump = jump->next)
		{
			if (jump->index + 1 == size)
				break;
		}
		printf("Value checked at the index [%ld] = [%d]\n", jump->index, jump->n);
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			node->index, jump->index);

	for (; node->index < jump->index && node->n < value; node = node->next)
		printf("Value checked at the index [%ld] = [%d]\n", node->index, node->n);
	printf("Value checked at the index [%ld] = [%d]\n", node->index, node->n);
	return (node->n == value ? node : NULL);
}
