#include "sort.h"

/**
 * swap_list_node - swap items in a list
 * @node1: the first node in the list to be swapped with second
 * @node2: the second node to be swapped with the first
 */

void swap_list_node(listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	if (node2->next)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * insertion_sort_list - a function to sort a list using insertion sort
 * @list: the list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *cur_node, *cur_iter_node;

	if (!list || !*list || !(*list)->next)
		return;
	cur_node = (*list)->next;

	while (cur_node != NULL)
	{
		/**
		 * cur_iter_node will be used inside the following while
		 * loop to prevent changing of the cur_node variable
		 */
		cur_iter_node = cur_node;
		cur_node = cur_node->next;
		while (cur_iter_node && cur_iter_node->prev)
		{
		/* The following lines swaps qualifying items in the list */
			if (cur_iter_node->prev->n > cur_iter_node->n)
			{
				swap_list_node(cur_iter_node->prev, cur_iter_node);
				if (!cur_iter_node->prev)
					*list = cur_iter_node;
				print_list(*list);
			}
			else
				cur_iter_node = cur_iter_node->prev;
		}
	}
}
