#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		search_n(char *current);

int		get_next_line(int fd, char **line);

#endif
