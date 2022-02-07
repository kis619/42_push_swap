/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:26:13 by kmilchev          #+#    #+#             */
/*   Updated: 2021/12/14 12:26:13 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*new_string;
	int		s1_len;
	int		s2_len;

	if (s1 == NULL)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	s1_len = gnl_strlen(s1);
	s2_len = gnl_strlen(s2);
	new_string = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (new_string == NULL || s1 == NULL)
		return (NULL);
	gnl_strlcpy(new_string, s1, s1_len + 1);
	gnl_strlcpy(new_string + s1_len, s2, s2_len + 1);
	free(s1);
	return (new_string);
}

size_t	gnl_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (gnl_strlen(src));
}

size_t	gnl_strlen(const char *s)
{
	const char	*p;

	p = s;
	while (*p)
		++p;
	return (p - s);
}

char	*gnl_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		i++;
	}
	return (0);
}
