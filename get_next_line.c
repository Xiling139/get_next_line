/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhenming <zhewu@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:26:12 by zhenming          #+#    #+#             */
/*   Updated: 2025/12/10 20:08:44 by zhenming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	merge_length(char *buffer, int start)
{
	int	count;

	count = 0;
	while (buffer[start + count])
	{
		count++;
		if (buffer[start + count] == '\n')
		{
			count++;
			break ;
		}
	}
	return (count);
}

char	*update_str(char *str, char *to_merge)
{
	char	*new_str;

	if (to_merge == NULL)
		return (NULL);
	new_str = ft_strjoin(str, to_merge);
	if (!new_str)
		return (NULL);
	free(str);
	free(to_merge);
	return (new_str);
}

char	*str_to_merge(char *buffer, int index, int len)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = buffer[index + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	index = -1;
	int			max_index;
	int			merge_len;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup("");
	while (true)
	{
		if (index != -1)
		{
			merge_len = merge_length(buffer, index);
			line = update_str(line, str_to_merge(buffer, index, merge_len));
			if (line == NULL)
				return (NULL);
			index += merge_len;
			if (index < max_index)
				break ;
		}
		index = 0;
		max_index = read(fd, buffer, sizeof(buffer) - 1);
		if (max_index <= 0)
			return (NULL);
	}
	return (line);
}
