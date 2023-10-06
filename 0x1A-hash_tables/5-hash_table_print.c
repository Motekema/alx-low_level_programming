#include "hash_tables.h"

/**
* hash_table_print - Print all of the hash table
* @ht: Pointer to a hash table
*
* Return: Voids
*/

void hash_table_print(const hash_table_t *ht)
{
unsigned long int h = 0;
int counter = 0;
hash_node_t **arr = NULL;
hash_node_t *nodes = NULL;

if (!ht || !ht->array)
return;

arr = ht->array;
printf("{");

for (; h < ht->size; h++)
{
if (ht->array[h] != NULL)
{
counter++;
if (counter == 2)
printf(", "), counter = 1;
printf("'%s': '%s'", arr[h]->key, arr[h]->value);
nodes = arr[h]->next;
if (nodes)
{
printf(", ");
for (; nodes; nodes = nodes->next)
{
printf("'%s': '%s'", nodes->key, nodes->value);
if (nodes->next)
printf(", ");
}
}
}
}
printf("}\n");
}
