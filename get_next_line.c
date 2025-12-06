/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhenming <zhewu@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:26:12 by zhenming          #+#    #+#             */
/*   Updated: 2025/12/06 16:06:23 by zhenming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	char		*line;
	static int	index = 0;
	int			i;

	i = 0;
	read(fd, buffer, BUFFER_SIZE - 1);
	line = (char *)malloc(sizeof(char) * (get_len(buffer, index) + 2));
	if (!line)
		return (NULL);
	while (buffer[index] && buffer[index] != '\n')
	{
		line[i] = buffer[index];
		i++;
		index++;
	}
	if (buffer[index] == '\n')
	{
		line[i] = '\n';
		i++;
		index++;
	}
	line[i] = '\0';
	return (line);
}
