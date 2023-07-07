/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 02:33:18 by smatsuo           #+#    #+#             */
/*   Updated: 2023/07/08 01:54:55 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *stack)
{
	stack->front_a = (stack->front_a + 1) % stack->size;
	stack->rear_a = (stack->rear_a + 1) % stack->size;
}

void	rotate_b(t_stack *stack)
{
	stack->front_b = (stack->front_b + 1) % stack->size;
	stack->rear_b = (stack->rear_b + 1) % stack->size;
}

void	rev_rotate_a(t_stack *stack)
{
	stack->front_a = (stack->front_a + stack->size - 1) % stack->size;
	stack->rear_a = (stack->rear_a + stack->size - 1) % stack->size;
}

void	rev_rotate_b(t_stack *stack)
{
	stack->front_b = (stack->front_b + stack->size - 1) % stack->size;
	stack->rear_b = (stack->rear_b + stack->size - 1) % stack->size;
}
