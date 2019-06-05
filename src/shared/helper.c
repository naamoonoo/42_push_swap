/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 21:45:05 by hnam              #+#    #+#             */
/*   Updated: 2019/06/04 23:19:58 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		dir_setting(t_stack *stack)
{
	t_node	*node;
	int		idx;
	int		max_dir;
	int		min_dir;

	node = stack->top;
	idx = 0;
	while (node && node->data != stack->max && ++idx)
		node = node->next;
	max_dir = (idx < stack->cnt / 2) ? idx : (stack->cnt - idx) * -1;
	node = stack->top;
	idx = 0;
	while (node && node->data != stack->min && ++idx)
		node = node->next;
	min_dir = (idx < stack->cnt / 2) ? idx : (stack->cnt - idx) * -1;
	if (max_dir * min_dir > 0)
		return (max_dir > 0 ? 1 : 0);
	else if (ABS(max_dir) < ABS(min_dir))
		return (max_dir > 0 ? 1 : 0);
	return (min_dir > 0 ? 1 : 0);
}

void	set_max_min(t_stack *stack)
{
	int		limit;
	t_node	*curr;

	curr = stack->top;
	limit = stack->cnt;
	while (limit-- > 0)
	{
		if (curr->data > stack->max)
			stack->max = curr->data;
		if (curr->data < stack->min)
			stack->min = curr->data;
		curr = curr->next;
	}
}

int		get_median(t_stack *stack, int len)
{
	t_node	*curr;
	int		max;
	int		min;

	curr = stack->top;
	max = INT_MIN;
	min = INT_MAX;
	while (len-- > 0)
	{
		if (curr->data > max)
			max = curr->data;
		if (curr->data < min)
			min = curr->data;
		curr = curr->next;
	}
	return ((max + min) / 2);
}

void	visual_bar(int number, int total)
{
	FP("%4d\t\033[48;2;%d;90;%dm",
	number, 255 - 255 / total * number, 255 / total * number);
	while (number--)
		FP(" ");
	FP("\033[0m\n");
}

void	free_stack(t_stack *stack)
{
	t_node	*curr;
	t_node	*tmp;

	curr = stack->top;
	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
		tmp = NULL;
	}
	free(stack);
}
