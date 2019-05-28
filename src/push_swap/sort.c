/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 22:42:50 by hnam              #+#    #+#             */
/*   Updated: 2019/05/27 20:47:23 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	sort(t_stack *a, t_stack *b, int total)
// {
	// FP("@@@@@@@default sort##########\n");

// 	if (check_sorted(a, total))
// 		return ;
// 	else
// 	{
// 		if (total == a->cnt && total < 5)
// 			sort_only_5(a, b);
// 		else
// 			split_sort_a(a, b, a->cnt, last);
// 	}
// 	// sort(a, b, total);
// }

int		find_rep(t_stack *stack)
{
	t_node	*node;
	int		idx;

	if (!(node = stack->top))
		return (0);
	idx = 0;
	while (node->data != stack->max)
	{
		idx++;
		node = node->next;
	}
	if (stack->cnt - idx > stack->cnt / 2)
		return (1);
	return (0);
}

void	split_sort_a(t_stack *a, t_stack *b, int len)
{
	// FP("@@@@@@split number with [%d]@@@@@\n", len);
	int			median;
	int			cnt;
	int			i;
	static int	call_time = 0;

	// while (check_sorted(a, len) && len--)
	// 	DP(a, b, "ra");
	if (check_sorted(a, a->cnt))
		return ;
	if (len <= 3)
		sort_a(a, b, len);
	cnt = 0;
	median = get_median(a, len);

	while (a->min <= median)
	{
		if (call_time && peek(a) == a->min)
			break;
		if (peek(a) <= median)
		{
			DP(a, b, "pb");
			cnt++;
		}
		else
		{
			// FP("finding less than median\n");
			DP(a, b, "ra");
		}
	}
	i = 0;
		FP("split ended on b side %d number will be rr\n", get_small(cnt, a->cnt));
		// FP("cnt : %d\ta->cnt : %d\t len :%d\n", cnt, a->cnt, len);
	while (call_time && len - cnt > i++)
		DP(a, b, "rra");
	sort_b(a, b, find_rep(b), 0);
	if (check_sorted(a, a->cnt))
		return ;
	while (peek(a) <= median)
	{
		// FP("after sort b\n");
		DP(a, b, "ra");
	}
	while (check_sorted(a, unsorted_cnt(a)) && a->cnt > cnt)
	{
		// FP("can be sorted\n");
		DP(a, b, "ra");
		cnt++;
		if (check_sorted(a, a->cnt))
			return ;
	}
	call_time += 1;
	if (call_time == 2)
		return ;
	if (a->cnt > cnt)
		split_sort_a(a, b, unsorted_cnt(a));
}


void	sort_b(t_stack *a, t_stack *b, int dir, int is_pushed)
{
	if (!b->cnt)
		return ;
// if (is_pushed && peek(a) < b->min && b->cnt)
// 	{

// 		// !check_sorted(a, a->cnt) ? DP(a, b, dir ? "rr" : "ra") : 0;
// 		DP(a, b, !dir ? "rr" : "ra");
// 		is_pushed = 0;
// 	}
// 	else
	if (peek(b) == b->max)
	{
		DP(a, b, "pa");
		is_pushed = 1;
		dir = find_rep(b);
		// peek(a) > b->max ? (dir = find_rep(b)) : 0;
	}
	else
	{
		if (is_pushed && peek(a) < b->min && b->cnt)
		{

			// !check_sorted(a, a->cnt) ? DP(a, b, dir ? "rr" : "ra") : 0;
			DP(a, b, !dir ? "rr" : "ra");
			is_pushed = 0;
		}
		else
			DP(a, b, dir ? "rb" : "rrb");
	}
	sort_b(a, b, dir, is_pushed);
}

int		unsorted_cnt(t_stack *a)
{
	int 	i;
	t_node	*curr;

	if (!(curr = a->top))
		return (0);
	i = 0;
	while (curr && curr->data != a->min)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}
