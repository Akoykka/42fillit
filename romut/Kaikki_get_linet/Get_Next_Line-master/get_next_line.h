#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# define BUFF_SIZE 1


///muista poistaa naa
# include <stdio.h>
# include <string.h>
///muista poistaa naa

size_t	ft_strlen(const char *s);
int		get_next_line(const int fd, char **line);
void	ft_strdel(char **as);
char	*ft_strndup(const char *s1, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcpy(char *dst, const char *src);
void	*ft_memalloc(size_t size);
char	*ft_strnew(size_t size);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putendl_fd(char const *s, int fd);
#endif