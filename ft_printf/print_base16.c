/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base16.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:07:07 by jiko              #+#    #+#             */
/*   Updated: 2023/04/12 16:02:34 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_base16(unsigned int n, char flag, int *count)
{
	char	*base16;
	char	*base16_l;

	base16 = "0123456789abcdef";
	base16_l = "0123456789ABCDEF";
	if (n >= 16)
	{
		if (*count == -1)
			return (-1);
		print_base16(n / 16, flag, count);
		if (*count == -1)
			return (-1);
		print_base16(n % 16, flag, count);
	}
	else
	{
		if (flag == 'X')
			ft_putchar(base16_l[n], count);
		else
			ft_putchar(base16[n], count);
	}
	if (*count == -1)
		return (-1);
	return (0);
}
