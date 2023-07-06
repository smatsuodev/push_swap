/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 02:43:24 by smatsuo           #+#    #+#             */
/*   Updated: 2023/07/04 02:45:05 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	at_a(t_stack *stack, int index)
{
	return (stack->buffer_a[stack->front_a + index]);
}

int	at_b(t_stack *stack, int index)
{
	return (stack->buffer_b[stack->front_b + index]);
}
