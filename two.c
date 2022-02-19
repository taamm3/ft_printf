/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:11:15 by tapetros          #+#    #+#             */
/*   Updated: 2021/04/19 16:57:47 by tapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_dig_p(unsigned long long n, int len, char *base)
{
	int out;

	out = 0;
	if (n >= (unsigned long long)len)
	{
		out += ft_dig_p(n / len, len, base);
		out += ft_dig_p(n % len, len, base);
	}
	else
	{
		out += ft_putchar(base[n]);
	}
	return (out);
}

int		ft_putnbr_base_p(unsigned long long nbr)
{
	int					i;
	unsigned long long	n;
	int					out;
	char				*base;

	i = 0;
	out = 0;
	n = nbr;
	base = "0123456789abcdef";
	while (base[i] != '\0')
		i++;
	out += ft_dig_p(n, i, base);
	return (out);
}

int		ft_printf_p(va_list argument, t_flags *flag)
{
	unsigned long long	a;
	int					out;
	int					spaces;

	out = 0;
	a = (unsigned long long)va_arg(argument, void *);
	spaces = flag->width - int_len_p(a) - 2;
	if (spaces > 0 && !flag->minus)
		while (spaces--)
			out += ft_putchar(' ');
	out += ft_putstr("0x");
	out += ft_putnbr_base_p(a);
	if (flag->minus == 1 && spaces > 0)
		while (spaces--)
			out += ft_putchar(' ');
	return (out);
}

int		int_len_p(unsigned long long a)
{
	int		len;

	len = 0;
	if (a < 0)
		return (8);
	if (a == 0)
		return (1);
	while (a != 0)
	{
		a /= 16;
		++len;
	}
	return (len);
}

void	ft_init_flags(t_flags *flag)
{
	flag->dot = -1;
	flag->minus = 0;
	flag->asterisk = 0;
	flag->width = 0;
	flag->zero = 0;
}
