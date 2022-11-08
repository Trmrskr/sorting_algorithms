#include "sort.h"

/**
 * insertion_sort - a function to sort a list using insertion sort
 * @list: the list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *cur_node = (*list)->next;
	listint_t *node_before, *node_after, *cur_iter_node, *prev_node = NULL;

	while (cur_node != NULL)
	{
		prev_node = cur_node->prev;
		/**
		 * cur_iter_node will be used inside the following while
		 * loop to prevent changing of the cur_node variable
		 */
		cur_iter_node = cur_node;
		cur_node = cur_node->next;
		while (prev_node != NULL && (cur_iter_node->n < prev_node->n))
		{
		/* The following lines swaps qualifying items in the list */
			node_before = prev_node->prev;
			node_after = cur_iter_node->next;

			prev_node->next = cur_iter_node->next;
			node_after->prev = prev_node;
			node_before->next = cur_iter_node;
			prev_node->prev = cur_iter_node;
			cur_iter_node->prev = node_before;
			cur_iter_node->next = prev_node;
			print_list(*list);

			prev_node = cur_iter_node->prev;
		}
	}
}
