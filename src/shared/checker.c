/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:04:38 by hnam              #+#    #+#             */
/*   Updated: 2019/06/03 17:21:20 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_sorted(t_stack *stack, int cnt)
{
	t_node	*curr;

	curr = stack->top;
	while (curr && curr->next && --cnt > 0)
	{
		if (curr->data > curr->next->data)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int		check_sorted_r(t_stack *stack, int cnt)
{
	t_node	*curr;

	curr = stack->top;
	while (curr && curr->next && --cnt > 0)
	{
		if (curr->data < curr->next->data)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int		check_valid_command(char *command)
{
	char	*cmd[12] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb",
						"rr", "rra", "rrb", "rrr", NULL};
	int		i;

	i = -1;
	while (cmd[++i])
		if (!ft_strcmp(cmd[i], command))
			return (1);
	return (0);
}
