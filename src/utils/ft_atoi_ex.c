/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:48:33 by smatsuo           #+#    #+#             */
/*   Updated: 2023/07/06 12:03:29 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	return_on_err(int *iserr)
{
	*iserr = 1;
	return (0);
}

int	ft_atoi_ex(char *s, int *iserr)
{
	long long	res;
	long long	flag;

	flag = 1;
	while (*s == ' ' || *s == '\n' || *s == '\t'
		|| *s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-')
	{
		flag = -1;
		s++;
	}
	if (*s == '\0' || *s < '0' || *s > '9')
		return (return_on_err(iserr));
	res = 0;
	while (*s != '\0' && *s >= '0' && *s <= '9')
	{
		res = res * 10 + *s++ - '0';
		if (res * flag > INT_MAX || res * flag < INT_MIN)
			return (return_on_err(iserr));
	}
	return (res * flag);
}
