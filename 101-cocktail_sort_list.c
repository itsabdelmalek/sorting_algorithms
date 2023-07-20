#include "sort.h"

void swaps_node_front(listint_t **list, listint_t **tail, listint_t **shake);
void swaps_node_back(listint_t **list, listint_t **tail, listint_t **shake);
void cocktail_sort_list(listint_t **list);

/**
 * swaps_node_front - Swap a node in a linked list with the node in front.
 * @list: A pointer to the head of the list.
 * @tail: A pointer to the tail of the the list.
 * @shake: A pointer to the current swapping node of the cocktail shake.
 *
 * Return: void
 */
void swaps_node_front(listint_t **list, listint_t **tail, listint_t **shake)
{
	listint_t *tmp = (*shake)->next;

	if ((*shake)->prev != NULL)
		(*shake)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*shake)->prev;
	(*shake)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *shake;
	else
		*tail = *shake;
	(*shake)->prev = tmp;
	tmp->next = *shake;
	*shake = tmp;
}

/**
 * swaps_node_back - Swap a node in a linked with the node in the back.
 * @list: A pointer to the head of the list.
 * @tail: A pointer to the tail of the list.
 * @shake: A pointer to the current swapping node of the cocktail shake.
 *
 * Return: void
 */
void swaps_node_back(listint_t **list, listint_t **tail, listint_t **shake)
{
	listint_t *tmp = (*shake)->prev;

	if ((*shake)->next != NULL)
		(*shake)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*shake)->next;
	(*shake)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shake;
	else
		*list = *shake;
	(*shake)->next = tmp;
	tmp->prev = *shake;
	*shake = tmp;
}

/**
 * cocktail_sort_list - Sorts a linked list of integers in ascending order
 * @list: A pointer to the head of a listint_t doubly-linked list.
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shake;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shake = *list; shake != tail; shake = shake->next)
		{
			if (shake->n > shake->next->n)
			{
				swaps_node_front(list, &tail, &shake);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (shake = shake->prev; shake != *list;
				shake = shake->prev)
		{
			if (shake->n < shake->prev->n)
			{
				swaps_node_back(list, &tail, &shake);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
