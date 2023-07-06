/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 00:12:11 by smatsuo           #+#    #+#             */
/*   Updated: 2023/06/29 00:12:24 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pop_from_a(t_stack *stack)
{
	int	value;

	value = stack->buffer_a[stack->front_a];
	stack->front_a = (stack->front_a + 1 + stack->size) % stack->size;
	return (value);
}

int	pop_from_b(t_stack *stack)
{
	int	value;

	value = stack->buffer_b[stack->front_b];
	stack->front_b = (stack->front_b + 1 + stack->size) % stack->size;
	return (value);
}
