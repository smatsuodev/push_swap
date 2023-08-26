/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 00:12:11 by smatsuo           #+#    #+#             */
/*   Updated: 2023/08/26 17:49:23 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*pop_from_a(t_stack *stack)
{
	t_node	*res;

	if (stack == NULL)
		return (NULL);
	res = pop_node(&stack->top_a);
	if (res != NULL)
		stack->size_a--;
	return (res);
}

t_node	*pop_from_b(t_stack *stack)
{
	t_node	*res;

	if (stack == NULL)
		return (NULL);
	res = pop_node(&stack->top_b);
	if (res != NULL)
		stack->size_b--;
	return (res);
}
