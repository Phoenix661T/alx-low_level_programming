#include "hash_tables.h"
/**
 * hash_table_set - adds an element to the hash table.
 * @ht: hash table you want to add or update the key/value to
 * @key: is the key of the new element
 * @value: value associated with the key
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
unsigned long int size, index;
hash_node_t *new_node = NULL;

if (!ht || !value || !key)
return (0);

size = ht->size;
index =key_index((unsigned char *)key, size);

new_node = ht->array[index];
while (new_node)
{
if (strcmp(new_node->key, (void *)key) == 0)
{
free(new_node->value);
new_node->value = (void *)strdup(value);
return (1);
}
new_node = new_node->next;
}
new_node = malloc(sizeof(hash_node_t *) * 1);
if (!new_node)
return (0);
new_node->next = ht->array[index];
ht->array[index] = new_node;
new_node->key = strdup(key);
new_node->value = strdup(value);

return (1);
}
