/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:11:16 by yachen            #+#    #+#             */
/*   Updated: 2023/05/27 15:08:15 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_restofstr(char *buffer)
{
	int		i;
	char	*rest;

	i = 0;
	while (buffer[i] != '\n')
		i++;
	rest = (char *)malloc(sizeof(char) * (BUFFER_SIZE - i));
	while (BUFFER_SIZE - i > 0)
	{
		*rest++ = buffer[i];
		i++;
	}
	*rest++ = '\0';
	return (rest);
}

static char	*ft_mkestr(char *keep, char *buffer, char *rest, int fd)
{
	ssize_t	result;

	result = read(fd, buffer, BUFFER_SIZE);
	if (result <= 0)
	{
		free(buffer);
		return (NULL);
	}
	while (result > 0 && ft_check_str(buffer))
	{
		if (!keep)
			keep = ft_strdup(buffer);
		else
			keep = ft_strjoint(keep, buffer);
		read(fd, buffer, BUFFER_SIZE);
	}
	if (result == 0)
		return (keep);
	else if (!ft_check_str(buffer))
	{
		keep = ft_strjoint(keep, ft_make_str_n(buffer));
		rest = ft_restofstr(buffer);
	}
	free(buffer);
	return (keep);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char 		*keep;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	keep = NULL;
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!rest)
		ft_mkestr(keep, buffer, rest,  fd);
	else
	{
		keep = ft_strdup(rest);
		free(rest);
		ft_mkestr(keep, buffer, rest, fd);
	}
	return (keep);
}
