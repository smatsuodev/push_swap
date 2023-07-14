/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 19:52:27 by smatsuo           #+#    #+#             */
/*   Updated: 2023/07/14 20:19:11 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *stack)
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
