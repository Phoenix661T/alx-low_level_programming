#include "hash_tables.h"
/**
 * hash_table_create - creates a hash table.
 * @size: size of the new hash table
 * Return: When success, a pointer to the new hash table, if fails NULL
 */
hash_table_t *hash_table_create(unsigned long int size)
{
hash_table_t *new_table;
unsigned long int counter;

/*Allocs memory for the hash table and validates its creation*/
new_table = malloc(sizeof(hash_table_t) * 1);
if (!new_table)
return (NULL);
/*Allocs memory for each node of the hash table and validates it*/
new_table->array = malloc(sizeof(hash_node_t *) * size);
if (!new_table->array)
return (NULL);
/*Assign size value in hash struct*/
new_table->size = size;
/*sets to NULL every node of the hash*/
for (counter = 0; counter < size; counter++)
new_table->array[counter] = NULL;

return (new_table);
}
