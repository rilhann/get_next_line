/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruilhan <ruilhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:54:11 by ruilhan          #+#    #+#             */
/*   Updated: 2022/02/02 13:22:26 by ruilhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_all_line(int fd, char *all_line)
{
	char	*str;
	int		read_byte;

	str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
		return (0);
	read_byte = 1;
	while (!ft_strchr(all_line, '\n') && read_byte != 0)
	{
		read_byte = read(fd, str, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(str);
			return (0);
		}
		str[read_byte] = '\0';
		all_line = ft_strjoin(all_line, str);
	}
	free(str);
	return (all_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*all_line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	all_line = get_all_line(fd, all_line);
	if (!all_line)
	{
		free(all_line);
		return (0);
	}
	line = ft_get_line(all_line);
	all_line = ft_get_next_line(all_line);
	return (line);
}
/*
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("text/test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
}
*/