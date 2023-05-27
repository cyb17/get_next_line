/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:44:06 by yachen            #+#    #+#             */
/*   Updated: 2023/05/27 13:35:25 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);
int		ft_check_str(char *str);
int		ft_strlen(char *str);
void	ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *str);
char	*ft_strjoint(char *s1, char *s2);
char	*ft_make_str_n(char *buffer);

#endif
