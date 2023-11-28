/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:13:27 by luguaman          #+#    #+#             */
/*   Updated: 2023/11/27 17:56:42 by luguaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cpy(char *str,char *s, int pos)
{
	int		i;

	i = 0;
	while (str[pos] != '\0')
	{
		if (str[pos + 1] == '\0')
		{
			i++;
			break ;
		}
		if (str[pos] == '\n')
		{
			s[i] = '\n';
			i++;
			break ;
		}
		s[i] = str[pos];
		pos++;
		i++;
	}
	s[i] = '\0';
	return (s);
}

void	open_file(int fd, char *str)
{
	ssize_t	bytes;

	bytes = read(fd, str, BUFFER_SIZE);
	str[bytes] = '\0';
}
