/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:47:40 by smatsuo           #+#    #+#             */
/*   Updated: 2023/08/19 15:00:33 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define MAX_FD 256

char	*get_next_line(int fd);
ssize_t	read_line(int fd, char **line, char **buf_arr);
char	*join_and_free(char *s1, char *s2_start, char const *s2_end);
char	*gnl_strchr(const char *s, int c);
size_t	gnl_strlen(const char *s);
char	*ft_strjoin_between(char const *s1, char *s2_start, char const *s2_end);
void	*ft_memmove_from(void *dst, void *dst_end, void *src_start);
void	*gnl_calloc(size_t count, size_t size);

#endif
