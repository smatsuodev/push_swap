/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 21:19:13 by smatsuo           #+#    #+#             */
/*   Updated: 2023/08/16 22:55:39 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *node, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (node->next->value < node->value)
			return (0);
		node = node->next;
		i++;
	}
	return (1);
}
