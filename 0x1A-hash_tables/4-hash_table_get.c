#include "hash_tables.h"

/**
* hash_table_get - Get the value from the hash table
* @ht: Hash table to a search into
* @key: Key you are in looking for
* Return: Value of founded by key, otherwise NULL
*/

char *hash_table_get(const hash_table_t *ht, const char *key)
{
unsigned long int indexs = 0;
hash_node_t *nodes = NULL;
hash_node_t *tmp = NULL;

if (!ht || !ht->array || !key)
return (NULL);

indexs = key_index((unsigned char *)key, ht->size);

nodes = ht->array[indexs];
if (!nodes)
return (NULL);

if (strcmp(nodes->key, key) == 0)
return (nodes->value);

for (tmp = nodes; tmp; tmp = tmp->next)
if (strcmp(tmp->key, key) == 0)
return (tmp->value);

return (NULL);
}
