#include "hash_tables.h"

/**
* hash_table_create - creat a hash table with a given size
*
* @size: Size of the hash tables
* Return: The create hash table, or NULL if the function fails
*/
hash_table_t *hash_table_create(unsigned long int size)
{
hash_table_t *tables;
hash_node_t **array;
unsigned long int f;

tables = malloc(sizeof(hash_table_t));
if (tables == NULL)
return (NULL);

array = malloc(sizeof(hash_node_t *) * size);
if (array == NULL)
return (NULL);

for (f = 0; f < size; f++)
array[f] = NULL;

tables->array = array;
tables->size = size;

return (tables);
}
