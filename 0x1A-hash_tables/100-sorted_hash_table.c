#include "hash_tables.h"

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    shash_node_t *current, *new_node;

    if (ht == NULL || key == NULL || value == NULL)
        return (0);

    index = key_index((const unsigned char *)key, ht->size);

    current = ht->array[index];
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            free(current->value);
            current->value = strdup(value);
            return (1);
        }
        current = current->next;
    }

    new_node = malloc(sizeof(shash_node_t));
    if (new_node == NULL)
        return (0);

    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    /* Insert into sorted linked list based on ASCII value of key */

    /* Update shead and stail pointers */

    return (1);
}
