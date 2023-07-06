/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:45:26 by smatsuo           #+#    #+#             */
/*   Updated: 2023/07/06 12:07:43 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//__attribute__((destructor))
//static void destructor() {
//    system("leaks -q push_swap");
//}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = new_stack_from(argv + 1, argc - 1);
	if (stack == NULL)
		exit_on_error();
	if (stack->size == 3)
		solve_in_3(stack);
	print_ops(stack->op_list);
	destory_stack(stack);
	return (0);
}
