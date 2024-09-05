#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to the head of the list
 *
 * Return: address of the node where the loop starts,
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	/* Initialize two pointers, slow and fast, pointing to the head of the list */
	listint_t *slow = head, *fast = head;

	/* Traverse the list until the fast pointer reaches the end */
	while (fast && fast->next)
	{
		/* Move slow pointer by one step */
		slow = slow->next;
		/* Move fast pointer by two steps */
		fast = fast->next->next;

		/* If slow and fast pointers meet, there is a loop */
		if (slow == fast)
		{
			/* Move the slow pointer back to the head */
			slow = head;
			/* Move both pointers one step at a time until they meet again */
			/* This meeting point is the start of the loop */
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			/* Return the address of the node where the loop starts */
			return (slow);
		}
	}
	/* If there is no loop, return NULL */
	return (NULL);
}