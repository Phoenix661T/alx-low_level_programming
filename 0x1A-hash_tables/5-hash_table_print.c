#include "hash_tables.h"
/**
 * hash_table_print - prints a hash table.
 * @ht: Hash table
 */
void hash_table_print(const hash_table_t *ht)
{
unsigned long int i = 0, j = 0;
hash_node_t *tmp = NULL;

if (!ht)
return;
putchar('{');
while (i < ht->size)
{
tmp = ht->array[i];

while (tmp)
{
if (j != 0)
printf(", ");
printf("'%s': '%s'", tmp->key, tmp->value);
tmp = tmp->next;
j++;
}
i++;
}
printf("}\n");

}
