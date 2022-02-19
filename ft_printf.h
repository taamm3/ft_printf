/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:06:49 by tapetros          #+#    #+#             */
/*   Updated: 2021/04/19 16:57:18 by tapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_flags
{
	int			dot;
	int			minus;
	int			asterisk;
	int			width;
	int			zero;
}				t_flags;

int				ft_putstr(char *str);
int				ft_strlen(const char *str);
int				ft_isdigit(int c);
int				ft_printf_hex(va_list argument, t_flags *flag);
void			ft_init_flags(t_flags *flag);
int				ft_dig_p(unsigned long long n, int len, char *base);
int				ft_putnbr_base_p(unsigned long long nbr);
int				ft_printf_p(va_list argument, t_flags *flag);
int				int_len_p(unsigned long long a);
int				ft_putnbr_base(long n, int len, char *base);
int				ft_printf_s(va_list args, t_flags *flag);
int				ft_printf_d(va_list argument, t_flags *flag);
int				ft_printf_c(va_list args, t_flags *flag);
int				conv_check(const char *format, int i, va_list args,
				t_flags *flag);
int				ft_putchar(char c);
int				int_len(int n, int k);
int				int_len_u(unsigned int n, int k);
int				flag_check(const char *format, int i, va_list args,
				t_flags *flag);
int				ft_printf(const char *format, ...);
int				ft_printf_upperhex(va_list argument, t_flags *flag);
int				ft_printf_percent(t_flags *flag);
int				ft_printf_u_2(unsigned int a,
				t_flags *flag, int spaces, int out);
int				ft_printf_d_2(int a, t_flags *flag, int spaces,
				int out);
int				flag_check_2(const char *format, int i,
				va_list args, t_flags *flag);
int				ft_printf_hex_2(unsigned int a, t_flags *flag,
				int spaces, int out);
int				ft_printf_upperhex_2(unsigned int a, t_flags *flag,
				int spaces, int out);
int				flag_check_3(const char *format, int i,
				va_list args, t_flags *flag);
int				ft_printf_u(va_list argument, t_flags *flag);

#endif
