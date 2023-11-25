/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 04:06:43 by jiko              #+#    #+#             */
/*   Updated: 2023/06/24 19:16:28 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_format(va_list *ap, int *count, char c)
{
	if (c == 'd' || c == 'i' || c == 'u')
		ft_putnbr(va_arg(*ap, int), count, c);
	else if (c == 's')
		print_s(ap, count);
	else if (c == 'c')
		ft_putchar(va_arg(*ap, int), count);
	else if (c == '%')
		ft_putchar('%', count);
	else if (c == 'x' || c == 'X')
		print_base16(va_arg(*ap, unsigned int), c, count);
	else if (c == 'p')
		print_p(ap, count);
	else
		*count = -1;
}
