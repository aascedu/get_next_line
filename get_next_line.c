/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:13:59 by aascedu           #+#    #+#             */
/*   Updated: 2022/11/23 16:53:25 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;

	if (size > 0 && count > (SIZE_MAX / size))
		return (NULL);
	tab = malloc(count * size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, count * size);
	return (tab);
}

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

char	*add_buffer(char *buff, char *result)
{
	size_t	i;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	result = ft_strjoin(result, ft_strdup_index(buff, i));
	ft_memmove(buff, buff + i, BUFFER_SIZE - i + 1);
	ft_bzero(buff + BUFFER_SIZE - i, i);
	//printf("result:%s\n", result);
	return (result);
}


char	*read_buffer(int fd, char *buff, char *result)
{
	int	i;
	int	length_read;

	i = 0;
	length_read = read(fd, buff, BUFFER_SIZE);
	if (length_read == 0)
	{
		buff[BUFFER_SIZE] = EOF;
		return (free(result), NULL);
	}
	while (length_read == BUFFER_SIZE && !ft_is_set(buff, '\n'))
	{
		result = add_buffer(buff, result);
		length_read = read(fd, buff, BUFFER_SIZE);
	}
	if (length_read < BUFFER_SIZE)
	if (!ft_is_set(result, '\n'))
		result = add_buffer(buff, result);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1] = {0};
	char		*result;

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	if (ft_is_set(buff, EOF))
		return (NULL);
	result = ft_calloc(1, 1);
	if (buff[0] != '\0')
	{
		// printf("buffer = %s\n", buff);
		result = add_buffer(buff, result);
		if (ft_is_set(result, '\n'))
			return (result);
		// printf("result = %s\n", result);
	}
	result = read_buffer(fd, buff, result);
	return (result);
}
/*
#include <fcntl.h>

int	main(void)
{
	int	fd = open("get_next_line.h", O_RDONLY);
	char *input;

	input = get_next_line(fd);
	while (input)
	{
		printf("%s", input);
		free(input);
		input = get_next_line(fd);
	}
	close(fd);
	return (0);
}*/
