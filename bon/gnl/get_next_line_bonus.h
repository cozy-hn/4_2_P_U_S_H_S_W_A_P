/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 04:18:52 by jiko              #+#    #+#             */
/*   Updated: 2023/11/29 17:06:01 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_get_line(char **str, int *i);
char	*ft_strjoin(char *s1, char *s2, int flag);
char	*ft_strchr(char *str, char c);
char	*freeing(char **str, char *buf, char *dest);
int		readline(int fd, int *i, char **str);

#endif