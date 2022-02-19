/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:14:35 by tapetros          #+#    #+#             */
/*   Updated: 2021/04/19 16:55:14 by tapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putnbr_base(long n, int len, char *base)
{
	int out;

	out = 0;
	if (n < 0)
		n = -n;
	if (n >= len)
	{
		out += ft_putnbr_base(n / len, len, base);
		out += ft_putnbr_base(n % len, len, base);
	}
	else
		out += ft_putchar(base[n]);
	return (out);
}

int			ft_printf_s(va_list args, t_flags *flag)
{
	int		out;
	char	*str;
	int		i;
	int		spaces;

	out = 0;
	i = -1;
	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	flag->dot = (flag->dot > ft_strlen(str) ||
		flag->dot < 0 ? ft_strlen(str) : flag->dot);
	spaces = flag->width - flag->dot;
	if (flag->width && spaces > 0 && flag->minus == 0)
		while (spaces-- > 0)
			out += ft_putchar(' ');
	if (flag->dot > 0)
		while (flag->dot-- && str[++i])
			out += ft_putchar(str[i]);
	if (flag->minus == 1)
		while (spaces-- > 0)
			out += ft_putchar(' ');
	return (out);
}

int			ft_printf_d(va_list argument, t_flags *flag)
{
	int		out;
	int		spaces;
	int		a;
	int		zeros;
	char	zero;

	out = 0;
	a = va_arg(argument, int);
	zeros = (flag->dot - int_len(a, 10) < 0 ? 0 : flag->dot - int_len(a, 10));
	spaces = ((a == 0 && flag->dot == 0)
	? flag->width - zeros : flag->width - int_len(a, 10) - zeros);
	if (a < 0)
		spaces--;
	if (spaces > 0 && flag->minus == 0 && flag->zero == 0)
		while (spaces-- > 0)
			out += ft_putchar(' ');
	if (a < 0)
		out += ft_putchar('-');
	zero = (flag->dot >= 0) ? '0' : ' ';
	if (zeros > 0)
		while (zeros-- > 0)
			out += ft_putchar(zero);
	out = ft_printf_d_2(a, flag, spaces, out);
	return (out);
}

int			ft_printf_d_2(int a, t_flags *flag, int spaces, int out)
{
	if (flag->zero == 1)
		while (spaces-- > 0)
			out += ft_putchar('0');
	if (a != 0 || flag->dot != 0)
		out += ft_putnbr_base(a, 10, "0123456789");
	if (flag->minus == 1 && spaces > 0)
		while (spaces-- > 0)
			out += ft_putchar(' ');
	return (out);
}

int			ft_printf_u(va_list argument, t_flags *flag)
{
	int				out;
	int				spaces;
	unsigned int	a;
	int				zeros;
	char			zero;

	out = 0;
	zero = ' ';
	a = va_arg(argument, unsigned int);
	zeros = (flag->dot - int_len_u(a, 10) < 0 ?
		0 : flag->dot - int_len_u(a, 10));
	spaces = ((a == 0 && flag->dot == 0)
	? flag->width - zeros : flag->width - int_len_u(a, 10) - zeros);
	if (spaces > 0 && flag->minus == 0 && flag->zero == 0)
		while (spaces--)
			out += ft_putchar(' ');
	if (flag->dot >= 0)
		zero = '0';
	if (zeros > 0)
		while (zeros--)
			out += ft_putchar(zero);
	out = ft_printf_u_2(a, flag, spaces, out);
	return (out);
}
