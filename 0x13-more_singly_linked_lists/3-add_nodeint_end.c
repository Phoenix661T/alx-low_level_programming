#include "lists.h"
/**
 * new_node - Creates a new node for list
 * @n: number for new node
 *
 * Return: returns the new node or NULL on failure
 *
 */
listint_t *new_node(const int n)
{
listint_t *new;

new = malloc(sizeof(listint_t));
if (new == NULL)
return (NULL);
new->n = n;
return (new);
}

/**
 * last_node - return the address of the last node in a linked list
 * @head: head of linked list
 *
 * Return: returns last node address
 */
listint_t *last_node(listint_t **head)
{
listint_t *last = *head;

while (last->next != NULL)
last = last->next;
return (last);
}

/**
 * add_nodeint_end - adds a new node at the end of a linked list
 * @head: pointer to the head of the linked list
 * @n: number to add to new node
 *
 * Return: returns the address of the new element, or NULL on failure
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *new, *last;

if (head == NULL)
return (NULL);
new = new_node(n);
if (new == NULL)
return (NULL);
new->next = NULL;
if (*head == NULL)
{
*head = new;
return (*head);
}
last = last_node(head);
last->next = new;
return (new);
}
