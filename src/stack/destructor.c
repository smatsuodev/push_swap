/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 01:46:27 by smatsuo           #+#    #+#             */
/*   Updated: 2023/07/08 11:11:35 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	destory_stack(t_stack *stack)
{
	destory_node(&stack->top_a);
	destory_node(&stack->top_b);
	free(stack);
}
