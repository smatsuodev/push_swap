/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_in_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 02:41:52 by smatsuo           #+#    #+#             */
/*   Updated: 2023/07/06 11:37:51 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_in_3(t_stack *stack)
{
	if (at_a(stack, 0) < at_a(stack, 1) && at_a(stack, 1) > at_a(stack, 2)
		&& at_a(stack, 2) > at_a(stack, 0))
	{
		pb(stack);
		sa(stack);
		pa(stack);
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
		sa(stack);
		rra(stack);
	}
}

// 0 2 1
// 1 0 2
// 1 2 0
// 2 0 1
// 2 1 0
