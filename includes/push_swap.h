/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:31:49 by hnam              #+#    #+#             */
/*   Updated: 2019/06/04 23:09:59 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <sys/ioctl.h>

# include "../lib/includes/ft_printf.h"
# include "../lib/includes/libft.h"

# define INVALID_INPUT -42
# define INVALID_FLAG -4242

# define GET_COMMAND(command) (command[0])
# define COMMAND_TO(command) (command[ft_strlen(command) - 1])
# define REVERSE_ORDER(cmd) ((ft_strlen(cmd) == 3) && (cmd[1] == 'r'))

# define DP	dispatch_table

typedef struct		s_node
{
	int				data;
	struct s_node	*next;
}					t_node;

typedef struct		s_stack
{
	t_node			*top;
	int				min;
	int				max;
	int				cnt;
}					t_stack;

void				push(t_stack *stack, int data);
int					pop(t_stack *stack);
int					peek(t_stack *stack);
int					is_empty(t_stack *stack);
void				show(t_stack *stack, int show, int total);

int					read_dispatcher(t_stack *a, t_stack *b,
					int visual, int color);
void				dispatch_table(t_stack *a, t_stack *b, char *command);

int					initialize_stack(t_stack *s, int ac, char *av[]);
void				ps_swap(t_stack *stack);
void				ps_push(t_stack	*from, t_stack *to);
void				reverse_rotate(t_stack *stack);
void				rotate(t_stack *stack);

void				sort_only_3(t_stack *a);
void				sort_only_5(t_stack *a, t_stack *b);

int					split_b(t_stack *a, t_stack *b, int median);
void				sort_b(t_stack *a, t_stack *b, int dir);
void				partial_b(t_stack *a, t_stack *b);
void				handle_b(t_stack *a, t_stack *b);
void				split_a(t_stack *a, t_stack *b, int len);

int					dir_setting(t_stack *stack);
int					is_existed(t_stack *stack, int val);
int					check_sorted(t_stack *stack, int cnt);
int					check_sorted_r(t_stack *stack, int cnt);

int					check_valid_command(char *command);
void				set_max_min(t_stack *stack);
int					get_median(t_stack *stack, int len);
void				visual_bar(int number, int total);
void				free_stack(t_stack *stack);

#endif
