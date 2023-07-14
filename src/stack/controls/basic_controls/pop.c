/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 00:12:11 by smatsuo           #+#    #+#             */
/*   Updated: 2023/07/08 10:22:47 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*pop_from_a(t_stack *stack)
{
	return (pop_node(&stack->top_a));
}

t_node	*pop_from_b(t_stack *stack)
{
	return (pop_node(&stack->top_b));
}
