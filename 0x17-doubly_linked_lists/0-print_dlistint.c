#include "lists.h"

/**
* print_dlistint - Print all elements of a dlistint_t list
* @h: Pointer to the head of the list
*
* Return: The number of nodes in the list
*/
size_t print_dlistint(const dlistint_t *h)
{
int counts;

counts = 0;

if (h == NULL)
return (counts);

while (h->prev != NULL)
h = h->prev;

while (h != NULL)
{
printf("%d\n", h->n);
counts++;
h = h->next;
}

return (counts);
}

