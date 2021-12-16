#include "hash_tables.h"
/**
 * hash_table_delete - deletes a hash table.
 * @ht: Hash table
 *
 */
void hash_table_delete(hash_table_t *ht)
{
hash_node_t *tmp = NULL, *tmp2 = NULL;
unsigned long int i = 0;

if (!ht)
return;
while (i < ht->size)
{
if (ht->array)
{
tmp = ht->array[i];
tmp2 = ht->array[i];
while (tmp)
{
tmp = tmp->next;
free(tmp2->key);
free(tmp2->value);
free(tmp2);
tmp2 = tmp;
}
}
i++;
}
free(ht->array);
free(ht);
}
