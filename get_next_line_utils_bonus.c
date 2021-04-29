#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char			*join;
	unsigned int	sumlen;
	size_t			i;
	size_t			j;
	unsigned int	len1;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	len1 = ft_strlen(s1);
	sumlen = len1 + ft_strlen(s2);
	join = malloc((sumlen + 1) * sizeof(char));
	if (!join)
		return (0);
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	return (join);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s1[i])
	{
		len++;
		i++;
	}
	copy = malloc((len + 1) * (sizeof(char)));
	if (!copy)
	{
		return (0);
	}
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int	search_n(char *current)
{
	int	i;

	i = 0;
	if (!current)
		return (0);
	while (current[i] != '\0')
	{
		if (current[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

