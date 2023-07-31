#include "lists.h"

/**
 * Return: the number of nodes
 * Using printf
 */

size_t print_listint(const listint_t *h);
{

size_t num1 = 0;

while (h)
{
printf("%d\n", h->n);
num++;
h = h->next;
}
return (num1);
}

