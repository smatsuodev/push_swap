/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:47:38 by smatsuo           #+#    #+#             */
/*   Updated: 2023/08/19 14:57:05 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buf_arr[MAX_FD] = {0};
	char		*line;
	ssize_t		read_res;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE == 0)
		return (NULL);
	if (buf_arr[fd] == NULL)
	{
		buf_arr[fd] = gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (buf_arr[fd] == NULL)
			return (NULL);
	}
	line = NULL;
	read_res = read_line(fd, &line, buf_arr);
	if (read_res <= 0)
	{
		free(buf_arr[fd]);
		buf_arr[fd] = NULL;
	}
	if (read_res == -1 || (read_res == 0 && gnl_strlen(line) == 0))
	{
		free(line);
		return (NULL);
	}
	return (line);
}

ssize_t	read_line(int fd, char **line, char **buf_arr)
{
	ssize_t	read_res;
	char	*line_end_pos;

	while (1)
	{
		line_end_pos = gnl_strchr(buf_arr[fd], '\n');
		if (line_end_pos != NULL)
			break ;
		*line = join_and_free(*line, buf_arr[fd],
				gnl_strchr(buf_arr[fd], '\0'));
		if (*line == NULL)
			return (-1);
		read_res = read(fd, buf_arr[fd], BUFFER_SIZE);
		if (read_res <= 0)
			return (read_res);
	}
	if (line_end_pos == NULL)
		line_end_pos = gnl_strchr(buf_arr[fd], '\0');
	*line = join_and_free(*line, buf_arr[fd], line_end_pos + 1);
	if (*line == NULL)
		return (-1);
	ft_memmove_from(buf_arr[fd], &buf_arr[fd][BUFFER_SIZE], line_end_pos + 1);
	return (gnl_strlen(*line));
}

char	*join_and_free(char *s1, char *s2_start, char const *s2_end)
{
	char	*res;

	res = ft_strjoin_between(s1, s2_start, s2_end);
	free(s1);
	if (res == NULL)
		return (NULL);
	return (res);
}
