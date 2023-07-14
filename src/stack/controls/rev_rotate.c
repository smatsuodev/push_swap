/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 02:36:31 by smatsuo           #+#    #+#             */
/*   Updated: 2023/07/04 02:39:52 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack)
{
	rev_rotate_a(stack);
	record_op_to_stack(stack, RRA);
}

void	rrb(t_stack *stack)
{
	rev_rotate_b(stack);
	record_op_to_stack(stack, RRB);
}

void	rrr(t_stack *stack)
{
	rev_rotate_a(stack);
	rev_rotate_b(stack);
	record_op_to_stack(stack, RRR);
}
