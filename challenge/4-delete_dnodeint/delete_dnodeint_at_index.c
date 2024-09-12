#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a doubly linked list
 * @index: The index of the node to delete (starting from 0)
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current;
    unsigned int p;

    /* If the list is empty, return failure */
    if (*head == NULL)
        return (-1);

    current = *head;
    p = 0;

    /* Traverse to the node at the specified index */
    while (p < index && current != NULL)
    {
        current = current->next;
        p++;
    }

    /* If the index is out of bounds, return failure */
    if (current == NULL)
        return (-1);

    /* Deleting the head (first node) */
    if (index == 0)
    {
        *head = current->next;
        if (*head != NULL)  /* If there is a next node, update its prev pointer */
            (*head)->prev = NULL;
    }
    else
    {
        /* Update the previous node's next pointer */
        if (current->prev != NULL)
            current->prev->next = current->next;

        /* Update the next node's prev pointer if it's not the last node */
        if (current->next != NULL)
            current->next->prev = current->prev;
    }

    /* Free the memory of the node to be deleted */
    free(current);
    return (1);
}

