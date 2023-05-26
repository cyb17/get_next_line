/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:11:16 by yachen            #+#    #+#             */
/*   Updated: 2023/05/26 19:24:21 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_mkestr(char *keep, int fd)
{
	char 	*buffer;
	ssize_t	result;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
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
			ft_strjoint(keep, buffer);
	}
	if (result == 0)
		return (keep);
	else if (!ft_check_str(buffer))
		ft_strjoint(keep, ft_make_str_n(buffer));
	free(buffer)
	return (keep);
}

char	*get_next_line(int fd)
{
	static char *keep;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	ft_mkestr(keep, fd);
	return (keep);
}
