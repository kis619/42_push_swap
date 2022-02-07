/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:46:15 by kmilchev          #+#    #+#             */
/*   Updated: 2021/12/13 12:46:15 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/***/
char	*read_to_nl_or_eof(int fd, char *buf)
{
	char	*read_buf;
	ssize_t	read_chars;

	read_chars = 69;
	read_buf = (char *)malloc(BUFFER_SIZE + 1);
	if (read_buf == NULL)
		return (NULL);
	while (read_chars != 0 && !(gnl_strchr(buf, '\n')))
	{
		read_chars = read(fd, read_buf, BUFFER_SIZE);
		if (read_chars == -1)
		{
			free(read_buf);
			return (NULL);
		}
		read_buf[read_chars] = '\0';
		buf = gnl_strjoin(buf, read_buf);
	}
	free(read_buf);
	return (buf);
}

char	*trim_up_to_nl(char *line)
{
	char	*new;
	int		i;

	if (line[0] == '\0')
		return (NULL);
	new = (char *)malloc(gnl_strlen(line) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		new[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		new[i] = '\n';
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*update_buffer(char *buf)
{
	char	*new;
	int		i;
	int		idx;

	i = 0;
	idx = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (buf[i] == '\0')
	{
		free(buf);
		return (NULL);
	}
	new = malloc(gnl_strlen(buf) - i + 1);
	if (new == NULL)
		return (NULL);
	while (buf[++i])
		new[idx++] = buf[i];
	new[idx] = '\0';
	free (buf);
	return (new);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buf;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	buf = read_to_nl_or_eof(fd, buf);
	if (buf == NULL)
		return (NULL);
	line = trim_up_to_nl(buf);
	buf = update_buffer(buf);
	return (line);
}
