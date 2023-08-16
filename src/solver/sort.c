/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 23:45:27 by smatsuo           #+#    #+#             */
/*   Updated: 2023/07/21 11:39:37 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort(t_stack *stack)
{
	if (stack->size == 2)
		sort_2_in_a(stack);
	else if (stack->size == 3)
		sort_3_in_a(stack);
	else if (stack->size == 4)
		sort_4_in_a(stack);
	else if (stack->size == 5)
		sort_5_in_a(stack);
	else if (stack->size == 6)
		sort_6(stack);
	else
		quick_sort(stack);
}
