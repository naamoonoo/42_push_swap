/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:07:30 by hnam              #+#    #+#             */
/*   Updated: 2019/05/17 15:05:57 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack)
{
	t_node	*tmp;

	if (!(tmp = stack->top))
		return ;
	down = stack->top;
	stack->top = up;
	down->prev = up->prev;
	up->prev->next = down;
	down->next = up;
	up->prev = down;
}

void	ft_push(t_stack *from, t_stack *to)
{
	int	tmp;

	tmp = pop(from);
	push(to, tmp);
}

void	rotate(t_stack *stack)
{
	// FP("rotate!\n");

	// stack->last = stack->top;
	// stack->top = stack->top->prev;
	stack->last = stack->last->prev;
	stack->top = stack->top->prev;
}

void	reverse_rotate(t_stack *stack)
{
	// FP("reverse rotate!\n");
	stack->top = stack->top->next;
	stack->last = stack->last->next;
}

// 4 1 2 3 ->
