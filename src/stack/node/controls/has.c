/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 20:20:03 by smatsuo           #+#    #+#             */
/*   Updated: 2023/08/18 20:23:45 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_upper_than_median(t_node *node, int median)
{
	t_node	*cur;

	if (node->value > median)
		return (1);
	cur = node->next;
	while (cur != node)
	{
		if (cur->value > median)
			return (1);
		cur = cur->next;
	}
	return (0);
}

int	has_lower_than_median(t_node *node, int median)
{
	t_node	*cur;

	if (node->value <= median)
		return (1);
	cur = node->next;
	while (cur != node)
	{
		if (cur->value <= median)
			return (1);
		cur = cur->next;
	}
	return (0);
}
