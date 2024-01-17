#include "search_algos.h"

/**
* linear_skip - Search for the algorithm in a sorted singly
*               linked list of integer using linear skip.
* @list: A pointer to the  heads of the linked list to search.
* @value: The value to searches for.
*
* Return: If a value is not present or the head ofs the list is NULL, NULL.
*         else, a pointer to the first node where the value is locat.
*
* Description: Print a value every time it is compared in the list.
*              Uses the square root of the list size as the jump step.
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
skiplist_t *node, *jump;

if (list == NULL)
return (NULL);

for (node = jump = list; jump->next != NULL && jump->n < value;)
{
node = jump;
if (jump->express != NULL)
{
jump = jump->express;
printf("Value checked the index [%ld] = [%d]\n",
jump->index, jump->n);
}
else
{
while (jump->next != NULL)
jump = jump->next;
}
}

printf("Value found between the indexes [%ld] and [%ld]\n",
node->index, jump->index);

for (; node->index < jump->index && node->n < value; node = node->next)
printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);

return (node->n == value ? node : NULL);
}
