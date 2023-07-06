/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 00:09:12 by smatsuo           #+#    #+#             */
/*   Updated: 2023/07/04 02:37:36 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	rotate_a(stack);
	record_op_to_stack(stack, RA);
}

void	rb(t_stack *stack)
{
	rotate_b(stack);
	record_op_to_stack(stack, RB);
}

void	rr(t_stack *stack)
{
	rotate_a(stack);
	rotate_b(stack);
	record_op_to_stack(stack, RR);
}
