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
			command[1] == 'r' ? reverse_rotate(a) : rotate(a);
			command[1] == 'r' ? reverse_rotate(b) : rotate(b);
		}
		else if (COMMAND_TO(command) == 'a')
			command[1] == 'r' ? reverse_rotate(a) : rotate(a);
		else if (COMMAND_TO(command) == 'b')
			command[1] == 'r' ? reverse_rotate(b) : rotate(b);
	}
}
