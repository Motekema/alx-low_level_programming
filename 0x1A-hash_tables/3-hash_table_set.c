#include "hash_tables.h"

/**
* hash_table_set - add items in a hash table
* @ht: the tables
* @key: key of the items
* @value: value of the items
* Return: 1 for success 0 for a failure
*/

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
unsigned long int z;
hash_node_t *new, *tmp;

if (!ht || !key || !(*key))
return (0);
new = malloc(sizeof(*new));
if (!new)
return (0);
new->key = strdup((char *)key);
new->value = strdup(value);
new->next = NULL;
z = key_index((unsigned char *)key, ht->size);
if (!(ht->array[z]))
{
ht->array[z] = new;
}
else
{
/* check for the update */
tmp = ht->array[z];
while (tmp && strcmp(tmp->key, new->key) != 0)
tmp = tmp->next;
if (tmp) /* its update */
{
free(tmp->value);
tmp->value = new->value;
free(new->key);
free(new);
return (1);
}
/* its collision */
tmp = ht->array[z];
new->next = tmp;
ht->array[z] = new;
}

return (1);
}
