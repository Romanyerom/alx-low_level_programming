#ifndef HASH_TABLES_H
#define HASH_TABLES_H

/* Standard Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Data Structures */

/**
 * struct hash_node_s - Node of a hash table
 *
 * @key: The key, string (unique in the HashTable)
 * @value: The value corresponding to a key
 * @next: A pointer to the next node in the collision chain
 */
typedef struct hash_node_s
{
    char *key;
    char *value;
    struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 *
 * @size: The size of the array (number of buckets)
 * @array: An array of pointers to the first node of linked lists
 */
typedef struct hash_table_s
{
    unsigned long int size;
    hash_node_t **array;
} hash_table_t;

/* Function Prototypes */

/* Function to create a hash table */
hash_table_t *hash_table_create(unsigned long int size);

/* Function to add an element to the hash table */
int hash_table_set(hash_table_t *ht, const char *key, const char *value);

/* Function to retrieve a value associated with a key */
char *hash_table_get(const hash_table_t *ht, const char *key);

/* Function to print the contents of the hash table */
void hash_table_print(const hash_table_t *ht);

/* Function to free memory used by the hash table */
void hash_table_delete(hash_table_t *ht);

/* Additional Function Prototypes */

/* Hashing algorithm (djb2) */
unsigned long int hash_djb2(const unsigned char *str);

/* Calculate index for a given key */
unsigned long int key_index(const unsigned char *key, unsigned long int size);

#endif /* HASH_TABLES_H */
