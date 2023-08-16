/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:51:11 by smatsuo           #+#    #+#             */
/*   Updated: 2023/08/17 00:06:51 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_op_list	*new_op_list(t_op op)
{
	t_op_list	*list;

	list = ft_calloc(1, sizeof(t_op_list));
	if (list == NULL)
		return (NULL);
	list->op = op;
	return (list);
}

t_op_list	*append_op(t_op_list *list, t_op op)
{
	t_op_list	*new_node;

	new_node = new_op_list(op);
	if (new_node == NULL)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	list->next = new_node;
	return (new_node);
}

void	print_op(t_op op)
{
	if (op == SA)
		ft_printf("sa\n");
	if (op == SB)
		ft_printf("sb\n");
	if (op == SS)
		ft_printf("ss\n");
	if (op == PA)
		ft_printf("pa\n");
	if (op == PB)
		ft_printf("pb\n");
	if (op == RA)
		ft_printf("ra\n");
	if (op == RB)
		ft_printf("rb\n");
	if (op == RR)
		ft_printf("rr\n");
	if (op == RRA)
		ft_printf("rra\n");
	if (op == RRB)
		ft_printf("rrb\n");
	if (op == RRR)
		ft_printf("rrr\n");
}

void	print_ops(t_op_list **list)
{
	t_op_list	*cur_node;

	if (list == NULL)
		return ;
	optimize_ops(list);
	cur_node = *list;
	while (cur_node != NULL)
	{
		print_op(cur_node->op);
		cur_node = cur_node->next;
	}
}

void	destroy_op_list(t_op_list *list)
{
	t_op_list	*cur_node;
	t_op_list	*tmp;

	cur_node = list;
	while (cur_node != NULL)
	{
		tmp = cur_node->next;
		free(cur_node);
		cur_node = tmp;
	}
}
