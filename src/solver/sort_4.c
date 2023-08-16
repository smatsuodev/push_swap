/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:18:51 by smatsuo           #+#    #+#             */
/*   Updated: 2023/08/17 05:10:08 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_4_in_b_helper(t_stack *stack);

static void	insert_tmp_into_a(t_stack *stack, int tmp)
{
	if (tmp < at_a(stack, 0))
		pa(stack);
	else if (at_a(stack, 0) < tmp && tmp < at_a(stack, 1))
	{
		ra(stack);
		pa(stack);
		rra(stack);
	}
	else if (at_a(stack, 1) < tmp && tmp < at_a(stack, 2))
	{
		rra(stack);
		pa(stack);
		ra(stack);
		ra(stack);
	}
	else if (at_a(stack, 2) < tmp)
	{
		pa(stack);
		ra(stack);
	}
}

void	sort_4_in_a(t_stack *stack)
{
	if (is_sorted(stack->top_a, stack->size_a))
		return ;
	pb(stack);
	sort_3_in_a(stack);
	insert_tmp_into_a(stack, at_b(stack, 0));
}

void	sort_4_in_b(t_stack *stack)
{
	if (is_sorted(stack->top_b, stack->size_b))
	{
		repeat(para, stack, 4);
		return ;
	}
	if (at_b(stack, 0) < at_b(stack, 2) && at_b(stack, 1) < at_b(stack, 2)
		&& at_b(stack, 0) < at_b(stack, 3) && at_b(stack, 1) < at_b(stack, 3))
		repeat(sort_2_in_b, stack, 2);
	else if (at_b(stack, 2) < at_b(stack, 0) && at_b(stack, 3) < at_b(stack, 0)
		&& at_b(stack, 2) < at_b(stack, 1) && at_b(stack, 3) < at_b(stack, 1))
	{
		repeat(pa, stack, 2);
		sort_2_in_b(stack);
		sort_2_in_a(stack);
		repeat(ra, stack, 2);
	}
	else if (at_b(stack, 0) == get_min_value_in_list(stack->top_b, 4))
	{
		para(stack);
		sort_3_in_b(stack);
	}
	else
		sort_4_in_b_helper(stack);
}

static void	sort_4_in_b_helper(t_stack *stack)
{
	if (at_b(stack, 0) == get_max_value_in_list(stack->top_b, 4))
	{
		pa(stack);
		sort_3_in_b(stack);
		ra(stack);
	}
	else if (at_b(stack, 3) == get_min_value_in_list(stack->top_b, 4))
	{
		rrb(stack);
		para(stack);
		sort_3_in_b(stack);
	}
	else if (at_b(stack, 3) == get_max_value_in_list(stack->top_b, 4))
	{
		rrb(stack);
		pa(stack);
		sort_3_in_b(stack);
		ra(stack);
	}
	else
	{
		rb(stack);
		sort_4_in_b(stack);
	}
}
