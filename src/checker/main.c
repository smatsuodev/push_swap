/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:08:36 by smatsuo           #+#    #+#             */
/*   Updated: 2023/08/19 16:31:29 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//__attribute__((destructor))
//static void destructor() {
//    system("leaks -q checker");
//}

int	main(int argc, char **argv)
{
	t_stack		*stack;
	char		*line;
	t_op		op;
	t_op_list	op_list;

	if (argc == 1)
		return (0);
	stack = new_stack_from(argv + 1, argc - 1);
	if (stack == NULL)
		exit_on_error();
	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		op = str_to_op(line);
		free(line);
		if (op == UNKNOWN)
			destroy_stack_then_exit(stack);
		append_op(&op_list, op);
	}
	run_ops(stack, op_list.next);
	destroy_stack(stack);
}

void	run_ops(t_stack *stack, t_op_list *op_list)
{
	t_op_list	*cur_op;

	cur_op = op_list;
	while (cur_op != NULL)
	{
		run_op(stack, cur_op->op);
		cur_op = cur_op->next;
	}
	destroy_op_list(op_list);
	if (is_sorted(stack->top_a, stack->size_a) && stack->size_b == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	run_op(t_stack *stack, t_op op)
{
	if (op == SA)
		sa(stack);
	if (op == SB)
		sb(stack);
	if (op == SS)
		ss(stack);
	if (op == PA)
		pa(stack);
	if (op == PB)
		pb(stack);
	if (op == RA)
		ra(stack);
	if (op == RB)
		rb(stack);
	if (op == RR)
		rr(stack);
	if (op == RRA)
		rra(stack);
	if (op == RRB)
		rrb(stack);
	if (op == RRR)
		rrr(stack);
}

t_op	str_to_op(char *str)
{
	if (ft_strlen(str) <= 1)
		return (UNKNOWN);
	if (ft_strncmp(str, "sa\n", ft_max(ft_strlen(str), 3)) == 0)
		return (SA);
	if (ft_strncmp(str, "sb\n", ft_max(ft_strlen(str), 3)) == 0)
		return (SB);
	if (ft_strncmp(str, "ss\n", ft_max(ft_strlen(str), 3)) == 0)
		return (SS);
	if (ft_strncmp(str, "pa\n", ft_max(ft_strlen(str), 3)) == 0)
		return (PA);
	if (ft_strncmp(str, "pb\n", ft_max(ft_strlen(str), 3)) == 0)
		return (PB);
	if (ft_strncmp(str, "ra\n", ft_max(ft_strlen(str), 3)) == 0)
		return (RA);
	if (ft_strncmp(str, "rb\n", ft_max(ft_strlen(str), 3)) == 0)
		return (RB);
	if (ft_strncmp(str, "rr\n", ft_max(ft_strlen(str), 3)) == 0)
		return (RR);
	if (ft_strncmp(str, "rra\n", ft_max(ft_strlen(str), 4)) == 0)
		return (RRA);
	if (ft_strncmp(str, "rrb\n", ft_max(ft_strlen(str), 4)) == 0)
		return (RRB);
	if (ft_strncmp(str, "rrr\n", ft_max(ft_strlen(str), 4)) == 0)
		return (RRR);
	return (UNKNOWN);
}
