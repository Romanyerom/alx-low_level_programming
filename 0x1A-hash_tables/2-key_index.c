#include "hash_tables.h"

/**
 * key_index - Calculates the index at which a key/value pair should be stored
 * in the array of a hash table.
 * @key: The key (string) to calculate the index for.
 * @size: The size of the array in the hash table.
 *
 * Return: The index at which the key/value pair should be stored.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
    unsigned long int hash_val;

    if (key == NULL || size == 0)
        return (0);

    hash_val = hash_djb2(key);
    return (hash_val % size);
}
