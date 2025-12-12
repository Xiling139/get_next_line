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

int	merge_length(char *buffer, int start)
{
	int	count;

	count = 0;
	while (buffer[start + count] && buffer[start + count] != '\n')
	{
		count++;
	}
	if (buffer[start + count] == '\n')
		count++;
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
	static int	pos = 0;
	static int buffer_bytes = 0;
	int			merge_len;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup("");
	while (true)
	{
		if (pos >= buffer_bytes)
		{
			buffer_bytes = read(fd, buffer, sizeof(buffer) - 1);
			if (buffer_bytes <= 0)
			{
				if (buffer_bytes < 0 || (buffer_bytes == 0 && line[0] == '\0'))
				{
					free(line);
					return (NULL);
				}
				return (line);
			}
			pos = 0;
			buffer[buffer_bytes] = '\0';
		}
		merge_len = merge_length(buffer, pos);
		line = update_str(line, str_to_merge(buffer, pos, merge_len));
		if (line == NULL)
			return (NULL);
		pos += merge_len;
		if ((get_last_char(line) == '\n'))
			break ;
	}
	return (line);
}
