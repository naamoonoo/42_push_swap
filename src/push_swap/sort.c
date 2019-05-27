/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 22:42:50 by hnam              #+#    #+#             */
/*   Updated: 2019/05/26 23:58:21 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	split_stack(t_stack *a, t_stack *b)
// {
// 	int median;
// 	int	cnt;

// 	cnt = 0;
// 	median = (a->max + a->min) / 2;
// 	while (a->min < median)
// 	{
// 		if (peek(a) <= median)
// 		{
// 			DP(a, b, "pb");
// 			cnt++;
// 		}
// 		else
// 			DP(a, b, "ra");
// 	}
// 	// sort_b(a, b, cnt);
// }



void	sort(t_stack *a, t_stack *b, int total)
{
	if (check_sorted(a, total))
	{
		if (!is_empty(b))// && check_sorted_r(b, total - a->cnt))
			DP(a, b, "pa");
		else
			return ;
	}
	else
	{
		if (total == a->cnt && total < 5)
			sort_only_5(a, b);
		// else if (a->cnt <= 3)
		else
			sort_a(a, b, a->cnt);
	}
	sort(a, b, total);
}

// int		find_rep(t_stack *a, t_stack *b)
// {
// 	int		a_top;
// 	int		rep_time;
// 	t_node	*tmp;

// 	a_top = peek(a);
// 	tmp = b->top;
// 	rep_time = 0;
// 	if (b->cnt == 2)
// 		return (1);
// 	while (tmp && a_top < tmp->data)
// 	{
// 		rep_time += 1;
// 		tmp = tmp->next;
// 	}
// 	if ((double)b->cnt / 2.0 > (double)rep_time)
// 		return (rep_time);
// 	return (rep_time * -1);
// }
