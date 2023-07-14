/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:42:23 by smatsuo           #+#    #+#             */
/*   Updated: 2023/07/14 23:36:12 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(t_stack *stack)
{
	int	min_value_index;
	int	min_value;

	if (is_sorted(stack->top_a, stack->size))
		return ;
	min_value_index = get_index_of_min_value_on_list(stack->top_a, stack->size);
	min_value = at_a(stack, min_value_index);
	if (min_value_index < stack->size / 2)
		while (at_a(stack, 0) != min_value)
			ra(stack);
	else
		while (at_a(stack, 0) != min_value)
			rra(stack);
	pb(stack);
	sort_4(stack);
	pa(stack);
}
