/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurascedu <arthurascedu@student.42ly    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:13:37 by aascedu           #+#    #+#             */
/*   Updated: 2022/11/28 20:15:41 by arthurasced      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		ft_strlen(char *str);
int		ft_newline(char *buff);
int		ft_index_nl(char *buff);
char	*ft_strjoin2(char *line, char *temp);
char	*ft_strjoin(char *line, char *buff);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	ft_bzero(void *s, size_t n);
char	*add_buffer(char *line, char *buff);
char	*get_next_line(int fd);

#endif
