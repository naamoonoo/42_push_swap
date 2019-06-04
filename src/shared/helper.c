/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 21:45:05 by hnam              #+#    #+#             */
/*   Updated: 2019/06/03 17:22:16 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	*is_exist(int *arr, int count)
{
	int	pivot;
	int l_idx;
	int	r_idx;
	int tmp;

	pivot = count / 2;
	l_idx = 1;
	r_idx = count - 1;
	while (l_idx < r_idx)
	{
		while (l_idx < count && pivot > arr[l_idx])
			l_idx++;
		while (r_idx > 1 && pivot < arr[r_idx])
			r_idx--;
		if (l_idx < r_idx)
			SWAP(arr[l_idx], arr[r_idx], tmp);
	}
	return arr;
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
		if (curr-> data < stack->min)
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
		if (curr-> data < min)
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


