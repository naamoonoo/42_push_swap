/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 15:20:10 by hnam              #+#    #+#             */
/*   Updated: 2019/06/04 23:03:53 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_only_3(t_stack *a)
{
	if (check_sorted(a, a->cnt))
		return ;
	if (a->cnt == 2 && !check_sorted(a, a->cnt))
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
