/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:16:13 by aascedu           #+#    #+#             */
/*   Updated: 2022/11/29 10:19:06 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char	*add_buffer(char *line, char *buff);
char	*ft_strjoin(char *line, char *buff);

char	*ft_strjoin2(char *line, char *temp);
char	*get_next_line(int fd);

int		ft_strlen(char *str);
int		ft_newline(char *buff);
int		ft_index_nl(char *buff);

void	*ft_memmove(void *dst, const void *src, size_t len);
void	ft_bzero(void *s, size_t n);

#endif
