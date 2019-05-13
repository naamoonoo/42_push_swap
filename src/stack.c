#include "push_swap.h"

/*
	working as stack, but It is circular queue
*/

void	push(t_stack *stack, int data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->data = data;
	if (!stack->count)
	{
		node->next = node;
		node->prev = node;
		stack->top = node;
		stack->last = node;
	}
	else
	{
		node->prev = stack->top;
		node->next = stack->last;
		stack->top = node;
		stack->last->prev = node;
	}
	stack->count += 1;
}

int		pop(t_stack *stack)
{
	t_node *curr;
	int		data;

	if (!stack->top)
	{
		FP("stack underflow\n");
		return INT_MIN;
	}
	curr = stack->top;
	data = curr->data;

	stack->top = curr->prev;

	// circular
	stack->last->prev = curr->prev;
	curr->prev->next = stack->last;

	free(curr);
	stack->count -= 1;
	return (data);
}

void	top(t_stack *stack)
{
	FP("%d is top/first out/last in value\n", stack->top->data);
}

int		is_empty(t_stack *stack)
{
	return (stack->count == 0);
}

void	show(t_stack *stack)
{
	int limit;
	FP("last in == first out == top \n");

	limit = stack->count;
	while (limit--)
	{
		FP("%d\n",stack->top->data);
		stack->top = stack->top->prev;
	}
	FP("first in == last out == last\n");
}

