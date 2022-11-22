/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:13:59 by aascedu           #+#    #+#             */
/*   Updated: 2022/11/22 10:41:14 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	int			length_read;

	length_read = read(fd, buff, BUFFER_SIZE);
	buff[BUFFER_SIZE + 1] = '\0';
	if (length_read == BUFFER_SIZE && buff[BUFFER_SIZE] != '\n')
	
}
