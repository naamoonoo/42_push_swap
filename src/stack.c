/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:55:50 by hnam              #+#    #+#             */
/*   Updated: 2019/05/17 16:05:55 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->data = data;
	node->next = NULL;
	if (stack->top)
		node->next = stack->top;
	stack->top = node;
}

int		pop(t_stack *stack)
{
	int		data;
	t_node	*node;

	if (!stack->top)
		return (-1);
	node = stack->top;
	data = node->data;
	stack->top = node->next;
	free(node);
	return data;
}

void	peek(t_stack *stack)
{
	FP("%d is top/first out/last in value\n", stack->top->data);
}

int		is_empty(t_stack *stack)
{
	if (stack->top)
		return (0);
	return (1);
}

void	show(t_stack *stack)
{
	t_node	*curr;

	FP("last in == first out == top \n");
	curr = stack->top;
	while (curr)
	{
		FP("%d\n", curr->data);
		curr = curr->next;
	}
	FP("first in == last out == last\n");
}
