#include "lists.h"
#include <stdlib.h>

typedef struct listint_s {
    int n;
    struct listint_s *next;
} listint_t;

/**
 * add_nodeint - adds a new node at the beginning of a listint_t list.
 * @head: pointer to a pointer to the head of the list
 * @n: the value to be stored in the new node
 * Return: pointer to the new head of the list
 */
listint_t *add_nodeint(listint_t **head, int n)
{
    listint_t *new_node = malloc(sizeof(listint_t));

    if (new_node == NULL) {
        return (NULL);
    }

    new_node->n = n;
    new_node->next = *head;
    *head = new_node;

    return (*head);
}
