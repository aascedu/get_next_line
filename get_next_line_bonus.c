/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:05:04 by aascedu           #+#    #+#             */
/*   Updated: 2022/12/02 13:04:15 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	if (dst > src)
	{
		while (i < len)
		{
			((char *)dst)[len - i - 1] = ((char *)src)[len - i - 1];
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}

char	*add_buffer(char *line, char *buff)
{
	char	*temp;
	int		i;
	int		j;

	i = ft_index_nl(buff);
	temp = (char *)malloc(sizeof(char) * (i + 1));
	if (!temp)
		return (NULL);
	j = -1;
	while (++j < i)
		temp[j] = buff[j];
	temp[j] = '\0';
	temp = ft_strjoin(line, temp);
	if (!temp)
		return (NULL);
	ft_memmove(buff, buff + i, BUFFER_SIZE - i);
	ft_bzero(buff + (BUFFER_SIZE - i), ft_strlen(buff + (BUFFER_SIZE - i)));
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	buff[OPEN_MAX][BUFFER_SIZE + 1] = {{0}};
	char		*line;
	int			byte_read;

	if (fd < 0)
		return (NULL);
	if (fd > OPEN_MAX || BUFFER_SIZE <= 0 || read(fd, NULL, 0) != 0)
		return (ft_bzero(buff[fd], BUFFER_SIZE), NULL);
	line = (char *)malloc(sizeof(char));
	if (!line)
		return (NULL);
	*line = 0;
	byte_read = 1;
	if (!buff[fd][0])
		byte_read = read(fd, buff[fd], BUFFER_SIZE);
	if (byte_read <= 0)
		return (free(line), NULL);
	while (byte_read)
	{
		if (ft_newline(buff[fd]))
			return (add_buffer(line, buff[fd]));
		line = add_buffer(line, buff[fd]);
		byte_read = read(fd, buff[fd], BUFFER_SIZE);
	}
	return (add_buffer(line, buff[fd]));
}
