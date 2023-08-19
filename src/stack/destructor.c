/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 01:46:27 by smatsuo           #+#    #+#             */
/*   Updated: 2023/08/19 14:40:07 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	destroy_stack(t_stack *stack)
{
	destroy_node(&stack->top_a);
	destroy_node(&stack->top_b);
	destroy_op_list(stack->op_list);
	free(stack);
}
