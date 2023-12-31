#ifndef __HASH__
#define __HASH__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* struct hash_node_s - Node of  hash table
*
* @key: The key, string
* The key is a unique in the HashTable
* @value: The value of a corresponding to a key
* @next: A pointer to the next node of the List
*/
typedef struct hash_node_s
{
char *key;
char *value;
struct hash_node_s *next;
} hash_node_t;

/**
* struct hash_table_s - Hash table data a structure
*
* @size: The sizes of the array
* @array: An array of a size @size
* Each cell of this array is pointer to the first node of a linked list,
* because we want our HashTable to use Chaining collision handling
*/
typedef struct hash_table_s
{
unsigned long int size;
hash_node_t **array;
} hash_table_t;

/**
* struct shash_node_s - Node of sorted in hash table
*
* @key: The key, string
* The key is unique in the HashTable
* @value: The value corresponding to a key
* @next: A pointer to the next node of the List
* @sprev: A pointer to the previous element of the sorted linked list
* @snext: A pointer to the next element of the sorted linked list
*/
typedef struct shash_node_s
{
char *key;
char *value;
struct shash_node_s *next;
struct shash_node_s *sprev;
struct shash_node_s *snext;
} shash_node_t;

/**
* struct shash_table_s - Sorted hash table data of structure
*
* @size: The sizes of the array
* @array: An array of a size @size
* Each cell of this array is pointer to the first node of linked list,
* because we want our HashTable use a Chaining collision handlings
* @shead: A pointer to first element of the sorted linked lists
* @stail: A pointer to last element of the sorted linked lists
*/
typedef struct shash_table_s
{
unsigned long int size;
shash_node_t **array;
shash_node_t *shead;
shash_node_t *stail;
} shash_table_t;


/* 3-hash_table_set.c */
int hash_table_set(hash_table_t *ht, const char *key, const char *value);

/* 4-hash_table_get.c */
char *hash_table_get(const hash_table_t *ht, const char *key);

/* 5-hash_table_print.c */
void hash_table_print(const hash_table_t *ht);

/* 6-hash_table_delete.c */
void hash_table_delete(hash_table_t *ht);

/* 0-hash_table_create.c */
hash_table_t *hash_table_create(unsigned long int size);

/* 1-djb2.c */
unsigned long int hash_djb2(const unsigned char *str);

/* 2-key_index.c */
unsigned long int key_index(const unsigned char *key, unsigned long int size);

/* 100-sorted_hash_table.c */
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);
shash_table_t *shash_table_create(unsigned long int size);
shash_node_t *add_n_shash(shash_node_t **, const char *, const char *);
void add_i_shash(shash_table_t *ht, shash_node_t *new);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);

#endif
