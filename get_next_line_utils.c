/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhenming <zhewu@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:38:51 by zhenming          #+#    #+#             */
/*   Updated: 2025/12/10 17:31:31 by zhenming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int		i;
	size_t	count;

	i = 0;
	while (str[i])
	{
		i++;
	}
	count = i;
	return (count);
}

char	*ft_strdup(const char *s)
{
	unsigned int	i;
	char			*string;
	size_t			len;

	i = 0;
	len = ft_strlen(s);
	string = (char *)malloc(len + 1);
	if (!string)
		return (NULL);
	while (i < len)
	{
		string[i] = s[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	size_t			len1;
	size_t			len2;
	unsigned int	i;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (NULL);
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		str[i] = s2[i - len1];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char get_last_char(char *str)
{
	char c;
	int i;

	c = '\0';
	i = 0;
	while(str[i])
	{
		c = str[i];
		i++;
	}
	return (c);
}
