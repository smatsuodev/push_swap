/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index_of_min_value_on_list.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 22:28:56 by smatsuo           #+#    #+#             */
/*   Updated: 2023/07/14 22:35:31 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index_of_min_value_on_list(t_node *node, int size)
{
	int	min_value;
	int	res;
	int	i;

	min_value = INT_MAX;
	res = -1;
	i = 0;
	while (i < size)
	{
		if (node->value < min_value)
		{
			min_value = node->value;
			res = i;
		}
		node = node->next;
		i++;
	}
	return (res);
}
