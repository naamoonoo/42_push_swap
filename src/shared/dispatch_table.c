/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:06:01 by hnam              #+#    #+#             */
/*   Updated: 2019/05/23 00:19:49 by hnam             ###   ########.fr       */
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
	// if (check_valid_command(command))
		FP("%s\n", command);
		show(a);
		printf("--------------\n");
		show(b);
}

int		read_dispatcher(t_stack *a, t_stack *b)
{
	char	*command;
	// int		fd;

	// fd = open("res.txt", O_RDONLY | O_CREAT);
	command = NULL;
	while(get_next_line(0, &command) > 0)
	{
		// FP("|%s|\n", command);
		if (!check_valid_command(command))
		{
			FP("Error : INVALID COMMAND\n");
			continue; // return (0);
			// do i have to quit? or just tell them put valid input
		}
		DP(a, b, command);
		// write(1, "\e[1;1H\e[2J", 12);
		system("clear");
		// system("column -c 20");
		show(a);
		printf("--------------\n");
		show(b);

		// system("column RR");
		// ststem(printf "PERM LINKS OWNER GROUP SIZE MONTH DAY " ; \
        //    printf "HH:MM/YEAR NAME\n" ; \
        //    ls -l | sed 1d) | column -t
		ft_strdel(&command);
	}
	return (1);

}
