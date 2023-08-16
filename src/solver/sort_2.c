/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:40:38 by smatsuo           #+#    #+#             */
/*   Updated: 2023/08/17 03:18:53 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_in_a(t_stack *stack)
{
	if (at_a(stack, 0) > at_a(stack, 1))
		sa(stack);
}

void	sort_2_in_b(t_stack *stack)
{
	if (at_b(stack, 0) > at_b(stack, 1))
	{
		pa(stack);
		pa(stack);
		ra(stack);
		ra(stack);
	}
	else
	{
		pa(stack);
		ra(stack);
		pa(stack);
		ra(stack);
	}
}
