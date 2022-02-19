/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:11:58 by tapetros          #+#    #+#             */
/*   Updated: 2021/04/19 16:59:25 by tapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_upperhex(va_list argument, t_flags *flag)
{
	int				out;
	unsigned int	a;
	int				spaces;
	int				zeros;
	char			zero;

	out = 0;
	zero = ' ';
	a = va_arg(argument, unsigned int);
	zeros = (flag->dot - int_len_u(a, 16) < 0
	? 0 : flag->dot - int_len_u(a, 16));
	spaces = ((a == 0 && flag->dot == 0)
	? flag->width - zeros : flag->width - int_len_u(a, 16) - zeros);
	zero = (flag->dot >= 0) ? '0' : ' ';
	if (spaces > 0 && flag->minus == 0 && flag->zero == 0)
		while (spaces-- > 0)
			out += ft_putchar(' ');
	if (zeros > 0)
		while (zeros-- > 0)
			out += ft_putchar(zero);
	out = ft_printf_upperhex_2(a, flag, spaces, out);
	return (out);
}

int			ft_printf_upperhex_2(unsigned int a, t_flags *flag,
		int spaces, int out)
{
	if (flag->zero == 1)
		while (spaces-- > 0)
			out += ft_putchar('0');
	if (a < 0)
		out += ft_putnbr_base(4294967295 + a, 16, "0123456789ABCDEF");
	if (a != 0 || flag->dot != 0)
		out += ft_putnbr_base(a, 16, "0123456789ABCDEF");
	if (flag->minus == 1)
		while (spaces-- > 0)
			out += ft_putchar(' ');
	return (out);
}

int			ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int			int_len(int n, int k)
{
	int len;

	len = 0;
	if (n < 0)
		n = -n;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= k;
		++len;
	}
	return (len);
}

int			ft_printf_c(va_list args, t_flags *flag)
{
	int	out;
	int	c;

	out = 0;
	c = va_arg(args, int);
	if (flag->minus == 0)
		while (flag->width - 1 > 0)
		{
			flag->width--;
			out += ft_putchar(' ');
		}
	out += ft_putchar(c);
	if (flag->minus == 1)
		while (flag->width - 1 > 0)
		{
			flag->width--;
			out += ft_putchar(' ');
		}
	return (out);
}
