/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:13:59 by aascedu           #+#    #+#             */
/*   Updated: 2022/11/23 13:12:07 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE];
	char		*result;
	int			length_read;
	int			i;

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	length_read = read(fd, buff, BUFFER_SIZE);
	if (length_read <= 0)
		return (NULL);
	result = ft_calloc(1, 1);
	result = ft_strjoin(result, buff);
	i = 0;
	while (ft_isnew(result, i) == -1)
	{
		length_read = read(fd, buff, BUFFER_SIZE);
		result = ft_strjoin(result, buff);
		i++;
	}
	if (length_read >= 0)
		ft_memmove(buff, buff - ft_isnew(buff, 0), (BUFFER_SIZE - ft_isnew(buff, 0)));
	result = ft_strdup_index(result, ft_isnew(result, i));

	return (result);
}
