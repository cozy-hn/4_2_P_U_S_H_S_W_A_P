/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_adress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:10:02 by jiko              #+#    #+#             */
/*   Updated: 2023/04/12 16:05:07 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_adress(unsigned long long n, int *count)
{
	char	*base16;

	base16 = "0123456789abcdef";
	if (n >= 16)
	{
		if (*count == -1)
			return (-1);
		print_adress(n / 16, count);
		if (*count == -1)
			return (-1);
		print_adress(n % 16, count);
	}
	else
	{
		if (ft_putchar(base16[n], count) == -1)
			return (-1);
	}
	return (0);
}
