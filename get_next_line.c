/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurascedu <arthurascedu@student.42ly    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:13:59 by aascedu           #+#    #+#             */
/*   Updated: 2022/11/22 16:29:06 by arthurasced      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	int			length_read;
	int			i;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	length_read = read(fd, buff, BUFFER_SIZE);
	buff[length_read] = '\0';
	line = ft_strdup(buff);
	while (length_read != 0 && ft_isnew(line) == 0)
	{
		length_read = read(fd, buff, BUFFER_SIZE);
		line = ft_strjoin(line, buff);
	}
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	line = ft_strdup_index(line, i + 1);
	return (line);
}
