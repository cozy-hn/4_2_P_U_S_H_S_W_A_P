/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:13:31 by jiko              #+#    #+#             */
/*   Updated: 2023/11/25 19:42:56 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_error()
{
    write(2, "Error\n", 6);
    exit(1);
}

int min_max(int a, int b, int flag)
{
	if (flag == 0)
	{
		if (a < b)
			return (a);
		return (b);
	}
	else
	{
		if (a > b)
			return (a);
		return (b);
	}
}

int get_min_idx_arr(int *arr, int size)
{
	int i;
	int min;
	int min_idx;

	i = 0;
	min = 2147483647;
	while (i < size)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			min_idx = i;
		}
		i++;
	}
	return (min_idx);
}

void	*ft_memset(void *str, int value, size_t size)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)str;
	while (size--)
		*tmp++ = value;
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*rtm;

	rtm = malloc(count * size);
	if (!rtm)
		print_error();
	ft_memset(rtm, 0, count * size);
	return (rtm);
}