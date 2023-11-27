/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:26:01 by jiko              #+#    #+#             */
/*   Updated: 2023/11/28 01:05:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

char	*ft_strjoin(char *s1, char *s2, int flag)
{
	char	*dest;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (flag)
		s1 = (char *)ft_calloc(1, sizeof(char));
	dest = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	while (s1[++i])
		dest[i] = s1[i];
	free(s1);
	while (s2[j])
		dest[i++] = s2[j++];
	return (dest);
}

char	*ft_get_line(char **str, int *i)
{
	char	*dest;

	*i = 0;
	while ((*str)[*i] && (*str)[*i] != '\n')
		(*i)++;
	if ((*str)[*i] == '\0')
	{
		dest = ft_strjoin(0, (*str), 1);
		return (dest);
	}
	dest = (char *)ft_calloc(*i + 2, sizeof(char));
	*i = 0;
	while ((*str)[*i] != '\n')
		dest[(*i)++] = (*str)[*i];
	dest[(*i)++] = '\n';
	return (dest);
}

char	*freeing(char **str, char *buf, char *dest)
{
	if (buf)
		free(buf);
	if (dest)
		free(dest);
	if (!str)
		return (0);
	if (*str)
	{
		free(*str);
		*str = 0;
	}
	return (NULL);
}

int	readline(int fd, int *i, char **str)
{
	char	*buf;

	*i = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		exit(1);
	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (*i > 0)
	{
		if (ft_strchr(*str, '\n'))
			break ;
		*i = read(fd, buf, BUFFER_SIZE);
		if (*i < 0)
			exit(1);
		if (!(*str) && *i == 0)
			return ((int)freeing(str, buf, NULL));
		buf[*i] = '\0';
		*str = ft_strjoin(*str, buf, !(*str));
	}
	freeing(&buf, NULL, NULL);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buf;
	char		*dest;
	int			i;
	int			flag;

	buf = NULL;
	flag = readline(fd, &i, &str);
	if (!flag)
		return (NULL);
	dest = ft_get_line(&str, &i);
	if (dest && (ft_strlen(str) != ft_strlen(dest)))
		buf = ft_strjoin(NULL, str + i, 1);
	free(str);
	str = buf;
	return (dest);
}
