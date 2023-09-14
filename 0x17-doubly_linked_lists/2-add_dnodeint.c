#include "lists.h"

/**
* add_dnodeint - Add a new node at the beginning of a dlistint_t list
* @head: Pointer to the pointer of the head of the list
* @n: The integer value to be stored in the new node
*
* Return: The address of the new element, or NULL if it failed
*/
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
dlistint_t *new_node;
dlistint_t *z;

new_node = malloc(sizeof(dlistint_t));
if (new_node == NULL)
return (NULL);

new_node->n = n;
new_node->prev = NULL;
z = *head;

if (z != NULL)
{
while (h->prev != NULL)
h = h->prev;
}

new_node->next = z;

if (z != NULL)
z->prev = new_node;

*head = new_node;

return (new_node);
}
