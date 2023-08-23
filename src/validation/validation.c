/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 02:24:01 by smatsuo           #+#    #+#             */
/*   Updated: 2023/08/20 12:58:50 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_nums(char **arr)
{
	char	*cur_str;

	while (*arr != NULL)
	{
		cur_str = *arr;
		if (*cur_str == '+')
			cur_str++;
		else if (*cur_str == '-')
			cur_str++;
		if (!ft_isdigit(*cur_str))
			return (0);
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
	int	former_i;
	int	letter_i;

	former_i = 0;
	while (former_i < arr_len)
	{
		letter_i = former_i + 1;
		while (letter_i < arr_len)
		{
			if (arr[former_i] == arr[letter_i])
				return (0);
			letter_i++;
		}
		former_i++;
	}
	return (1);
}
