/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:03:14 by smatsuo           #+#    #+#             */
/*   Updated: 2023/08/20 00:11:21 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_empty_stack(int size)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->size = size;
	return (stack);
}

t_stack	*new_stack_from(char **str_arr, int arr_len)
{
	char	**arr;
	t_stack	*stack;
	int		stack_size;

	arr = flatten_str_arr(str_arr, arr_len);
	if (arr == NULL || !is_valid_nums(arr))
	{
		free_str_arr(arr);
		return (NULL);
	}
	stack_size = 0;
	while (arr[stack_size] != NULL)
		stack_size++;
	stack = new_empty_stack(stack_size);
	if (stack == NULL)
	{
		free_str_arr(arr);
		return (NULL);
	}
	set_string_to_stack(stack, arr);
	stack->size_a = stack->size;
	return (stack);
}

void	set_string_to_stack(t_stack *stack, char **str_arr)
{
	int		iserr;
	int		*int_arr;
	int		i;
	t_node	*node;

	iserr = 0;
	int_arr = compress_array(ft_atoi_arr(str_arr, &iserr), stack->size);
	free_str_arr(str_arr);
	if (int_arr == NULL || iserr || !is_nums_unique(int_arr, stack->size))
	{
		free(int_arr);
		destroy_stack_then_exit(stack);
	}
	i = stack->size - 1;
	while (i >= 0)
	{
		node = new_node(int_arr[i--]);
		if (node == NULL)
		{
			free(int_arr);
			destroy_stack_then_exit(stack);
		}
		push_to_a(stack, node);
	}
	free(int_arr);
}
