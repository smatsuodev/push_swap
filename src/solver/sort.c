/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 23:45:27 by smatsuo           #+#    #+#             */
/*   Updated: 2023/08/18 20:03:07 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	else
		quick_sort(stack);
}
