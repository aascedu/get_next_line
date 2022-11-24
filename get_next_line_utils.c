/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:13:52 by aascedu           #+#    #+#             */
/*   Updated: 2022/11/24 15:27:53 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_is_set(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_index_nl(char *line, int i)
{
	int	j;

	j = BUFFER_SIZE * i;
	while (line[j])
	{
		if (line[j] == '\n')
			return (j + 1);
		j++;
	}
	return (0);
}

char	*ft_strdup_index(char *s1, size_t index)
{
	size_t	i;
	char	*copy;

	copy = malloc(sizeof(char) * (index + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < index)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char *s1, char *s2, int size)
{
	char	*res;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	res = malloc(sizeof(char) * ((BUFFER_SIZE * size) + BUFFER_SIZE + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < BUFFER_SIZE * size)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < BUFFER_SIZE)
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	free(s1);
	//free(s2);
	return (res);
}
