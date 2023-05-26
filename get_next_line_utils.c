/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:50:11 by yachen            #+#    #+#             */
/*   Updated: 2023/05/26 19:24:25 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_str(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (0);
		str++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (*str)
		i++;
	return (i);
}

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strdup(char *str)
{
	char	*duplicate;

	duplicate = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))
	ft_strcpy(duplicate, str);
	return (duplicate);
}

char	*ft_strjoint(char *s1, char *s2)
{
	int		i;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	ft_strcpy(s3, s1);
	ft_strcpy(s3 + ft_strlen(s1), s2);
	return (s3);
}

char	*ft_make_str_n(char *buffer)
{
	int 	i;
	int		j;
	char	*str_n;

	i = 0;
	j = 0;
	while (buffer[i] != '\n')
		i++;
	str_n = (char *)malloc(sizeof(char) * i + 2);
	if (!str_n)
		return (NULL);
	while (i >= 0)
	{
		str_n[j] = buffer[j];
		j++;
	}
	str_n[j] = '\0';
	return (str_n);
}
