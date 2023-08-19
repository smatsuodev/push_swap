/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 02:56:53 by smatsuo           #+#    #+#             */
/*   Updated: 2023/08/19 14:35:15 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_node(t_node **node, t_node *new_node)
{
	if (*node == NULL)
	{
		*node = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else if (new_node != NULL)
	{
		new_node->next = *node;
		new_node->prev = (*node)->prev;
		(*node)->prev->next = new_node;
		(*node)->prev = new_node;
	}
}
