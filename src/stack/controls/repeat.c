/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 03:32:33 by smatsuo           #+#    #+#             */
/*   Updated: 2023/08/17 04:00:26 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	repeat(void (*op)(t_stack *), t_stack *stack, int times)
{
	int	i;

	i = 0;
	while (i++ < times)
		op(stack);
}
