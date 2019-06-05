/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 17:20:58 by hnam              #+#    #+#             */
/*   Updated: 2019/06/04 18:32:30 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		initialize_stack(t_stack *s, int ac, char *av[])
{
	int		tmp;
	int		count;
	char	**tmps;
	// int		*sets;

	tmp = 0;
	tmps = (ac == 2 && ft_strchr(av[1], ' ')) ? ft_strsplit(av[1], ' ') : av;
	if (ac-- == 2 && ft_strchr(av[1], ' '))
		while (tmps[tmp])
			ac = ++tmp - 1;
	count = tmp ? ac + 1 : ac;
	// if (!(sets = validation(tmps, count, ac)))
	// 	return (0);

	// int i = 1;
	// while (i <= count)
	// {
	// 	// push(s, sets[i]);

	// 	FP("new arr[%d]\t%d\n", i, sets[i]);
	// 	i++;
	// }
	// tmp = -1;
	// while (++tmp < count)
	while (count--)
	{
		if ((!(tmp = ft_atol(tmps[ac])) && ft_strcmp(tmps[ac], "0")) ||
			tmp > INT_MAX || tmp < INT_MIN || is_existed(s, tmp))
			return (0);
		push(s, tmp);
		ac--;

		// tmp = sets[i];
		// FP("sets[%d]\t%d\n", ac, sets[ac]);
		// if (is_existed(s, sets[ac]))
		// 	return (0);
		// push(s, sets[ac--]);
	}
	// int i = 0;
	// while (i < count)
	// {
	// 	// push(s, sets[i]);

	// 	FP("new arr[%d]\t%d\n", i, sets[i]);
	// 	i++;
	// }
	// s->cnt +=1;
	// return (0);
	return (1);
}

int		*validation(char **sets, int count, int ac)
{
	int	*arr;
	int	tmp;

	arr = ft_memalloc(ac);
	tmp = ac;
	while (count--)
	{
		if ((!(arr[ac] = ft_atol(sets[ac]))
			&& ft_strcmp(sets[ac], "0")) ||
			arr[ac] > INT_MAX || arr[ac] < INT_MIN)
			return (NULL);
		ac--;
	}
	return (is_exist(arr, tmp));
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
