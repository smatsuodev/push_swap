/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 19:52:27 by smatsuo           #+#    #+#             */
/*   Updated: 2023/08/17 05:01:52 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3_in_b_helper(t_stack *stack);

void	sort_3_in_a(t_stack *stack)
{
	if (at_a(stack, 0) < at_a(stack, 1) && at_a(stack, 1) > at_a(stack, 2)
		&& at_a(stack, 2) > at_a(stack, 0))
	{
		rra(stack);
		sa(stack);
	}
	else if (at_a(stack, 0) > at_a(stack, 1) && at_a(stack, 1) < at_a(stack, 2)
		&& at_a(stack, 2) > at_a(stack, 0))
		sa(stack);
	else if (at_a(stack, 0) < at_a(stack, 1) && at_a(stack, 1) > at_a(stack, 2)
		&& at_a(stack, 2) < at_a(stack, 0))
		rra(stack);
	else if (at_a(stack, 0) > at_a(stack, 1) && at_a(stack, 1) < at_a(stack, 2)
		&& at_a(stack, 2) < at_a(stack, 0))
		ra(stack);
	else if (at_a(stack, 0) > at_a(stack, 1) && at_a(stack, 1) > at_a(stack, 2)
		&& at_a(stack, 2) < at_a(stack, 0))
	{
		ra(stack);
		sa(stack);
	}
}

void	sort_3_in_b(t_stack *stack)
{
	if (is_sorted(stack->top_b, stack->size_b))
	{
		repeat(para, stack, 3);
		return ;
	}
	if (at_b(stack, 0) < at_b(stack, 1) && at_b(stack, 1) > at_b(stack, 2)
		&& at_b(stack, 2) > at_b(stack, 0))
	{
		para(stack);
		sort_2_in_b(stack);
	}
	else if (at_b(stack, 0) > at_b(stack, 1) && at_b(stack, 1) < at_b(stack, 2)
		&& at_b(stack, 2) > at_b(stack, 0))
	{
		sort_2_in_b(stack);
		para(stack);
	}
	else
		sort_3_in_b_helper(stack);
}

static void	sort_3_in_b_helper(t_stack *stack)
{
	if (at_b(stack, 0) < at_b(stack, 1) && at_b(stack, 1) > at_b(stack, 2)
		&& at_b(stack, 2) < at_b(stack, 0))
	{
		rrb(stack);
		sort_2_in_b(stack);
		para(stack);
	}
	else if ((at_b(stack, 0) > at_b(stack, 1) && at_b(stack, 1) < at_b(stack, 2)
			&& at_b(stack, 2) < at_b(stack, 0))
		|| (at_b(stack, 0) > at_b(stack, 1) && at_b(stack, 1) > at_b(stack, 2)
			&& at_b(stack, 2) < at_b(stack, 0)))
	{
		pa(stack);
		sort_2_in_b(stack);
		ra(stack);
	}
}
