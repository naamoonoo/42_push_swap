/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 23:04:01 by hnam              #+#    #+#             */
/*   Updated: 2019/06/04 23:04:06 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		return (0);
	a = ft_memalloc(sizeof(t_stack));
	b = ft_memalloc(sizeof(t_stack));
	if (!initialize_stack(a, ac, av))
	{
		FP("Error : INVALID INPUT\n");
		return (0);
	}
	if (check_sorted(a, a->cnt) && is_empty(b))
		return (0);
	if (a->cnt <= 5)
		sort_only_5(a, b);
	else
		split_a(a, b, a->cnt);
	free_stack(a);
	return (0);
}
