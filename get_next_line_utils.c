/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:18:14 by yachen            #+#    #+#             */
/*   Updated: 2023/06/13 10:18:30 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoint(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	while (s1[i])
		s3[j++] = s1[i++];
	s3[j] = '\0';
	while (s2[k])
		s3[j++] = s2[k++];
	s3[j] = '\0';
	free(s1);
	return (s3);
}

char	*ft_strdup(char *str)
{
	char	*duplicate;
	int		i;

	i = 0;
	duplicate = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!duplicate)
		return (NULL);
	while (str[i])
	{
		duplicate[i] = str[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}
