/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 22:42:50 by hnam              #+#    #+#             */
/*   Updated: 2019/05/24 15:20:19 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_stack(t_stack *a, t_stack *b)
{
	int median;
	int	cnt;

	cnt = 0;
	median = (a->max + a->min) / 2;
	while (a->min < median)
	{
		if (peek(a) <= median)
		{
			DP(a, b, "pb");
			cnt++;
		}
		else
			DP(a, b, "ra");
	}
	// sort_b(a, b, cnt);
}

void	sort_b(t_stack *a, t_stack *b, int cnt)
{
	if (b->top->data == b->max)
		DP(a, b, "pa");
	cnt++;
}

void	sort(t_stack *a, t_stack *b)
{
	if (check_sorted(a) && is_empty(b))
		return ;
	if (a->count <= 5 && !is_empty(b))
	{

		return sort_a_5(a, b);
		// system("clear");
		// show(a);
		// printf("--------------\n");
		// show(b);

		// return ;
	}
	if (a->count == 3 && is_empty(b))
		return sort_a_3(a);
	if (a->count <= 5 && is_empty(b))
		return sort_a_5(a, b);
	if (a->count > 5)
		split_stack(a, b);
	sort(a, b);
}

// int		find_rep(t_stack *a, t_stack *b)
// {
// 	int		a_top;
// 	int		rep_time;
// 	t_node	*tmp;

// 	a_top = peek(a);
// 	tmp = b->top;
// 	rep_time = 0;
// 	if (b->count == 2)
// 		return (1);
// 	while (tmp && a_top < tmp->data)
// 	{
// 		rep_time += 1;
// 		tmp = tmp->next;
// 	}
// 	if ((double)b->count / 2.0 > (double)rep_time)
// 		return (rep_time);
// 	return (rep_time * -1);
// }
