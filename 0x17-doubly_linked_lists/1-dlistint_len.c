#include "lists.h"

/**
* dlistint_len - Return the number of elements in a dlistint_t list
* @h: Pointer to the head of the list
*
* Return: The number of nodes in the list
*/
size_t dlistint_len(const dlistint_t *h)
{
dlistint_t *z;
dlistint_t *new_node;

new_node = malloc(sizeof(dlistint_t));
if (new_node == NULL)
return (NULL);

new_node->n = n;
new_node->next = NULL;

z = *head;

if (z != NULL)
{
while (z->next != NULL)
z = z->next;
z->next = new_node;
}
else
{
*head = new_node;
}

new_node->prev = z;

return (new_node);
}
