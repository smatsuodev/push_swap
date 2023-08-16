/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 23:47:41 by smatsuo           #+#    #+#             */
/*   Updated: 2023/08/16 23:47:36 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_on_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	destroy_stack_then_exit(t_stack	*stack)
{
	destroy_stack(stack);
	exit_on_error();
}
