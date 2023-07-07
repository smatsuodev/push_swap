/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 23:38:08 by smatsuo           #+#    #+#             */
/*   Updated: 2023/07/08 00:05:52 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Return NULL if an error occured
int	*compress_array(int *arr, int arr_len)
{
	int	*sorted_arr;
	int	*res;
	int	i;

	sorted_arr = sort(arr, arr_len);
	res = ft_calloc(sizeof(int), arr_len);
	if (sorted_arr == NULL || res == NULL)
	{
		free(sorted_arr);
		free(res);
		return (NULL);
	}
	i = 0;
	while (i < arr_len)
	{
		res[i] = search_in_int_arr(sorted_arr, arr_len, arr[i]) - sorted_arr;
		i++;
	}
	free(sorted_arr);
	return (res);
}
