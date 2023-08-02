/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:14:41 by yachen            #+#    #+#             */
/*   Updated: 2023/06/13 10:16:20 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_line(int fd, char	*str)
{
	char	*buffer;
	int		result;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	result = 1;
	while (result != 0 && ft_check_str(buffer))
	{
		result = read(fd, buffer, BUFFER_SIZE);
		if (result == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[result] = '\0';
		if (result == 0)
			break ;
		str = ft_strjoint(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*ft_get_line(char	*str)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	line = NULL;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (ft_strdup(str));
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	while (j != i)
	{
		line[j] = str[j];
		j++;
	}
	line[j] = '\n';
	line[j + 1] = '\0';
	return (line);
}

char	*ft_get_restline(char *str)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	j = 0;
	rest = NULL;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0' || (str[i] == '\n' && str[i + 1] == '\0'))
	{
		free(str);
		return (NULL);
	}
	i++;
	rest = (char *)malloc(sizeof(char) * ft_strlen(str) - i + 1);
	while (str[i])
		rest[j++] = str[i++];
	rest[j] = '\0';
	free(str);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[1024];

	line = NULL;
	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	str[fd] = ft_read_line(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_get_line(str[fd]);
	if (line == NULL)
		return (NULL);
	str[fd] = ft_get_restline(str[fd]);
	return (line);
}
