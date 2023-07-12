/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruilhan <ruilhan@student.42.fr>          +#+  +:+       +#+          */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:01:15 by ruilhan          #+#    #+#             */
/*   Updated: 2022/02/02 13:20:00 by ruilhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *all_line, char *str)
{
	int		i;
	int		j;
	char	*arr;

	if (!all_line)
	{
		all_line = (char *)malloc(sizeof(char));
		all_line[0] = '\0';
	}
	if (!all_line || !str)
		return (0);
	i = ft_strlen(all_line) + ft_strlen(str);
	arr = (char *)malloc(sizeof(char) * i + 1);
	if (!arr)
		return (0);
	i = 0;
	j = 0;
	while (all_line[i] != '\0')
		arr[j++] = all_line[i++];
	i = 0;
	while (str[i] != '\0')
		arr[j++] = str[i++];
	arr[ft_strlen(all_line) + ft_strlen(str)] = '\0';
	free(all_line);
	return (arr);
}

char	*ft_get_line(char *all_line)
{
	int		i;
	char	*line;

	i = 0;
	if (!all_line[i])
		return (0);
	while (all_line[i] != '\n' && all_line[i] != '\0')
		i++;
	line = (char *)malloc(sizeof(char) * i + 2);
	if (!line)
		return (0);
	i = 0;
	while (all_line[i] != '\n' && all_line[i] != '\0')
	{
		line[i] = all_line[i];
		i++;
	}
	if (all_line[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_get_next_line(char *all_line)
{
	int		i;
	int		j;
	char	*new_all_line;

	i = 0;
	while (all_line[i] != '\n' && all_line[i] != '\0')
		i++;
	if (all_line[i] == '\0')
	{
		free(all_line);
		return (0);
	}
	j = ft_strlen(all_line);
	new_all_line = (char *)malloc(sizeof(char) * (j - i) + 1);
	if (!new_all_line)
		return (0);
	i++;
	j = 0;
	while (all_line[i] != '\0')
		new_all_line[j++] = all_line[i++];
	new_all_line[j] = '\0';
	free(all_line);
	return (new_all_line);
}
