/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:53:55 by jiko              #+#    #+#             */
/*   Updated: 2023/04/12 16:11:33 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int *count, char flag)
{
	long	tmp;

	if (flag == 'u')
		return (ft_putunbr((unsigned int)n, count));
	tmp = (long)n;
	if (tmp < 0)
	{
		if (ft_putchar('-', count) == -1)
			return (-1);
		tmp = -tmp;
	}
	if (tmp >= 10)
	{
		ft_putnbr(tmp / 10, count, flag);
		if (*count == -1)
			return (-1);
	}
	if (ft_putchar(tmp % 10 + '0', count) == -1)
		return (-1);
	return (0);
}
