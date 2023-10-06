#include "hash_tables.h"

/**
 * key_index - Gives the index in a key
 * @key: point to the given key
 * @size: an arrays size of the hash table
 * Return: The indexs of the key in the hash table
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
		unsigned long int indexs = 0;

			indexs = hash_djb2(key);
				indexs %= size;
					return (indexs);
}
