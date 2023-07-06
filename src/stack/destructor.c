/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 01:46:27 by smatsuo           #+#    #+#             */
/*   Updated: 2023/06/28 23:51:13 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	destory_stack(t_stack *stack)
{
	free(stack->buffer_a);
	free(stack->buffer_b);
	destory_op_list(stack->op_list);
	free(stack);
}
