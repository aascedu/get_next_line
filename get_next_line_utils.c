/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurascedu <arthurascedu@student.42ly    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:09:51 by arthurasced       #+#    #+#             */
/*   Updated: 2022/11/28 17:10:06 by arthurasced      ###   ########lyon.fr   */
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
