/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:06:01 by hnam              #+#    #+#             */
/*   Updated: 2019/05/13 12:06:12 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dispatch_table(t_stack *a, t_stack *b, char *command)
{
	if (GET_COMMAND(command) == 's')
	{
		if (COMMAND_TO(command) == 's')
		{
			ft_swap(a);
			ft_swap(b);
		}
		else
			COMMAND_TO(command) == 'a' ? ft_swap(a) : ft_swap(b);
	}
	else if (GET_COMMAND(command) == 'p')
		COMMAND_TO(command) == 'a' ? ft_push(b, a) : ft_push(a, b);
	if (GET_COMMAND(command) == 'r')
	{
		if (COMMAND_TO(command) == 's')
		{
			REVERSE_ORDER(command) ? reverse_rotate(b) : rotate(b);
			REVERSE_ORDER(command) ? reverse_rotate(a) : rotate(a);
		}
		else if (COMMAND_TO(command) == 'a')
			command[1] == 'r' ? reverse_rotate(a) : rotate(a);
		else if (COMMAND_TO(command) == 'b')
			command[1] == 'r' ? reverse_rotate(b) : rotate(b);
	}
}
