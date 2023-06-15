#include "lists.h"

/**
 * free_listint_safe - frees a linked list
 * @g: pointer to the first node in the linked list
 *
 * Return: number of elements in the freed list
 */

size_t free_listint_safe(listint_t **g)
{
	size_t len = 0;
	int diff;
	listint_t *temp;

	if (!g || !*g)
		return (0);

	while (*g)
	{
		diff = *g - (*g)->next;
		if (diff > 0)
		{
			temp = (*g)->next;
			free(*g);
			*g = temp;
			len++;
		}
		else
		{
			free(*g);
			*g = NULL;
			len++;
			break;
		}
	}

	*g = NULL;

	return (len);
}
