/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 04:06:22 by jiko              #+#    #+#             */
/*   Updated: 2023/05/07 04:06:26 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_p(va_list *ap, int *count)
{
	char	*tmp;

	ft_putstr("0x", count);
	if (*count == -1)
		return ;
	tmp = va_arg(*ap, void *);
	if (tmp == NULL)
		ft_putchar('0', count);
	else
		print_adress((unsigned long long)tmp, count);
}
