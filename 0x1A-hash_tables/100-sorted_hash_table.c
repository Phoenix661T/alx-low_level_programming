#include "hash_tables.h"
/**
 * shash_table_create - creates a hash table.
 * @size: size of the new hash table
 * Return: When success, a pointer to the new hash table, if fails NULL
 */
shash_table_t *shash_table_create(unsigned long int size)
{
shash_table_t *new_table;
unsigned long int counter;

/*Allocs memory for the hash table and validates its creation*/
new_table = malloc(sizeof(shash_table_t) * 1);
if (!new_table)
return (NULL);
/*Allocs memory for each node of the hash table and validates it*/
new_table->array = malloc(sizeof(shash_node_t *) * size);
if (!new_table->array)
return (NULL);
/*Assign size value in hash struct*/
new_table->size = size;
new_table->shead = NULL;
new_table->stail = NULL;
/*sets to NULL every node of the hash*/
for (counter = 0; counter < size; counter++)
new_table->array[counter] = NULL;

return (new_table);
}

/**
 * shash_table_set - adds an element to the hash table.
 * @ht: hash table you want to add or update the key/value to
 * @key: is the key of the new element
 * @value: value associated with the key
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
unsigned long int size, index;
shash_node_t *new_node = NULL;

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
new_node = malloc(sizeof(shash_node_t *) * 1);
if (!new_node)
return (0);
new_node->next = ht->array[index];
ht->array[index] = new_node;
new_node->key = strdup(key);
new_node->value = strdup(value);

return (1);
}

/**
 * shash_table_get - retrieves a value associated with a key.
 * @ht: hash table you want to look into
 * @key: is the key you are looking for
 * Return: The value associated with @key, or NULL if @key couldn’t be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
shash_node_t *tmp = NULL;
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

/**
 * shash_table_print - prints a hash table.
 * @ht: Hash table
 */
void shash_table_print(const shash_table_t *ht)
{
unsigned long int i = 0, j = 0;
shash_node_t *tmp = NULL;

if (!ht)
return;
putchar('{');
tmp = ht->shead;

while (tmp)
{
if (j != 0)
printf(", ");
printf("'%s': '%s'", tmp->key, tmp->value);
tmp = tmp->snext;
j++;
}
i++;
printf("}\n");
}

/*/**
 * shash_table_print_rev - print the hash tables key/value
 * pairs in reverse order
 * @ht: Hash table
 */
/*
 *void shash_table_print_rev(const shash_table_t *ht)
 *{
 *
*}
*/

/**
 * shash_table_delete - deletes a hash table.
 * @ht: Hash table
 */
void shash_table_delete(shash_table_t *ht)
{
shash_node_t *tmp = NULL, *tmp2 = NULL;
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
