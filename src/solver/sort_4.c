/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:18:51 by smatsuo           #+#    #+#             */
/*   Updated: 2023/07/14 22:39:01 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_4(t_stack *stack)
{
	if (is_sorted(stack->top_a, stack->size))
		return ;
	pb(stack);
	sort_3(stack);
	insert_tmp_into_a(stack, at_b(stack, 0));
}
