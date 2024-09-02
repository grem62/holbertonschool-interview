#include <stdio.h>
#include <math.h>

/**
 * struct skiplist_s - Skip list node
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 * @express: Pointer to the next node in the express lane
 *
 * Description: singly linked list node structure with an express lane
 * for Holberton project
 */
typedef struct skiplist_s
{
    int n;
    size_t index;
    struct skiplist_s *next;
    struct skiplist_s *express;
} skiplist_t;

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 *
 * @list: Pointer to the head of the skip list to search in.
 * @value: Value to search for.
 *
 * Return: Pointer to the first node where value is located,
 *         or NULL if value is not present in list or if head is NULL.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *current, *prev;

    if (list == NULL)
        return (NULL);

    current = list;
    while (current != NULL && current->n < value)
    {
        prev = current;
        if (current->express != NULL)
        {
            printf("Value checked at index [%lu] = [%d]\n",
                   current->express->index, current->express->n);
            if (current->express->n >= value)
            {
                printf("Value found between indexes [%lu] and [%lu]\n",
                       current->index, current->express->index);
                break;
            }
            current = current->express;
        }
        else
        {
            while (current->next != NULL)
                current = current->next;
            break;
        }
    }

    printf("Value found between indexes [%lu] and [%lu]\n",
           prev->index, current->index);

    while (prev != NULL && prev->index <= current->index)
    {
        printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
        if (prev->n == value)
            return (prev);
        prev = prev->next;
    }

    return (NULL);
}