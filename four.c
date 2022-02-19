/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:13:19 by tapetros          #+#    #+#             */
/*   Updated: 2021/04/19 16:55:52 by tapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_u_2(unsigned int a,
		t_flags *flag, int spaces, int out)
{
	if (flag->zero == 1)
		while (spaces--)
			out += ft_putchar('0');
	if (a != 0 || flag->dot != 0)
		out += ft_putnbr_base(a, 10, "0123456789");
	if (flag->minus == 1 && spaces > 0)
		while (spaces--)
			out += ft_putchar(' ');
	return (out);
}

int			ft_printf_percent(t_flags *flag)
{
	int out;
	int spaces;
	int zeros;
	int zero;

	out = 0;
	zeros = (flag->dot - 1 < 0 ? 0 : flag->dot - 1);
	spaces = ((flag->dot == 0)
	? flag->width - zeros : flag->width - 1 - zeros);
	if (spaces > 0 && flag->minus == 0 && flag->zero == 0)
		while (spaces--)
			out += ft_putchar(' ');
	zero = (flag->dot >= 0) ? '0' : ' ';
	if (zeros > 0)
		while (zeros--)
			out += ft_putchar(zero);
	if (flag->zero == 1)
		while (spaces--)
			out += ft_putchar('0');
	if (flag->dot != 0)
		out += ft_putchar('%');
	if (flag->minus == 1 && spaces > 0)
		while (spaces--)
			out += ft_putchar(' ');
	return (out);
}

int			conv_check(const char *format, int i, va_list args, t_flags *flag)
{
	int	out;

	out = 0;
	if (format[i] == 's')
		out += ft_printf_s(args, flag);
	else if (format[i] == 'd' || format[i] == 'i')
		out += ft_printf_d(args, flag);
	else if (format[i] == 'x')
		out += ft_printf_hex(args, flag);
	else if (format[i] == 'X')
		out += ft_printf_upperhex(args, flag);
	else if (format[i] == 'c')
		out += ft_printf_c(args, flag);
	else if (format[i] == 'p')
		out += ft_printf_p(args, flag);
	else if (format[i] == 'u')
		out += ft_printf_u(args, flag);
	else if (format[i] == '%')
		out += ft_printf_percent(flag);
	return (out);
}
