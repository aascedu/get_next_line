#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# ifndef EOF
#  define EOF -1
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup_index(char *s1, size_t index);

int		ft_is_set(char *str, char c);
int		ft_index_nl(char *line, int i);

size_t	ft_strlen(char *str);

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

#endif
