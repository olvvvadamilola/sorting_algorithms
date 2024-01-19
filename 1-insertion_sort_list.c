#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the insertion sort algorithm
 * @list: The doubly linked list to be sorted
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *c_node, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		c_node = current;

		while (c_node->prev != NULL && c_node->n < c_node->prev->n)
		{
			/* Swap nodes */
			temp = c_node->prev;
			temp->next = c_node->next;
			if (c_node->next != NULL)
				c_node->next->prev = temp;
			c_node->prev = temp->prev;
			c_node->next = temp;
			temp->prev = c_node;

			if (c_node->prev != NULL)
				c_node->prev->next = c_node;
			else
				*list = c_node;

			/* Print the list after each swap */
			print_list(*list);
		}

		current = current->next;
	}
}
