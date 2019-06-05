/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:06:01 by hnam              #+#    #+#             */
/*   Updated: 2019/06/04 22:58:56 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dispatch_table(t_stack *a, t_stack *b, char *command)
{
	if (GET_COMMAND(command) == 's')
	{
		if (COMMAND_TO(command) == 's')
		{
			ps_swap(a);
			ps_swap(b);
		}
		else
			COMMAND_TO(command) == 'a' ? ps_swap(a) : ps_swap(b);
	}
	else if (GET_COMMAND(command) == 'p')
		COMMAND_TO(command) == 'a' ? ps_push(b, a) : ps_push(a, b);
	else if (GET_COMMAND(command) == 'r')
	{
		if (COMMAND_TO(command) == 'r')
		{
			REVERSE_ORDER(command) ? reverse_rotate(b) : rotate(b);
			REVERSE_ORDER(command) ? reverse_rotate(a) : rotate(a);
		}
		else if (COMMAND_TO(command) == 'a')
			command[1] == 'r' ? reverse_rotate(a) : rotate(a);
		else if (COMMAND_TO(command) == 'b')
			command[1] == 'r' ? reverse_rotate(b) : rotate(b);
	}
	FP("%s\n", command);
}

int		read_dispatcher(t_stack *a, t_stack *b, int visual, int color)
{
	char		*command;
	static int	counter = 0;

	command = NULL;
	while (get_next_line(0, &command) > 0)
	{
		if (!check_valid_command(command))
		{
			FP("Error : INVALID COMMAND[%s]\n", command);
			continue;
		}
		DP(a, b, command);
		if (visual)
		{
			system("clear");
			FP("Stack A---------------------------------------------------\n");
			show(a, color, a->cnt + b->cnt);
			FP("Stack B---------------------------------------------------\n");
			show(b, color, a->cnt + b->cnt);
		}
		ft_strdel(&command);
		counter += 1;
	}
	FP("[%d] number sorted with{blue} %d{eoc} move\n", a->cnt, counter);
	return (1);
}
