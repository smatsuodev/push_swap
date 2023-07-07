/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:03:14 by smatsuo           #+#    #+#             */
/*   Updated: 2023/07/08 00:11:24 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_empty_stack(int size)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->buffer_a = ft_calloc(size, sizeof(int));
	stack->buffer_b = ft_calloc(size, sizeof(int));
	if (stack->buffer_a == NULL || stack->buffer_b == NULL)
	{
		destory_stack(stack);
		return (NULL);
	}
	stack->size = size;
	return (stack);
}

t_stack	*new_stack_from(char **str_arr, int arr_len)
{
	char	**arr;
	int		stack_size;
	t_stack	*stack;

	arr = flatten_str_arr(str_arr, arr_len);
	if (!is_valid_nums(arr))
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
	compress_buffer_a(stack);
	return (stack);
}

void	set_string_to_stack(t_stack *stack, char **str_arr)
{
	int		*buffer;
	char	**cur_str;
	int		iserr;

	iserr = 0;
	cur_str = str_arr;
	buffer = stack->buffer_a;
	while (*cur_str != NULL)
		*buffer++ = ft_atoi_ex(*cur_str++, &iserr);
	free_str_arr(str_arr);
	if (!is_nums_unique(stack->buffer_a, stack->size) || iserr)
	{
		destory_stack(stack);
		exit_on_error();
	}
}

void	compress_buffer_a(t_stack *stack)
{
	int	*compressed_buffer;

	compressed_buffer = compress_array(stack->buffer_a, stack->size);
	if (compressed_buffer == NULL)
	{
		destory_stack(stack);
		exit_on_error();
	}
	free(stack->buffer_a);
	stack->buffer_a = compressed_buffer;
}
