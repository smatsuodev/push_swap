/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median_in_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:29:58 by smatsuo           #+#    #+#             */
/*   Updated: 2023/08/19 14:30:58 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	get_median_in_list(t_node *node, int size)
{
	int	*arr;
	int	*sorted_arr;
	int	i;
	int	doubled_res;

	arr = ft_calloc(sizeof(int), size);
	if (arr == NULL)
		return (-1);
	i = 0;
	while (i < size)
	{
		arr[i++] = node->value;
		node = node->next;
	}
	node = node->next;
	sorted_arr = sort_int_arr(arr, size);
	free(arr);
	if (sorted_arr == NULL)
		return (-1);
	if (size % 2)
		doubled_res = sorted_arr[size / 2] * 2;
	else
		doubled_res = sorted_arr[size / 2 - 1] + sorted_arr[size / 2];
	free(sorted_arr);
	return ((double)doubled_res / 2);
}
