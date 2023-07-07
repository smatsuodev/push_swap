/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 01:23:48 by smatsuo           #+#    #+#             */
/*   Updated: 2023/07/05 02:24:13 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static char	**flatten_str_arr_helper(char **dst, char *src)
{
	char	**splitted_str;
	char	**tmp;

	splitted_str = ft_split(src, ' ');
	if (splitted_str == NULL)
		return (NULL);
	tmp = splitted_str;
	while (*tmp != NULL)
		*dst++ = *tmp++;
	free(splitted_str);
	return (dst);
}

char	**flatten_str_arr(char **str_arr, int arr_len)
{
	int		res_len;
	char	**res;
	char	**res_ptr;
	int		i;

	res_len = count_strings(str_arr, arr_len);
	if (res_len == -1)
		return (NULL);
	res = ft_calloc(res_len + 1, sizeof(char *));
	if (res == NULL)
		return (NULL);
	res_ptr = res;
	i = 0;
	while (i < arr_len)
	{
		res_ptr = flatten_str_arr_helper(res_ptr, str_arr[i]);
		if (res_ptr == NULL)
		{
			free_str_arr(res);
			return (NULL);
		}
		i++;
	}
	return (res);
}

int	count_strings(char **str_arr, int arr_len)
{
	int		res;
	int		i;
	char	**splitted_str;
	char	**tmp;

	res = 0;
	i = 0;
	while (i < arr_len)
	{
		splitted_str = ft_split(str_arr[i], ' ');
		if (splitted_str == NULL)
			return (-1);
		tmp = splitted_str;
		while (*tmp != NULL)
		{
			free(*tmp++);
			res++;
		}
		free(splitted_str);
		i++;
	}
	return (res);
}

void	free_str_arr(char **arr)
{
	char	**tmp;

	tmp = arr;
	while (*tmp != NULL)
		free(*tmp++);
	free(arr);
}
