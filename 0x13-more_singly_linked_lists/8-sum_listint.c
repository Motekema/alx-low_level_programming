#include "lists.h"

/**
 * sum_listint - calculates the sum1 of all the data in a listint_t list
 * @head: first node in the linked list
 *
 * Return: resulting sum1
 */
int sum_listint(listint_t *head)
{
int sum1 = 0;
listint_t *temp = head;

while (temp)
{
sum1+= temp->n;
temp = temp->next;
}

return (sum1);
}
