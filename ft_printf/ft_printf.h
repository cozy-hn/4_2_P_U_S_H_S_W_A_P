/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 22:54:35 by jiko              #+#    #+#             */
/*   Updated: 2023/05/07 04:07:45 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(char c, int *count);
int		ft_putstr(char *str, int *count);
int		ft_putnbr(int n, int *count, char flag);
int		ft_putunbr(unsigned int n, int *count);
int		print_base16(unsigned int n, char flag, int *count);
int		print_adress(unsigned long long n, int *count);
int		ft_printf(const char *format, ...);
void	print_format(va_list *ap, int *count, char c);
void	print_p(va_list *ap, int *count);
void	print_s(va_list *ap, int *count);

#endif