/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:55:50 by hnam              #+#    #+#             */
/*   Updated: 2019/05/26 21:59:37 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->data = data;
	node->next = NULL;
	if (!stack->top)
	{
		stack->max = data;
		stack->min = data;
	}
	else
		node->next = stack->top;
	stack->top = node;
	if (data > stack->max)
		stack->max = data;
	if (data < stack->min)
		stack->min = data;
	stack->cnt += 1;
}

int		pop(t_stack *stack)
{
	int		data;
	t_node	*node;

	if (!stack->top)
		return (INT_MIN);
	node = stack->top;
	data = node->data;
	stack->top = node->next;
	free(node);
	stack->cnt -= 1;
	if (data == stack->min)
		stack->min = stack->top ? stack->top->data : INT_MAX;
	if (data == stack->max)
		stack->max = stack->top ? stack->top->data : INT_MIN;
	set_max_min(stack);
	return data;
}

int		peek(t_stack *stack)
{
	// FP("%d is top/first out/last in value\n", stack->top->data);
	if (stack->top)
		return stack->top->data;
	return (INT_MIN);
}

int		is_empty(t_stack *stack)
{
	if (stack->top)
		return (0);
	return (1);
}

void	show(t_stack *stack, int show, int total)
{
	t_node	*curr;

	// FP("last in == first out == top \n");
	if (!(curr = stack->top))
		return ;
	// FP("max : %d\t min : %d\t count : %d\n", stack->max, stack->min, stack->cnt);
	while (curr)
	{
		show ?
			visual_bar(curr->data, total)
			: FP("%d\n", curr->data);
		curr = curr->next;
	}
	// FP("first in == last out == last\n");
}
