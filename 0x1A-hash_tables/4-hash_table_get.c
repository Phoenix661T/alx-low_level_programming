#include "hash_tables.h"
/**
 * hash_table_get - retrieves a value associated with a key.
 * @ht: hash table you want to look into
 * @key: is the key you are looking for
 * Return: The value associated with @key, or NULL if @key couldn’t be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
hash_node_t *tmp = NULL;
unsigned long int size, index;

if (!ht || !key)
return (NULL);
size = ht->size;
index =key_index((unsigned char *)key, size);
tmp = ht->array[index];

while (tmp)
{
if (strcmp(tmp->key, (void *)key) == 0)
{
return (tmp->value);
}
tmp = tmp->next;
}
return (NULL);
}
