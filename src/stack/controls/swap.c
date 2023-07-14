/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 01:48:34 by smatsuo           #+#    #+#             */
/*   Updated: 2023/07/08 11:01:30 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = pop_from_a(stack);
	tmp2 = pop_from_a(stack);
	push_to_a(stack, tmp1);
	push_to_a(stack, tmp2);
	record_op_to_stack(stack, SA);
}

void	sb(t_stack *stack)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = pop_from_b(stack);
	tmp2 = pop_from_b(stack);
	push_to_b(stack, tmp1);
	push_to_b(stack, tmp2);
	record_op_to_stack(stack, SB);
}

void	ss(t_stack *stack)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = pop_from_a(stack);
	tmp2 = pop_from_a(stack);
	push_to_a(stack, tmp1);
	push_to_a(stack, tmp2);
	tmp1 = pop_from_b(stack);
	tmp2 = pop_from_b(stack);
	push_to_b(stack, tmp1);
	push_to_b(stack, tmp2);
	record_op_to_stack(stack, SS);
}
