/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 21:45:05 by hnam              #+#    #+#             */
/*   Updated: 2019/05/24 02:57:07 by hnam             ###   ########.fr       */
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

void	set_max_min(t_stack *stack)
{
	int		limit;
	t_node	*curr;

	curr = stack->top;
	limit = stack->count;
	while (limit--)
	{
		if (curr->data > stack->max)
			stack->max = curr->data;
		if (curr-> data < stack->min)
			stack->min = curr->data;
		curr = curr->next;
	}
	// FP("max : %d\t min :%d\n", stack->max, stack->min);
}
