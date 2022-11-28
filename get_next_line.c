/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:05:04 by aascedu           #+#    #+#             */
/*   Updated: 2022/11/28 15:04:02 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_newline(char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_index_nl(char *buff)
{
	int	i;

	i = -1;
	while (buff[++i])
	{
		if (buff[i] == '\n')
		{
			i++;
			break;
		}
	}
	return (i);
}

char	*ft_strjoin2(char *line, char *temp)
{
	char	*result;
	int		line_len;
	int		temp_len;
	int		i;

	line_len = ft_strlen(line);
	temp_len = ft_strlen(temp);
	result = (char *)malloc(sizeof(char) * (line_len + temp_len + 1));
	if (!result)
		return (NULL);
	i = -1;
	while (line[++i])
		result[i] = line[i];
	i = -1;
	while (temp[++i])
		result[line_len + i] = temp[i];
	result[line_len + temp_len] = '\0';
	free(line);
	free(temp);
	return (result);
}

char	*ft_strjoin(char *line, char *buff)
{
	char	*result;
	int		line_len;
	int		i;
	int		j;

	line_len = ft_strlen(line);
	result = (char *)malloc(sizeof(char) * (line_len + BUFFER_SIZE + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (line[i])
	{
		result[i] = line[i];
		i++;
	}
	j = 0;
	while (buff[j])
	{
		result[i + j] = buff[j];
		j++;
	}
	result[i + j] = '\0';
	free(line);
	return (result);
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
	ft_memmove(buff, buff + i, BUFFER_SIZE - i - 1);
	ft_bzero(buff + (BUFFER_SIZE - i), BUFFER_SIZE);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1] = {0};
	char		*line;
	int			byte_read;

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
