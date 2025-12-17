/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhenming <zhewu@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:26:12 by zhenming          #+#    #+#             */
/*   Updated: 2025/12/17 16:17:48 by zhenming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*omit_error(int value, char *line)
{
	if (value == 0)
		return (line);
	return (NULL);
}

char	*update_str(char *str, char *to_merge)
{
	char	*new_str;

	if (str == NULL)
		return (NULL);
	if (to_merge == NULL)
		return (free(str), NULL);
	new_str = ft_strjoin(str, to_merge);
	if (!new_str)
		return (free(str), free(to_merge), NULL);
	free(str);
	free(to_merge);
	return (new_str);
}

char	*str_to_merge(char *buffer, int *pos)
{
	char	*str;
	int		i;
	int		len;

	len = 0;
	while (buffer[*pos + len] && buffer[*pos + len] != '\n')
	{
		len++;
	}
	if (buffer[*pos + len] == '\n')
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = buffer[*pos + i];
		i++;
	}
	str[i] = '\0';
	*pos += len;
	return (str);
}

int	read_to_buffer(int fd, char *buffer, char *line)
{
	int	buffer_bytes;

	if (line == NULL)
		return (-1);
	buffer_bytes = read(fd, buffer, BUFFER_SIZE);
	if (buffer_bytes <= 0)
	{
		if (buffer_bytes < 0 || (buffer_bytes == 0 && line[0] == '\0'))
		{
			free(line);
			return (-1);
		}
		return (0);
	}
	buffer[buffer_bytes] = '\0';
	return (buffer_bytes);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	static int	pos = 0;
	static int	buffer_bytes = 0;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup("");
	while (true)
	{
		if (pos >= buffer_bytes)
		{
			buffer_bytes = read_to_buffer(fd, buffer, line);
			if (buffer_bytes <= 0)
				return (omit_error(buffer_bytes, line));
			pos = 0;
		}
		line = update_str(line, str_to_merge(buffer, &pos));
		if (line == NULL)
			return (NULL);
		if ((get_last_char(line) == '\n'))
			break ;
	}
	return (line);
}
