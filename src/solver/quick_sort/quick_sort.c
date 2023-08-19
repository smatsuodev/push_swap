/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:09:44 by smatsuo           #+#    #+#             */
/*   Updated: 2023/08/19 14:41:53 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pickup_from_a(t_stack *stack, int group_id)
{
	double	median;
	int		i;
	int		size;

	size = stack->size_a;
	median = get_median_in_list(stack->top_a, size);
	if (median == -1)
		destroy_stack_then_exit(stack);
	i = 0;
	while (i++ < size && has_lower_than_median(stack->top_a, median))
	{
		if (at_a(stack, 0) <= median)
		{
			stack->top_a->group_id = group_id;
			pb(stack);
		}
		else
			ra(stack);
	}
}

void	pickup_from_b(t_stack *stack, int group_id)
{
	double	median;

	median = get_median_in_list(stack->top_b, stack->size_b);
	if (median == -1)
		destroy_stack_then_exit(stack);
	while (stack->size_b > 0 && stack->top_b->group_id != group_id
		&& has_upper_than_median(stack->top_b, median))
	{
		stack->top_b->group_id = group_id;
		if (at_b(stack, 0) == stack->next_min_value)
		{
			pa(stack);
			ra(stack);
			stack->next_min_value++;
		}
		else if (at_b(stack, 0) > median)
			pa(stack);
		else
			rb(stack);
	}
}

void	sort_short_stack(t_stack *stack)
{
	if (stack->size_b > 5)
		return ;
	if (stack->size_b == 1)
		para(stack);
	if (stack->size_b == 2)
		sort_2_in_b(stack);
	else if (stack->size_b == 3)
		sort_3_in_b(stack);
	else if (stack->size_b == 4)
		sort_4_in_b(stack);
	else if (stack->size_b == 5)
		sort_5_in_b(stack);
}

static void	quick_sort_helper(t_stack *stack)
{
	int	group_id_tmp;

	if (stack->size_b == 0)
	{
		group_id_tmp = stack->top_a->group_id;
		while (stack->top_a->group_id == group_id_tmp)
		{
			if (at_a(stack, 0) == stack->next_min_value)
			{
				ra(stack);
				stack->next_min_value++;
			}
			else
				pb(stack);
		}
	}
}

void	quick_sort(t_stack *stack)
{
	int	cur_group_id;

	cur_group_id = 1;
	while (!(stack->size_a == stack->size
			&& is_sorted(stack->top_a, stack->size_a)))
	{
		if (cur_group_id == 1)
			pickup_from_a(stack, cur_group_id++);
		quick_sort_helper(stack);
		while (stack->size_b >= MAX_GROUP_SIZE * 2)
			pickup_from_b(stack, cur_group_id++);
		insertion_sort_in_b(stack);
	}
}
