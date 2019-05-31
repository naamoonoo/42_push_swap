/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 22:42:50 by hnam              #+#    #+#             */
/*   Updated: 2019/05/30 16:18:23 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_sort(t_stack *a, t_stack *b, int len)
{
	int			median;
	int			cnt;
	static int	call_time = 0;

	if (check_sorted(a, a->cnt))
		return ;
	cnt = 0;
	median = get_median(a, len);
	while (!check_sorted(a, a->cnt) && a->min <= median)
	{
		if (call_time && peek(a) == a->min)
			break ;
		if (peek(a) <= median)
		{
			// ft_push(a, b);
			DP(a, b, "pb");
			cnt++;
		}
		else
			// rotate(a);
			DP(a, b, "ra");
	}
	merge_sort(a, b, len, cnt, median);
	call_time += 1;
	// if (call_time == 1)
	// 	return ;

	if (!check_sorted(a, a->cnt) && a->cnt > cnt)
		split_sort(a, b, unsorted_cnt(a));
}

void	merge_sort(t_stack *a, t_stack *b, int len, int cnt, int median)
{
	// FP("merget sort started\n");
	static int	call_time = 0;
	int			i;

	i = 0;
	// FP("need to put in original order\n");
	while (call_time && len - cnt > i++)
		(dir_setting(b) && peek(b) != b->min) ?
			DP(a, b, "rrr") : DP(a, b, "rra");
		// DP(a, b, "rra");
	// FP("now it has original order\n");

	sort(a, b, dir_setting(b), cnt);
	// FP("sorting has been finished\n");
	if (check_sorted(a, a->cnt))
		return ;
	// FP("[%d]number is not yet sorted\n", cnt);
	// i = 0;
	while (peek(a) <= median)
		DP(a, b, "ra");
	while (check_sorted(a, unsorted_cnt(a)) && a->cnt > cnt)
	{
		DP(a, b, "ra");
		cnt++;
		if (check_sorted(a, a->cnt))
			return ;
	}
	// median++;
	// sorted_to_last(a, &cnt);
	// if (check_sorted(a, a->cnt))
	// 	return ;
	call_time += 1;
}

// // max and min finder
void	sort(t_stack *a, t_stack *b, int dir, int cnt)
{
	// int median;

	if (!b->cnt)
		return ;
	// median = get_median(b, cnt);
	if (peek(b) == b->max || peek(b) == b->min)
	{
		DP(a, b, "pa");
		if (b->cnt && peek(a) < b->min)
			DP(a, b, (dir && peek(b) != b->max && peek(b) != b->min)
			? "rr" : "ra");
		dir = dir_setting(b);
		cnt--;
	}
	// else if (peek(b) > median)
	// {
	// 	DP(a, b, "pa");
	// 	cnt--;
	// }
	else
		DP(a, b, dir ? "rb" : "rrb");
	sort(a, b, dir, cnt);
}


/*
** 1-> r // 0 -> rr
*/
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
	int		i;
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

void	sorted_to_last(t_stack *stk, int *cnt)
{
	int		last_sorted;
	t_node	*node;

	node = stk->top;
	while (node->next)
		node = node->next;
	last_sorted = node->data;
	node = stk->top;
	while (*cnt > 0 && node->data == 1 + last_sorted &&
		node->data < node->next->data)
	{
		last_sorted = node->data;
		DP(stk, stk, "ra");
		*cnt -= 1;
	}
	while (last_sorted + 1 == peek(stk))
	{
		last_sorted = node->data;
		DP(stk, stk, "ra");
	}
}
