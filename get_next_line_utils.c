/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhenming <zhewu@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:38:51 by zhenming          #+#    #+#             */
/*   Updated: 2025/12/05 18:37:55 by zhenming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_len(char *buffer, int index)
{
	int	count;

	count = 0;
	while (buffer[index + count] && buffer[index + count] != '\n')
	{
		count++;
	}
	return (count);
}
