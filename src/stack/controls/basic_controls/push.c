/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 01:49:27 by smatsuo           #+#    #+#             */
/*   Updated: 2023/07/21 11:01:30 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a(t_stack *stack, t_node *node)
{
	insert_node(&stack->top_a, node);
	stack->top_a = node;
	stack->size_a++;
}

void	push_to_b(t_stack *stack, t_node *node)
{
	insert_node(&stack->top_b, node);
	stack->top_b = node;
	stack->size_b++;
}
