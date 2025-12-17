/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhenming <zhewu@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:53:14 by zhenming          #+#    #+#             */
/*   Updated: 2025/12/17 16:13:32 by zhenming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 43
# endif

/* Core funtions */
char	*get_next_line(int fd);

/// Returns NULL or line based on the exception value
char	*omit_error(int value, char *line);

/// Joins two strings and free old strings
char	*update_str(char *str, char *to_merge);

/// Reads to the buffer when reached to the previous buffer
int		read_to_buffer(int fd, char *buffer, char *line);

/// Returns the string to merge
char	*str_to_merge(char *buffer, int *pos);

/* GNL Utils */

/// from libft
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

/// Returns the last char of str. When NULL string is given, returns null char
char	get_last_char(char *str);

/// Frees the string and returns null
char	*allocate_null(char *str);

#endif
