/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:58:36 by smatsuo           #+#    #+#             */
/*   Updated: 2023/08/18 21:28:20 by smatsuo          ###   ########.fr       */
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

void	replace_ops(t_op_list **cur, t_op new_op)
{
	remove_front(cur);
	(*cur)->op = new_op;
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
			replace_ops(cur, SS);
		if (is_op_pair(*cur, RA, RB))
			replace_ops(cur, RR);
		if (is_op_pair(*cur, RRA, RRB))
			replace_ops(cur, RRR);
		if (is_op_pair(*cur, RB, RRB) || is_op_pair(*cur, RA, RRA))
		{
			remove_front(cur);
			remove_front(cur);
		}
		cur = &((*cur)->next);
	}
}
