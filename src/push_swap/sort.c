/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 22:42:50 by hnam              #+#    #+#             */
/*   Updated: 2019/06/04 18:29:59 by hnam             ###   ########.fr       */
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
	return cnt;
}
// 25 -> 13/12 -> 13|6 / 6
void	sort_b(t_stack *a, t_stack *b, int dir, int *cnt)
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
			*cnt -= 1;
		}
	}
	else
		DP(a, b, dir ? "rb" : "rrb");
	sort_b(a, b, dir, cnt);
}

void	handle_b(t_stack *a, t_stack *b, int cnt)
{
	int unsorted;
	int new_min;
	// static int calltime= 0;

	if (cnt == 0)
		return ;
	unsorted = b->cnt > 10 ? split_b(a, b, get_median(b, b->cnt)) : 0;
	new_min = b->max + 1;
	sort_b(a, b, dir_setting(b), &cnt);
	// printf("left cnt %d\n", cnt);

	while (peek(a) < new_min && !check_sorted(a, a->cnt))
	{
		DP(a, b, "ra");
		cnt--;
	}

	// printf("left cnt %d == %d\n", cnt, unsorted);
	// if (calltime++)
	// 	return ;
	while (unsorted-- > 0)
		DP(a, b, "pb");
	new_min = b->max + 1;
	sort_b(a, b, dir_setting(b), &cnt);
	// printf("left cnt %d\n", cnt);
	while (peek(a) < new_min && !check_sorted(a, a->cnt))
	{
		DP(a, b, "ra");
		cnt--;
	}
	if (check_sorted(a, a->cnt))
		return;
	// printf("left cnt %d == %d\n", cnt, unsorted);
	// printf("left cnt should be zero! %d\n", cnt);
	while (peek(a) != a->min)
	{
		DP(a, b, "pb");
		cnt++;
	}
	// printf("new cnt %d\n", cnt);

	return handle_b(a, b, cnt);
	// if (cnt)
	// 	handle_b(a, b, cnt);
}

void	split_a(t_stack *a, t_stack *b, int len)
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
			DP(a, b, "pb");
			cnt++;
		}
		else
			DP(a, b, "ra");
	}
	handle_b(a, b, cnt);//, median);
	call_time += 1;
	if (call_time == 1)
		return ;

	if (!check_sorted(a, a->cnt) && a->cnt > cnt)
		split_a(a, b, unsorted_cnt(a));
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
