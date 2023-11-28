/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:36:46 by luguaman          #+#    #+#             */
/*   Updated: 2023/11/28 16:53:31 by luguaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int	pos = 0;
	static char	str[BUFFER_SIZE + 1];
	char		*s;
	int			size;

	if (fd == -1)
		return (NULL);
	if (pos == 0)
		open_file(fd, str);
	size = 0;
	if (str[pos] != '\0')
	{
		while (str[pos + size] != '\n')
		{
			size++;
			if (str[pos + size] == '\0')
				break ;
		}
		s = malloc(size + 1);
		if (!s)
			return (NULL);
		s = cpy(str, s, pos);
		pos += size + 1;
		return (s);
	}
	return (NULL);
}

int main()
{
	int		fd;
	int		i;

	i = 0;
	fd = open("prueba.txt", O_RDONLY);
	while (i++ < 9)
	{
		printf("%d- %s", i, get_next_line(fd));
	}
	close(fd);
	return 0;
}
