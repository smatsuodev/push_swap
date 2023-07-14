/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 10:08:18 by smatsuo           #+#    #+#             */
/*   Updated: 2023/07/08 10:21:49 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Returns given node and set node->next to node.
t_node	*pop_node(t_node **node)
{
	t_node	*res;
	t_node	*next;
	t_node	*prev;

	if (*node == NULL)
		return (NULL);
	res = *node;
	next = res->next;
	prev = res->prev;
	if (next == res)
	{
		*node = NULL;
		return (res);
	}
	*node = next;
	next->prev = prev;
	prev->next = next;
	return (res);
}
