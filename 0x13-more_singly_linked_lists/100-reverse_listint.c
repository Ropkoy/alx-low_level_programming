#include "lists.h"
/**
 * Definition for singly-linked list.
 * struct listint_s {
 *     int n;
 *     struct listint_s *next;
 * };
 * typedef struct listint_s listint_t;
 */

/**
 * reverse_listint - Reverses a singly linked list of integers.
 * @head: Pointer to the head node of the list.
 *
 * Return: Pointer to the new head node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
    listint_t *prev = NULL;
    listint_t *curr = *head;
    listint_t *next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;
    return *head;
}
