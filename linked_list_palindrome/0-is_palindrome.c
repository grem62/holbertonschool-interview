#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: pointer to head of list.
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome.
 */
int is_palindrome(listint_t **head)
{
    listint_t *current;
    int i, j, n;
    int array[10000]; /* Consider using dynamic allocation if list can exceed this size */

    if (!head || !(*head)) /* Betty style recommends checking for null pointers */
        return (1); /* An empty list is considered a palindrome */

    current = *head;
    n = 0;
    while (current != NULL)
    {
        array[n] = current->n;
        current = current->next;
        n++;
    }

    for (i = 0, j = n - 1; i < j; i++, j--) /* Minor optimization: loop until i < j */
    {
        if (array[i] != array[j])
            return (0);
    }
    return (1);
}

