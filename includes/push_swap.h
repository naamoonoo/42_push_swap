/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:31:49 by hnam              #+#    #+#             */
/*   Updated: 2019/05/17 15:44:03 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>

# include "../lib/includes/ft_printf.h"
# include "../lib/includes/libft.h"

# define INVALID_INPUT -42
# define INVALID_FLAG -4242

# define GET_COMMAND(command) (command[0])
# define COMMAND_TO(command) (command[ft_strlen(command) - 1])
# define REVERSE_ORDER(command) ((ft_strlen(command) == 3) && (command[1] == 'r'))

# define DP	dispatch_table

typedef struct			s_node
{
	int					data;
	struct s_node		*next;
	// struct s_node		*prev;
}						t_node;

typedef struct			s_stack
{
	t_node				*top;
	// t_node				*last;
	// int					count;
}						t_stack;

void					push(t_stack *stack, int data);
int						pop(t_stack *stack);
void					show(t_stack *stack);
void					peek(t_stack *stack);
int						is_empty(t_stack *stack);

void					dispatch_table(t_stack *a, t_stack *b, char *command);

void					ft_swap(t_stack *stack);
void					ft_push(t_stack	*from, t_stack *to);
void					reverse_rotate(t_stack *stack);
void					rotate(t_stack *stack);


void					error_alert(int type);
void					error_exit(int type);



int						check_sorted(t_stack *a, t_stack *b);


#endif
