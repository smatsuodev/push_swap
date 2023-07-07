/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:45:26 by smatsuo           #+#    #+#             */
/*   Updated: 2023/07/08 01:30:35 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

///__attribute__((destructor))
///static void destructor() {
///    system("leaks -q push_swap");
///}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = new_stack_from(argv + 1, argc - 1);
	if (stack == NULL)
		exit_on_error();
	if (stack->size == 3)
		solve_in_3(stack);
	if (stack->size == 4)
		solve_in_4(stack);
	print_ops(stack->op_list);
	for(int i =0;i<stack->size;i++)
	{
		ft_printf("%d\n", at_a(stack, i));
	}
	destory_stack(stack);
	return (0);
}
