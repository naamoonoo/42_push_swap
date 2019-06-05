/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:07:30 by hnam              #+#    #+#             */
/*   Updated: 2019/06/04 23:01:11 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		initialize_stack(t_stack *s, int ac, char *av[])
{
	long	tmp;
	int		count;
	char	**tmps;

	tmp = 0;
	tmps = (ac == 2 && ft_strchr(av[1], ' ')) ? ft_strsplit(av[1], ' ') : av;
	if (ac-- == 2 && ft_strchr(av[1], ' '))
		while (tmps[tmp])
			ac = ++tmp - 1;
	count = tmp ? ac + 1 : ac;
	while (count--)
	{
		if (ac == 1 && tmps[ac][0] == '-')
			break ;
		if ((!(tmp = ft_atol(tmps[ac])) && ft_strcmp(tmps[ac], "0")) ||
			tmp > INT_MAX || tmp < INT_MIN || is_existed(s, tmp))
			return (0);
		push(s, tmp);
		ac--;
	}
	return (1);
}

void	ps_swap(t_stack *stack)
{
	t_node	*tmp;

	if (!(tmp = stack->top) || !tmp->next)
		return ;
	stack->top = tmp->next;
	tmp->next = stack->top->next;
	stack->top->next = tmp;
}

void	ps_push(t_stack *from, t_stack *to)
{
	int	tmp;

	if ((tmp = pop(from)) == INT_MIN)
		return ;
	push(to, tmp);
}

void	rotate(t_stack *stack)
{
	int		tmp;
	t_node	*top;
	t_node	*new;

	if (!stack->top || !stack->top->next)
		return ;
	tmp = pop(stack);
	top = stack->top;
	while (top->next)
		top = top->next;
	new = (t_node *)malloc(sizeof(t_node));
	new->data = tmp;
	new->next = NULL;
	top->next = new;
	if (new->data > stack->max)
		stack->max = new->data;
	if (new->data < stack->min)
		stack->min = new->data;
	stack->cnt++;
}

void	reverse_rotate(t_stack *stack)
{
	int		tmp;
	t_node	*last;

	if (!stack->top || !stack->top->next)
		return ;
	last = stack->top;
	while (last->next)
		last = last->next;
	tmp = last->data;
	last = stack->top;
	while (last->next->data != tmp)
		last = last->next;
	free(last->next);
	last->next = NULL;
	stack->cnt--;
	push(stack, tmp);
}
