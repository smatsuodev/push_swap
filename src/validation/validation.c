/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 02:24:01 by smatsuo           #+#    #+#             */
/*   Updated: 2023/07/05 02:28:11 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_nums(char **arr)
{
	char	*cur_str;

	while (*arr != NULL)
	{
		cur_str = *arr;
		if (*cur_str == '-')
			cur_str++;
		while (*cur_str != '\0')
		{
			if (!ft_isdigit(*cur_str))
				return (0);
			cur_str++;
		}
		arr++;
	}
	return (1);
}

int	is_nums_unique(int *arr, int arr_len)
{
	int	i;
	int	j;

	i = 0;
	while (i < arr_len)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
