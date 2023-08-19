/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 03:26:08 by smatsuo           #+#    #+#             */
/*   Updated: 2023/08/19 14:57:14 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gnl_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		++s;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin_between(char const *s1, char *s2_start, char const *s2_end)
{
	char		*result;
	size_t		result_len;
	char		*cur_res;

	if (s2_start == NULL || s2_end == NULL)
		return (NULL);
	result_len = gnl_strlen(s1) + (s2_end - s2_start);
	result = gnl_calloc(result_len + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	cur_res = result;
	while (s1 != NULL && *s1 != '\0')
		*cur_res++ = *s1++;
	while (s2_start < s2_end)
	{
		*cur_res++ = *s2_start;
		*s2_start++ = '\0';
	}
	*cur_res = '\0';
	return (result);
}

size_t	gnl_strlen(const char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len] != '\0')
		++len;
	return (len);
}

// This function moves a value and set zero into where the value were
void	*ft_memmove_from(void *dst, void *dst_end, void *src_start)
{
	char	*cur_dst;
	char	*cur_src;

	if (dst == NULL || dst_end == NULL || src_start == NULL)
		return (NULL);
	cur_dst = dst;
	cur_src = src_start;
	while (cur_src < (char *)dst_end)
	{
		*cur_dst++ = *cur_src;
		*cur_src++ = 0;
	}
	while (cur_dst < (char *)dst_end)
		*cur_dst++ = 0;
	return (dst);
}

void	*gnl_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	i;

	if (!(count == 0 || size <= SIZE_T_MAX / count))
		return (NULL);
	if (count * size > SIZE_MAX)
		return (NULL);
	p = (char *)malloc(count * size);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < count * size)
		p[i++] = 0;
	return (p);
}
