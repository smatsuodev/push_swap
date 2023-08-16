/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:08:08 by smatsuo           #+#    #+#             */
/*   Updated: 2023/08/17 04:49:13 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort_in_b(t_stack *stack)
{
	int	min_value;

	sort_short_stack(stack);
	if (stack->size_b == 0)
		return ;
	min_value = get_min_value_in_list(stack->top_b, stack->size_b);
	while (stack->size_b > 5)
	{
		while (at_b(stack, 0) != min_value)
		{
			if (get_index_of_min_value_in_list(stack->top_b, stack->size_b) * 2
				<= stack->size_b)
				rb(stack);
			else
				rrb(stack);
		}
		pa(stack);
		ra(stack);
		min_value++;
	}
	sort_short_stack(stack);
	stack->next_min_value = at_a(stack, stack->size_a - 1) + 1;
}
