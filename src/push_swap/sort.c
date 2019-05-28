/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 22:42:50 by hnam              #+#    #+#             */
/*   Updated: 2019/05/27 23:11:11 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	split_sort(t_stack *a, t_stack *b, int len)
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
	if (check_sorted(a, a->cnt))
		return ;
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
		// FP("split ended on b side %d number will be rr\n", get_small(cnt, a->cnt));
		// FP("cnt : %d\ta->cnt : %d\t len :%d\n", cnt, a->cnt, len);
	while (call_time && len - cnt > i++)
		DP(a, b, "rra");
	sort(a, b, dir_setting(b));
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
	// if (call_time == 2)
	// 	return ;
	if (a->cnt > cnt)
		split_sort(a, b, unsorted_cnt(a));
}


void	sort(t_stack *a, t_stack *b, int dir)
{
	if (!b->cnt)
		return ;
	if (peek(b) == b->max || peek(b) == b->min)
	{
		DP(a, b, "pa");
		if (b->cnt && peek(a) < b->min)
			DP(a, b, (dir && peek(b) != b->max && peek(b) != b->min) ? "rr" : "ra");
		dir = dir_setting(b);
	}
	else
	{
		DP(a, b, dir ? "rb" : "rrb");
	}
	sort(a, b, dir);
}

// 1-> r // 0 -> rr
int		dir_setting(t_stack *stack)
{
	t_node	*node;
	int		idx;
	int		max_dir;
	int		min_dir;

	node = stack->top;
	idx = 0;
	while (node && node->data != stack->max)
	{
		idx++;
		node = node->next;
	}
	max_dir = (idx < stack->cnt / 2) ? idx : (stack->cnt - idx) * -1;
	node = stack->top;
	idx = 0;
	while (node && node->data != stack->min)
	{
		idx++;
		node = node->next;
	}
	min_dir = (idx < stack->cnt / 2) ? idx : (stack->cnt - idx) * -1;
	if (max_dir * min_dir > 0)
		return (max_dir > 0 ? 1 : 0);
	return (ABS(max_dir) < ABS(min_dir) ?
		(max_dir > 0 ? 1 : 0) : (min_dir > 0 ? 1 : 0));
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
