/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 22:42:50 by hnam              #+#    #+#             */
/*   Updated: 2019/06/04 23:04:59 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		split_b(t_stack *a, t_stack *b, int median)
{
	int cnt;

	cnt = 0;
	while (b->max > median)
	{
		if (peek(b) > median)
		{
			DP(a, b, "pa");
			cnt++;
		}
		else
			DP(a, b, "rb");
	}
	return (cnt);
}

void	sort_b(t_stack *a, t_stack *b, int dir)
{
	if (!b->cnt)
		return ;
	if (peek(b) == b->max || peek(b) == b->min)
	{
		DP(a, b, "pa");
		dir = dir_setting(b);
		if (b->cnt && peek(a) < b->min)
		{
			DP(a, b, (dir && peek(b) != b->max && peek(b) != b->min)
			? "rr" : "ra");
		}
	}
	else
		DP(a, b, dir ? "rb" : "rrb");
	sort_b(a, b, dir);
}

void	partial_b(t_stack *a, t_stack *b)
{
	int	unsorted;
	int	new_min;

	unsorted = split_b(a, b, get_median(b, b->cnt));
	new_min = b->max + 1;
	sort_b(a, b, dir_setting(b));
	while (peek(a) < new_min && !check_sorted(a, a->cnt))
		DP(a, b, "ra");
	while (unsorted-- > 0)
		DP(a, b, "pb");
}

void	handle_b(t_stack *a, t_stack *b)
{
	int new_min;

	if (!b->cnt)
		return ;
	if (b->cnt > 7)
		partial_b(a, b);
	new_min = b->max + 1;
	sort_b(a, b, dir_setting(b));
	while (peek(a) < new_min && !check_sorted(a, a->cnt))
		DP(a, b, "ra");
	while (peek(a) != a->min)
		DP(a, b, "pb");
	handle_b(a, b);
}

void	split_a(t_stack *a, t_stack *b, int len)
{
	int			median;
	int			cnt;

	if (check_sorted(a, a->cnt))
		return ;
	cnt = 0;
	median = get_median(a, len);
	while (!check_sorted(a, a->cnt) && a->min <= median)
	{
		if (peek(a) <= median)
		{
			DP(a, b, "pb");
			cnt++;
		}
		else
			DP(a, b, "ra");
	}
	handle_b(a, b);
}
