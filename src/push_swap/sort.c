/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 22:42:50 by hnam              #+#    #+#             */
/*   Updated: 2019/05/23 00:16:25 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *a, t_stack *b)
{
	static int	start = 0;
	int			times;
	int			rep;
	char		*cmd;

	if (!start++)
		DP(a, b, "pb");
	if (start && is_empty(a))
		return ;
	if (peek(a) > peek(b))
		DP(a, b, "pb");
	else
	{
		FP("peek(a) : %d\t peek(b) : %d\n", peek(a), peek(b));
		times = find_rep(a, b);
		cmd = times < 0 ? "rb" : "rrb";
		rep = ABS(times);
		FP("rep %d\n", rep);
		while (rep--)
			DP(a, b, cmd);
		DP(a, b, "pb");
		rep = ABS(times);
		while (rep--)
			DP(a, b, ft_strcmp(cmd, "rb") ? "rb" : "rrb");
	}
	if (start && !is_empty(b))
		return sort(a, b);

}

int		find_rep(t_stack *a, t_stack *b)
{
	int		a_top;
	int		rep_time;
	t_stack	*tmp;

	a_top = peek(a);
	tmp = b;
	rep_time = 0;
	if (b->count == 2)
		return (1);
	while (tmp->top && a_top < peek(tmp))
	{
		rep_time += 1;
		DP(a, tmp, "rb");
	}
	int num = rep_time;
	while (num--)
	{
		DP(a, tmp, "rrb");
	}
	if ((double)b->count / 2.0 > (double)rep_time)
		return (rep_time);
	return (rep_time * -1);
}
