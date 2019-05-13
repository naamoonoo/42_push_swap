#include "push_swap.h"

void	ft_swap(t_stack *stack)
{
	t_node	*down;
	t_node	*up;

	if (!(up = stack->top->prev))
		return ;
	down = stack->top;

	stack->top = up;

	down->prev = up->prev;
	up->prev->next = down;
	down->next = up;
	up->prev = down;
}

void	ft_push(t_stack	*from, t_stack *to)
{
	int	tmp;

	tmp = pop(from);
	push(to, tmp);
}

void	rotate(t_stack *stack)
{
	stack->last = stack->top;
	stack->top = stack->top->prev;
}

void	reverse_rotate(t_stack *stack)
{
	stack->top = stack->last;
	stack->last = stack->last->next;
}
