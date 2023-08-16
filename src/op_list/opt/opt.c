/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:58:36 by smatsuo           #+#    #+#             */
/*   Updated: 2023/08/17 00:09:44 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	is_op_pair(t_op_list *node, t_op op1, t_op op2)
{
	if (node == NULL || node->next == NULL)
		return (0);
	return ((node->op == op1 && node->next->op == op2)
		|| (node->op == op2 && node->next->op == op1));
}

void	remove_front(t_op_list **list)
{
	t_op_list	*tmp;

	tmp = (*list)->next;
	free(*list);
	*list = tmp;
}

void	optimize_ops(t_op_list **list)
{
	t_op_list	**cur;

	if (list == NULL)
		return ;
	cur = list;
	while (*cur != NULL)
	{
		if (is_op_pair(*cur, SA, SB))
		{
			remove_front(cur);
			(*cur)->op = SS;
		}
		if (is_op_pair(*cur, RA, RB))
		{
			remove_front(cur);
			(*cur)->op = RR;
		}
		if (is_op_pair(*cur, RRA, RRB))
		{
			remove_front(cur);
			(*cur)->op = RRR;
		}
		cur = &((*cur)->next);
	}
}
