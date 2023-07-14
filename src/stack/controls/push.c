/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 00:06:14 by smatsuo           #+#    #+#             */
/*   Updated: 2023/07/08 11:00:43 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack)
{
	t_node	*tmp;

	tmp = pop_from_b(stack);
	push_to_a(stack, tmp);
	record_op_to_stack(stack, PA);
}

void	pb(t_stack *stack)
{
	t_node	*tmp;

	tmp = pop_from_a(stack);
	push_to_b(stack, tmp);
	record_op_to_stack(stack, PB);
}
