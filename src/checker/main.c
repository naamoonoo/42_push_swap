/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 22:57:35 by hnam              #+#    #+#             */
/*   Updated: 2019/06/04 23:33:49 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_mode(int ac, char *av[], int *visual, int *color)
{
	int i;

	i = 0;
	*visual = 0;
	*color = 0;
	while (ac > 2 && av[1][0] == '-' && av[1][++i])
	{
		if (av[1][i] == 'v')
			*visual = 1;
		else if (av[1][i] == 'c')
			*color = 1;
		else
			return (0);
	}
	return (1);
}

int		main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	int		visual;
	int		color;

	if (ac == 1)
		return (0);
	a = ft_memalloc(sizeof(t_stack));
	b = ft_memalloc(sizeof(t_stack));
	if (!initialize_stack(a, ac, av))
	{
		FP("Error : INVALID INPUT\n");
		return (0);
	}
	if (a->cnt && av[1][0] == '-' && !get_mode(ac, av, &visual, &color))
		return (0);
	if (a->cnt && !read_dispatcher(a, b, visual, color))
		return (0);
	a->cnt && is_empty(b) && check_sorted(a, a->cnt)
		? FP("OK\n") : FP("KO\n");
	free_stack(a);
	return (0);
}
