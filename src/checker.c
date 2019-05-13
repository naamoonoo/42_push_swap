#include "push_swap.h"

int		check_sorted(t_stack *a, t_stack *b)
{
	int limit;
	t_node *curr;

	limit = a->count;
	if (b->count && !limit)
		return (0);
	curr = a->top;
	while (--limit)
	{
		if (curr->data > curr->prev->data)
			return (0);
		curr = curr->prev;
	}
	return (1);
}


