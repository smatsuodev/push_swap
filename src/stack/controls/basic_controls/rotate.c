/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 02:33:18 by smatsuo           #+#    #+#             */
/*   Updated: 2023/08/26 17:49:57 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *stack)
{
	if (stack == NULL || stack->top_a == NULL)
		return ;
	stack->top_a = stack->top_a->next;
}

void	rotate_b(t_stack *stack)
{
	if (stack == NULL || stack->top_b == NULL)
		return ;
	stack->top_b = stack->top_b->next;
}

void	rev_rotate_a(t_stack *stack)
{
	if (stack == NULL || stack->top_a == NULL)
		return ;
	stack->top_a = stack->top_a->prev;
}

void	rev_rotate_b(t_stack *stack)
{
	if (stack == NULL || stack->top_b == NULL)
		return ;
	stack->top_b = stack->top_b->prev;
}
