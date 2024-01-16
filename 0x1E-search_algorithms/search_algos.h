#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @n: Integers
 * @index: Index of a node in the list
 * @next: Pointer to a next node
 *
 * Description: singly linked list node structures
 */
typedef struct listint_s
{
		int n;
		size_t index;
		struct listint_s *next;
} listint_t;

/**
 * struct skiplist_s - Singly link list with an express lane
 *
 * @n: Integers
 * @index: Index of a node in the list
 * @next: Pointer to a next node
 * @express: Pointer toa next node in the express lane
 *
 * Description: singly linked list nodes structure with an express lane
 */
typedef struct skiplist_s
{
				int n;
				size_t index;
				struct skiplist_s *next;
				struct skiplist_s *express;
} skiplist_t;

int exponential_search(int *array, size_t size, int value);
int advanced_binary(int *array, size_t size, int value);
listint_t *jump_list(listint_t *list, size_t size, int value);
skiplist_t *linear_skip(skiplist_t *list, int value);
int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
int jump_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);

#endif
