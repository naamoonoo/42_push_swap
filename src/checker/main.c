/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 22:57:35 by hnam              #+#    #+#             */
/*   Updated: 2019/06/04 22:57:44 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_mode(int ac, char *av[], int *mode)
{
	int i;

	i = 0;
	mode[0] = 0;
	mode[1] = 0;
	while (ac > 2 && av[1][0] == '-' && av[1][++i])
	{
		if (av[1][i] == 'v')
			mode[0] = 1;
		else if (av[1][i] == 'c')
			mode[1] = 1;
		else
			return (0);
	}
	return (1);
}

int		main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	int		mode[2];

	if (ac == 1)
		return (0);
	a = ft_memalloc(sizeof(t_stack));
	b = ft_memalloc(sizeof(t_stack));
	if (!initialize_stack(a, ac, av))
	{
		FP("Error : INVALID INPUT\n");
		return (0);
	}
	if (a->cnt)
	{
		if (av[1][0] == '-' && !get_mode(ac, av, mode))
			return (0);
		if (!read_dispatcher(a, b, mode[0], mode[1]))
			return (0);
		is_empty(b) && check_sorted(a, a->cnt) ? FP("OK\n") : FP("KO\n");
		free_stack(a);
	}
	return (0);
}
