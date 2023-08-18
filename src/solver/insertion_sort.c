/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:08:08 by smatsuo           #+#    #+#             */
/*   Updated: 2023/08/18 23:42:58 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	insert_max_value(t_stack *stack, int *min_value, int *max_value)
{
	if (*min_value < *max_value && at_b(stack, 0) == *max_value)
	{
		pa(stack);
		(*max_value)--;
		return (1);
	}
	return (0);
}

static int	insert_neer_min_value(t_stack *stack,
								int *min_value, int *insert_flag)
{
	if (at_b(stack, 0) == *min_value + 1)
	{
		pa(stack);
		*insert_flag = 1;
		return (1);
	}
	return (0);
}

static void	insert_into_a(t_stack *stack, int *min_value, int *max_value)
{
	int	insert_flag;

	insert_flag = 0;
	while (at_b(stack, 0) != *min_value)
	{
		if ((!insert_flag && insert_max_value(stack, min_value, max_value))
			|| insert_neer_min_value(stack, min_value, &insert_flag))
			continue ;
		if (get_index_of_min_value_in_list(stack->top_b, stack->size_b) * 2
			<= stack->size_b)
			rb(stack);
		else
			rrb(stack);
	}
	para(stack);
	(*min_value)++;
	if (insert_flag)
	{
		ra(stack);
		(*min_value)++;
	}
}

void	insertion_sort_in_b(t_stack *stack)
{
	int	min_value;
	int	max_value;

	sort_short_stack(stack);
	if (stack->size_b == 0)
		return ;
	min_value = get_min_value_in_list(stack->top_b, stack->size_b);
	max_value = get_max_value_in_list(stack->top_b, stack->size_b);
	while (stack->size_b > OPT_SORT_SIZE)
	{
		insert_into_a(stack, &min_value, &max_value);
	}
	sort_short_stack(stack);
	while (at_a(stack, 0) != 0
		&& at_a(stack, 0) - at_a(stack, stack->size_a - 1) == 1)
		ra(stack);
	stack->next_min_value = at_a(stack, stack->size_a - 1) + 1;
}
