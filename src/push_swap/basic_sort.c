/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 15:20:10 by hnam              #+#    #+#             */
/*   Updated: 2019/05/27 00:16:37 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_only_3(t_stack *a)
{
	if (check_sorted(a, a->cnt))
		return ;
	if (a->cnt == 2)
		DP(a, a, "sa");
	if (a->top->data > a->top->next->data &&
		a->top->next->data > a->top->next->next->data)
		DP(a, a, "ra");
	else if (a->top->data > a->top->next->data &&
		a->top->next->data < a->top->next->next->data)
		DP(a, a, "sa");
	else if (a->top->data < a->top->next->data &&
		a->top->next->data > a->top->next->next->data)
		DP(a, a, "rra");
	sort_only_3(a);
}

void	sort_only_5(t_stack *a, t_stack *b)
{
	if (check_sorted(a, a->cnt))
	{
		if (!is_empty(b))
			DP(a, b, "pa");
		else
			return ;
	}
	else
	{
		if (a->cnt <= 3)
			sort_only_3(a);
		else if (a->top->data == a->min)
			DP(a, b, "pb");
		else if (a->top->next->data == a->min ||
			a->top->next->next->data == a->min)
			DP(a, a, "ra");
		else
			DP(a, a, "rra");
	}
	sort_only_5(a, b);
}

void	sort_a(t_stack *a, t_stack *b, int cnt)
{
	// FP("@@@@@@@sort AAAAAAA@@@@@@@[%d]\n", cnt);
	if (check_sorted(a, cnt))
		return ;
	if (cnt == 2)
		DP(a, b, "sa");
	else if (cnt == 3 && ((a->top->data > a->top->next->data &&
		a->top->next->data > a->top->next->next->data) ||
		(a->top->data > a->top->next->data &&
		a->top->next->data < a->top->next->next->data)))
		DP(a, b, "sa");
	else if (cnt == 3 && (a->top->data < a->top->next->data &&
		a->top->next->data > a->top->next->next->data))
		{
			DP(a, b, "pb");
			DP(a, b, "sa");
			DP(a, b, "pa");
		}
	else if (cnt > 3)
		split_sort_a(a, b, cnt);
	sort_a(a, b, cnt);
}

void	sort_b(t_stack *a, t_stack *b, int cnt)
{
	// FP("@@@@@@@sort bbbbbbb@@@@@@@[%d]\n", cnt);
	if (!b->cnt || !cnt)
		return ;
	else if (b->top->data == b->max || check_sorted_r(b, cnt))
	{
		DP(a, b, "pa");
		cnt--;
	}
	// else if (b->top->data == b->min)
	// {
	// 	DP(a, b, "pa");
	// 	DP(a, b, "ra");
	// }
	else if (cnt == 2)
		DP(a, b, "sb");
	else if (cnt == 3 && ((b->top->data < b->top->next->data &&
		b->top->next->data < b->top->next->next->data) ||
		(b->top->data < b->top->next->data &&
		b->top->next->data > b->top->next->next->data)))
		DP(a, b, "sb");
	else if (cnt == 3 && (b->top->data > b->top->next->data &&
		b->top->next->data < b->top->next->next->data))
		{
			DP(a, b, "pa");
			DP(a, b, "sb");
			DP(a, b, "pb");
		}
	else if (cnt > 3)
		split_sort_b(a, b, cnt);
	sort_b(a, b, cnt);
}

void	split_sort_a(t_stack *a, t_stack *b, int len)
{
	// FP("@@@@@@@split AAAAAAA@@@@@@@[%d]\n", len);
	int median;
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	median = get_median(a, len);
	while (a->min <= median)
	{
		// curr = a->top;
		// idx = 0;
		// while (curr->data != a->min)
		// {
		// 	curr = curr->next;
		// 	idx++;
		// }
		// if(a->min == peek(a))
		// {
		// 	DP(a, b, "ra");
		// 	a->cnt -= 1;
		// }
		// else
		if (peek(a) <= median)
		{
			DP(a, b, "pb");
			cnt++;
		}
		else
			DP(a, b, "ra");
	}
	while (cnt - i++ > 0 && !check_sorted(a, a->cnt))
		DP(a, b, "rra");
	sort_a(a, b, a->cnt);
	sort_b(a, b, cnt);
}

void	split_sort_b(t_stack *a, t_stack *b, int len)
{
	// FP("@@@@@@@split bbbbbbb@@@@@@@[%d]\n", len);
	int median;
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	median = get_median(b, len);
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
	// while (cnt - i++ > 0)
	// 	DP(a, b, "rrb");
	sort_a(a, b, cnt);
	sort_b(a, b, b->cnt);
}
