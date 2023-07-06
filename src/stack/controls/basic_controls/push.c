/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 01:49:27 by smatsuo           #+#    #+#             */
/*   Updated: 2023/06/29 00:12:44 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a(t_stack *stack, int value)
{
	stack->buffer_a[stack->front_a] = value;
	stack->front_a = (stack->front_a + 1) % stack->size;
}

void	push_to_b(t_stack *stack, int value)
{
	stack->buffer_b[stack->front_b] = value;
	stack->front_b = (stack->front_b + 1) % stack->size;
}
