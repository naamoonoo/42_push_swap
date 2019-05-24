/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 15:20:10 by hnam              #+#    #+#             */
/*   Updated: 2019/05/24 15:20:10 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a_3(t_stack *a)
{
	if (check_sorted(a))
		return ;
	if (a->count == 2 && !check_sorted(a))
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
	sort_a_3(a);
}

void	sort_a_5(t_stack *a, t_stack *b)
{
	if (check_sorted(a))
	{
		if (!is_empty(b))
			DP(a, b, "pa");
		else
			return ;
	}
	else
	{
		if (a->count <= 3)
			sort_a_3(a);
		else if (a->top->data == a->min)
			DP(a, b, "pb");
		else if (a->top->next->data == a->min ||
			a->top->next->next->data == a->min)
			DP(a, a, "ra");
		else
			DP(a, a, "rra");
	}
	sort_a_5(a, b);
}
