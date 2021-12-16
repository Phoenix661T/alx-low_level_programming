#include "hash_tables.h"
/**
 * key_index - returns the index of a @key
 * @key: string of the key
 * @size: size of the array - hash table
 * Return: index of the key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
unsigned long int hash, index;

hash = hash_djb2(key);
index = hash % size;

return (index);
}
