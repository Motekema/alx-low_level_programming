#include "hash_tables.h"

/**
*  * hash_table_delete - deletes hash table
* @ht: this given hash table
*
* Return: voids
*/
void hash_table_delete(hash_table_t *ht)
{
unsigned long int g;
hash_node_t *tmp, *cursor;

if (!ht)
return;
for (g = 0; g < ht->size; g++)
{
cursor = ht->array[g];
while (cursor)
{
tmp = cursor->next;
free(cursor->key);
free(cursor->value);
free(cursor);
cursor = tmp;
}
}
free(ht->array);
free(ht);
}
