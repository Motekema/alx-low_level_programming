#include "lists.h"

/**
* add_dnodeint_end - Add a new node at the end of a dlistint_t list
* @head: Pointer to the pointer of the head of the list
* @n: The integer value to be stored in the new node
*
* Return: The address of the new element, or NULL if it failed
*/
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
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
h->next = new_node;
}
else
{
*head = new_node;
}

new_node->prev = z;

return (new_node);
}
