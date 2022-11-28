/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurascedu <arthurascedu@student.42ly    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:05:04 by aascedu           #+#    #+#             */
/*   Updated: 2022/11/28 17:14:38 by arthurasced      ###   ########lyon.fr   */
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

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while (i < n)
		{
			((char *)s)[i] = 0;
			i++;
		}
	}
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
	temp = ft_strjoin2(line, temp);
	ft_memmove(buff, buff + i, BUFFER_SIZE - i);
	ft_bzero(buff + (BUFFER_SIZE - i), BUFFER_SIZE);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1] = {0};
	
	char		*line;
	int			byte_read;

if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = (char *)malloc(sizeof(char));
	if (!line)
		return (NULL);
	*line = 0;
	byte_read = 1;
	while (byte_read)
	{
		if (!buff[0])
		{
			byte_read = read(fd, buff, BUFFER_SIZE);
		}
		if (ft_newline(buff))
			return (add_buffer(line, buff));
		line = ft_strjoin(line, buff);
		byte_read = read(fd, buff, BUFFER_SIZE);
	}
	return (line);
}
/*
int	main(void)
{
	int	fd;

	fd = open("../../francinette/tests/get_next_line/gnlTester/files/alternate_line_nl_with_nl", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}
*/