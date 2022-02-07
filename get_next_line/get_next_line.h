/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:46:25 by kmilchev          #+#    #+#             */
/*   Updated: 2021/12/13 12:46:25 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*read_to_nl_or_eof(int fd, char *line);
char	*gnl_strjoin(char *s1, char *s2);
size_t	gnl_strlcpy(char *dest, const char *src, size_t size);
size_t	gnl_strlen(const char *s);
char	*gnl_strchr(char *str, int c);

#endif