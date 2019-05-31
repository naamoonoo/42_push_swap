// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   sort.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2019/05/22 22:42:50 by hnam              #+#    #+#             */
// /*   Updated: 2019/05/29 00:50:16 by hnam             ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "push_swap.h"

// void	split_sort(t_stack *a, t_stack *b, int len)
// {
// 	FP("split with %d number\n", len);
// 	int			median;
// 	int			cnt;
// 	static int	call_time = 0;

// 	cnt = 0;
// 	median = get_median(a, len);
// 	while (!check_sorted(a, a->cnt) && a->min <= median)
// 	{
// 		if (call_time && peek(a) == a->min)
// 			break ;
// 		if (peek(a) <= median)
// 		{
// 			DP(a, b, "pb");
// 			cnt++;
// 		}
// 		else
// 			DP(a, b, "ra");
// 	}
// 	if (!merge_sort(a, b, len, cnt))
// 		return ;

// 	FP("[%d]number is not yet sorted\n", cnt);
// 	call_time += 1;
// 	// if (call_time == 2)
// 	// 	return ;
// 	if (!check_sorted(a, a->cnt))
// 		split_sort(a, b, unsorted_cnt(a));
// }

// int		merge_sort(t_stack *a, t_stack *b, int len, int cnt)
// {
// 	FP("merget sort started\n");
// 	static int	call_time = 0;
// 	int			i;

// 	if(!cnt)
// 		return (1);
// 	i = 0;
// 	FP("need to put in original order\n");
// 	while (call_time && len - cnt > i++)
// 		DP(a, b, (dir_setting(b) && peek(b) != b->min) ? "rrr" : "rra");
// 	FP("now it has original order\n");
// 	sort(a, b, dir_setting(b), &cnt);
// 	sorted_to_last(a, &cnt);
// 	if (check_sorted(a, a->cnt))
// 		return (0);
// 	if (cnt <= 3)
// 		sort_a(a, b, cnt);
// 	else
// 		split_sort(a, b, cnt);
// 	call_time += 1;
// 	return (1);
// 	// // FP("sorting has been finished\n");
// 	// // if (check_sorted(a, a->cnt))
// 	// // 	return (0);

// 	// // FP("a->cnt - i = %d\t[%d]number is not yet sorted\n", a->cnt - i, cnt);
// 	// // // i = 0;
// 	// // while (peek(a) <= median)
// 	// // 	DP(a, b, "ra");
// 	// while (check_sorted(a, unsorted_cnt(a)) && a->cnt > cnt)
// 	// {
// 	// 	DP(a, b, "ra");
// 	// 	cnt++;
// 	// 	if (check_sorted(a, a->cnt))
// 	// 		return ;
// 	// }

// }

// int		unsorted_cnt(t_stack *a)
// {
// 	int		i;
// 	t_node	*curr;

// 	if (!(curr = a->top))
// 		return (0);
// 	i = 0;
// 	while (curr && curr->data != a->min)
// 	{
// 		curr = curr->next;
// 		i++;
// 	}
// 	return (i);
// }


// void	sort(t_stack *a, t_stack *b, int dir, int *cnt)
// {
// 	FP("actual sorting is in progress with [%d] number\n", *cnt);
// 	int median;

// 	if (!b->cnt && *cnt && !check_sorted(a, *cnt))
// 	{
// 		FP("no b, cnt[%d] left and amount of cnt is not yet sorted\n", *cnt);
// 		return split_sort(a, b, *cnt);
// 	}
// 	else if (!b->cnt && !*cnt)
// 		return ;
// 	median = get_median(b, b->cnt);
// 	if (peek(b) == b->min)
// 	{
// 		DP(a, b, "pa");
// 		dir = dir_setting(b);

// 		if ((b->cnt && peek(a) < b->min) || (!b->cnt && peek(a) == a->min))
// 		{
// 			DP(a, b, (dir && peek(b) != b->min) ? "rr" : "ra");
// 			*cnt -= 1;
// 		}
// 	}
// 	else if (peek(b) > median)
// 	{
// 		DP(a, b, "pa");
// 		dir = dir_setting(b);
// 	}
// 	else
// 		DP(a, b, dir ? "rb" : "rrb");
// 	// sort(a, b, dir, cnt);
// 	b->cnt ? sort(a, b, dir, cnt) : 0;
// }

// // min finder
// int		dir_setting(t_stack *stack)
// {
// 	t_node	*node;
// 	int		idx;

// 	node = stack->top;
// 	idx = 0;
// 	while (node && node->data != stack->min)
// 	{
// 		idx++;
// 		node = node->next;
// 	}
// 	FP("idx : %d\t stack->cnt %d\n", idx, stack->cnt);
// 	return (idx < stack->cnt / 2);
// }

// void	sorted_to_last(t_stack *stk, int *cnt)
// {
// 	int		last_sorted;
// 	t_node	*node;

// 	node = stk->top;
// 	while (node->next)
// 		node = node->next;
// 	last_sorted = node->data;
// 	node = stk->top;
// 	while (*cnt > 0 && node->data == 1 + last_sorted &&
// 		node->data < node->next->data)
// 	{
// 		last_sorted = node->data;
// 		DP(stk, stk, "ra");
// 		*cnt -= 1;
// 	}
// 	while (last_sorted + 1 == peek(stk))
// 	{
// 		last_sorted = node->data;
// 		DP(stk, stk, "ra");
// 	}
// }
