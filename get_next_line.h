/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhenming <zhewu@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:53:14 by zhenming          #+#    #+#             */
/*   Updated: 2025/12/10 18:23:21 by zhenming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

/* Core funtions */
char	*get_next_line(int fd);

/// Finds new line character and returns string length to merge
int	merge_length(char *buffer, int start);

/* GNL Utils */
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

/// Returns the last char of str. When NULL string is given, returns null char
char get_last_char(char *str);

#endif
