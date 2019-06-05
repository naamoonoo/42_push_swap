/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:04:38 by hnam              #+#    #+#             */
/*   Updated: 2019/06/04 22:58:25 by hnam             ###   ########.fr       */
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
	static char	*cmd[12] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb",
						"rr", "rra", "rrb", "rrr", NULL};
	int			i;

	i = -1;
	while (cmd[++i])
		if (!ft_strcmp(cmd[i], command))
			return (1);
	return (0);
}

int		is_existed(t_stack *stack, int val)
{
	t_node	*tmp;

	if (!(tmp = stack->top))
		return (0);
	while (tmp)
	{
		if (tmp->data == val)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
