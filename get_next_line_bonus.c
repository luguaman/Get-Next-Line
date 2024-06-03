#include "get_next_line.h"

char	*ft_free(char *line, char *buf)
{
	char	*temp;

	temp = ft_strjoin(line, buf);
	free(line);
	return (temp);
}

char	*ft_next(char *line)
{
	int		i;
	int		j;
	char	*buf;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	buf = ft_calloc((ft_strlen(line) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (line[i])
		buf[j++] = line[i++];
	free(line);
	return (buf);
}

char	*ft_return(char *line)
{
	char	*buf;
	int		i;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	buf = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		buf[i] = line[i];
		i++;
	}
	if (line[i] && line[i] == '\n')
		buf[i++] = '\n';
	return (buf);
}

char	*read_file(int fd, char *line)
{
	char	*buffer;
	int		bytes;

	if (!line)
		line = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = 0;
		line = ft_free(line, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = read_file(fd, line);
	if (!line)
		return (NULL);
	ret = ft_return(line);
	line = ft_next(line);
	return (ret);
}
