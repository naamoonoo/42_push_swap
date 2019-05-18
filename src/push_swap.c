/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:07:30 by hnam              #+#    #+#             */
/*   Updated: 2019/05/17 16:36:34 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack)
{
	t_node	*tmp;

	if (!(tmp = stack->top) || !tmp->next)
		return ;
	stack->top = tmp->next;
	tmp->next = stack->top->next;
	stack->top->next = tmp;
}

void	ft_push(t_stack *from, t_stack *to)
{
	int	tmp;

	tmp = pop(from);
	push(to, tmp);
}

void	rotate(t_stack *stack)
{
	int 	tmp;
	t_node	*top;
	t_node	*new;

	tmp = pop(stack);
	top = stack->top;
	while (top->next)
		top = top->next;
	new = (t_node *)malloc(sizeof(t_node));
	new->data = tmp;
	new->next = NULL;
	top->next = new;
}

void	reverse_rotate(t_stack *stack)
{
	int 	tmp;
	t_node	*last;

	last = stack->top;
	while (last->next)
		last = last->next;
	tmp = last->data;
	last = stack->top;
	while (last->next->data != tmp)
		last = last->next;
	free(last->next);
	last->next = NULL;
	push(stack, tmp);
}
