/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 22:49:41 by smatsuo           #+#    #+#             */
/*   Updated: 2023/08/17 02:01:51 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	ft_printf("=======\n");
	while (i < ft_max(stack->size_a, stack->size_b))
	{
		if (i < stack->size_a && i < stack->size_b)
			ft_printf("%2d:g%-2d %2d:g%-2d\n", at_a(stack, 0),
				stack->top_a->group_id, at_b(stack, 0), stack->top_b->group_id);
		else if (i < stack->size_a)
			ft_printf("%2d:g%-2d\n", at_a(stack, 0), stack->top_a->group_id);
		else
			ft_printf("       %2d:g%-2d\n",
				at_b(stack, 0), stack->top_b->group_id);
		if (i < stack->size_a)
			rotate_a(stack);
		if (i < stack->size_b)
			rotate_b(stack);
		i++;
	}
	ft_printf("=======\n");
}
