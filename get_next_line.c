#include "get_next_line.h"

static char	*moving_pointer(char *old_string)
{
	char	*new_string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!old_string)
		return (0);
	while (old_string[i] != '\0' && old_string[i] != '\n')
		i++;
	if (!old_string[i])
	{
		free(old_string);
		return (0);
	}
	new_string = malloc(sizeof(char) * ((ft_strlen(old_string) - i) + 1));
	if (!new_string)
		return (0);
	i++;
	while (old_string[i] != '\0')
		new_string[j++] = old_string[i++];
	new_string[j] = '\0';
	free(old_string);
	return (new_string);
}

static char	*write_to_delim(char *current)
{
	char	*line;
	int		i;

	i = 0;
	while (current[i] != '\n' && current[i] != '\0')
	{
		i++;
	}
	line = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (current[i] != '\n' && current[i] != '\0')
	{
		line[i] = current[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static int	what_to_return(int reading)
{
	if (reading == 0)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*current;
	char		*buff;
	int			reading;

	reading = 1010;
	if (BUFFER_SIZE < 1 || fd < 0 || fd > 999 ||line == NULL)
		return (-1);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	while (!search_n(current) && reading != 0)
	{
		reading = read(fd, buff, BUFFER_SIZE);
		if (reading == -1)
		{
			free(buff);
			return (0);
		}
		buff[reading] = '\0';
		current = ft_strjoin(current, buff);
	}
	free(buff);
	*line = write_to_delim(current);
	current = moving_pointer(current);
	return (what_to_return(reading));
}
