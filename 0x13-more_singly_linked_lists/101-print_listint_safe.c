#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/* Definition for singly-linked list */
struct listint_t {
    int val;
    struct listint_t *next;
};

/* Function to print a singly-linked list */
void print_list(struct listint_t *head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

/* Driver program to test the print_list function */
int main() {
    /* Creating a sample linked list */
    struct listint_t *head = malloc(sizeof(struct listint_t));
    head->val = 1;
    head->next = malloc(sizeof(struct listint_t));
    head->next->val = 2;
    head->next->next = malloc(sizeof(struct listint_t));
    head->next->next->val = 3;
    head->next->next->next = NULL;

    /* Printing the linked list */
    print_list(head);

    /* Freeing the memory */
    free(head->next->next);
    free(head->next);
    free(head);

    return 0;
}
