/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 23:45:27 by smatsuo           #+#    #+#             */
/*   Updated: 2023/07/14 20:42:32 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort(t_stack *stack)
{
	if (stack->size == 2)
		sort_2(stack);
	if (stack->size == 3)
		sort_3(stack);
	if (stack->size == 4)
		sort_4(stack);
	if (stack->size == 5)
		sort_5(stack);
}
