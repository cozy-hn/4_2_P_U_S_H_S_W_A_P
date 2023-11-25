/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:57:39 by jiko              #+#    #+#             */
/*   Updated: 2023/04/12 16:11:18 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int n, int *count)
{
	if (n >= 10)
	{
		ft_putunbr(n / 10, count);
		if (*count == -1)
			return (-1);
	}
	if (ft_putchar(n % 10 + '0', count) == -1)
		return (-1);
	return (0);
}
