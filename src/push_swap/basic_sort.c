/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 15:20:10 by hnam              #+#    #+#             */
/*   Updated: 2019/06/03 17:28:43 by hnam             ###   ########.fr       */
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
	if (check_sorted(a, cnt))
	{
		while (--cnt > 0)
			DP(a, b, "ra");
		return ;
	}
	else if (!cnt)
		return ;
	else if (cnt == 1)
		return DP(a, b, "ra");
	else if (cnt == 2)
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
	sort_a(a, b, cnt);
}




// 1
// void	sort(t_stack *a, t_stack *b, int dir)
// {
// 	// FP("@@@@@@@sort bbbbbbb@@@@@@@[%d]\n", cnt);
// 	// int is_pushed;

// 	// is_pushed = 0;
// 	if (!b->cnt)
// 		return ;
// 	if (peek(b) == b->max || peek(b) == b->min)
// 	{
// 		DP(a, b, "pa");
// 		if (a->top->data < b->min && b->cnt)
// 		{
// 			DP(a, b, "ra");
// 		}
// 	}
// 	else
// 	{
// 			DP(a, b, dir ? "rb" : "rrb");
// 	}

// 	sort(a, b, dir);
// }

//2
// void	sort(t_stack *a, t_stack *b, int dir, int is_pushed)
// {
// 	// FP("@@@@@@@sort bbbbbbb@@@@@@@[%d]\n", cnt);
// 	// int is_pushed;

// 	// is_pushed = 0;
// 	if (!b->cnt)
// 		return ;
// 	if (peek(b) == b->max)
// 	{
// 		DP(a, b, "pa");
// 		is_pushed = 1;
// 		peek(a) > b->max ? (dir = find_rep(b)) : 0;
// 	}
// 	else
// 	{
// 		if (is_pushed && a->top->data < b->min && b->cnt)
// 		{
// 			DP(a, b, dir ? "rr" : "ra");
// 			is_pushed = 0;
// 		}
// 		else
// 			DP(a, b, dir ? "rb" : "rrb");
// 	}

// 	sort(a, b, dir, is_pushed);
// }



// void	split_sort(t_stack *a, t_stack *b, int len)
// {
// 	FP("@@@@@@@split AAAAAAA@@@@@@@[%d]\n", len);
// 	int median;
// 	int	cnt;
// 	int	i;

// 	if (len == 0 || check_sorted(a, a->cnt))
// 		return;
// 	cnt = 0;
// 	i = 0;
// 	if (len <= 3)
// 		sort_a(a, b, len);
// 	median = get_median(a, len);
// 	while (a->min <= median)
// 	{
// 		if (peek(a) <= median)
// 		{
// 			DP(a, b, "pb");
// 			cnt++;
// 		}
// 		else
// 		{
// 			FP("finding less than median\n");
// 			DP(a, b, "ra");
// 		}
// 	}
// 	FP("split ended\n");
// 	while (!check_sorted(a, cnt) && cnt - i++ > 0)
// 		DP(a, b, "rra");
// 	// sort_a(a, b, a->cnt);
// 	FP("set to first foramtion\n");
// 	if (cnt > 0)
// 		sort(a, b, cnt);
// 	FP("nothing in the b anymore\n");
// 	while (!check_sorted(a, a->cnt) && peek(a) <= median)
// 		DP(a, b, "ra");
// 	FP("%d thing is sorted in last\n", cnt);
// 	i = 0;
// 	while (!check_sorted(a, a->cnt) && check_sorted(a, a->cnt - cnt - i) && cnt - i++ > 0)
// 		DP(a, b, "ra");
// 	FP("thing is in sorted order, so put to the last %d ls not sorted\n", a->cnt - cnt);
// 	if (check_sorted(a, a->cnt))
// 		return ;
// 	if (a->cnt - cnt > 3)
// 		split_sort(a, b, a->cnt - cnt);
// 	else
// 		sort_a(a, b, a->cnt - cnt);
// }

// void	split_sort(t_stack *a, t_stack *b, int len)
// {
// 	// FP("@@@@@@@split bbbbbbb@@@@@@@[%d]\n", len);
// 	int median;
// 	int	cnt;
// 	int	i;

// 	cnt = 0;
// 	i = 0;
// 	median = get_median(b, len);
// 	while (b->max > median)
// 	{
// 		if (peek(b) > median)
// 		{
// 			DP(a, b, "pa");
// 			cnt++;
// 		}
// 		else
// 			DP(a, b, "rb");
// 	}
// 	// while (cnt - i++ > 0)
// 	// 	DP(a, b, "rrb");
// 	sort_a(a, b, cnt);
// 	sort(a, b, b->cnt);
// }


// void	sort(t_stack *a, t_stack *b, int cnt)
// {
// 	// FP("@@@@@@@sort bbbbbbb@@@@@@@[%d]\n", cnt);
// 	if (!b->cnt || !cnt)
// 		return ;
// 	else if (b->top->data == b->max || check_sorted_r(b, cnt))
// 	{
// 		DP(a, b, "pa");
// 		cnt--;
// 	}
// 	// else if (b->top->data == b->min)
// 	// {
// 	// 	DP(a, b, "pa");
// 	// 	DP(a, b, "ra");
// 	// }
// 	else if (cnt == 2)
// 		DP(a, b, "sb");
// 	else if (cnt == 3 && ((b->top->data < b->top->next->data &&
// 		b->top->next->data < b->top->next->next->data) ||
// 		(b->top->data < b->top->next->data &&
// 		b->top->next->data > b->top->next->next->data)))
// 		DP(a, b, "sb");
// 	else if (cnt == 3 && (b->top->data > b->top->next->data &&
// 		b->top->next->data < b->top->next->next->data))
// 		{
// 			DP(a, b, "pa");
// 			DP(a, b, "sb");
// 			DP(a, b, "pb");
// 		}
// 	else if (cnt > 3)
// 		split_sort(a, b, cnt);
// 	sort(a, b, cnt);
// }
