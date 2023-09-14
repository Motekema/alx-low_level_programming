#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position
 * @h: Pointer to a pointer to the head of the list
 * @idx: Index where the new node should be inserted
 * @n: Value to be stored in the new node
 *
 * Return: Address of the new node on success, NULL on failure
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    dlistint_t *new_node, *current = *h;
    unsigned int i = 0;

    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = n;

    if (idx == 0)
    {
        new_node->next = current;
        new_node->prev = NULL;
        if (current != NULL)
            current->prev = new_node;
        *h = new_node;
        return (new_node);
    }

    while (i < idx - 1)
    {
        if (current == NULL)
        {
            free(new_node);
            return (NULL);
        }
        current = current->next;
        i++;
    }

    new_node->next = current->next;
    new_node->prev = current;
    if (current->next != NULL)
        current->next->prev = new_node;
    current->next = new_node;

    return (new_node);
}
