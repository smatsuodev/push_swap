/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 23:52:37 by smatsuo           #+#    #+#             */
/*   Updated: 2023/08/16 23:46:59 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_values_from_a_to_b(t_stack *stack, double pivot)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		i++;
		if (at_a(stack, 0) < pivot)
			pb(stack);
		else
			ra(stack);
	}
}

void	sort_6(t_stack *stack)
{
	double	median;

	if (is_sorted(stack->top_a, stack->size_a))
		return ;
	median = get_median_in_list(stack->top_a, stack->size);
	if (median == -1)
		destroy_stack_then_exit(stack);
	move_values_from_a_to_b(stack, median);
	sort_3_in_a(stack);
	sort_3_in_b(stack);
	while (at_b(stack, 0) != -1)
	{
		pa(stack);
		ra(stack);
	}
	ra(stack);
	ra(stack);
	ra(stack);
}
