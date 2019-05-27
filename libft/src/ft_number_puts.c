/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_puts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 20:17:52 by yhetman           #+#    #+#             */
/*   Updated: 2019/01/03 14:05:39 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void		ft_nbput(t_shit *print)
{
	intmax_t	n;

	if (print->params & TYPE_LONG || print->params & TYPE_LONG2)
		n = (print->params & TYPE_LONG2)
		? ((intmax_t)va_arg(print->ap, long long)) :
			((intmax_t)va_arg(print->ap, long));
	else if (print->params & TYPE_SHORT || print->params & TYPE_SHORT2)
		n = (print->params & TYPE_SHORT2)
		? (intmax_t)((char)va_arg(print->ap, int)) :
			(intmax_t)((short)va_arg(print->ap, int));
	else if (print->params & TYPE_INTMAX)
		n = (va_arg(print->ap, intmax_t));
	else if (print->params & TYPE_SIZET)
		n = ((intmax_t)va_arg(print->ap, size_t));
	else
		n = ((intmax_t)va_arg(print->ap, int));
	(print->params & FLAG_ZERO) ? print->precis = print->min_length : 0;
	ft_printf_itoa(n, print, 0);
}

void		ft_nbput_base(int base, t_shit *print)
{
	uintmax_t	n;

	if (print->params & TYPE_LONG || print->params & TYPE_LONG2)
		n = (print->params & TYPE_LONG2)
		? ((intmax_t)va_arg(print->ap, unsigned long long)) :
			((intmax_t)va_arg(print->ap, unsigned long));
	else if (print->params & TYPE_SHORT || print->params & TYPE_SHORT2)
		n = (print->params & TYPE_SHORT2)
		? (uintmax_t)((unsigned char)va_arg(print->ap, int))
			: (uintmax_t)((unsigned short)va_arg(print->ap, int));
	else if (print->params & TYPE_INTMAX)
		n = (va_arg(print->ap, uintmax_t));
	else if (print->params & TYPE_SIZET)
		n = ((uintmax_t)va_arg(print->ap, size_t));
	else
		n = (uintmax_t)va_arg(print->ap, unsigned int);
	ft_printf_itoa_base(n, base, print);
}

static void	ft_ldtoa_fill(double num, t_shit *print, long value)
{
	int		len;
	int		rigor;
	char	str[48];

	len = print->writen - 1 - print->precis;
	rigor = print->writen - 1 - len;
	while (rigor--)
	{
		str[len + rigor + 1] = value % 10 + '0';
		value /= 10;
	}
	(print->precis > 0) ? str[len] = '.' : 0;
	value = (long)(ABS(num));
	while (++rigor < len)
	{
		str[len - rigor - 1] = value % 10 + '0';
		value /= 10;
	}
	(print->params & PRECIS && print->params & FLAG_ZERO) ? str[0] = ' ' : 0;
	(print->params & FLAG_SPACE) ? str[0] = ' ' : 0;
	(num < 0) ? str[0] = '-' : 0;
	(print->params & FLAG_PLUS && num >= 0) ? str[0] = '+' : 0;
	ft_buffering(print, str, len + 1 + 6);
}

void		ft_putfloats(t_shit *print)
{
	double		num;
	long		tmp;
	int			len;
	double		decimal;
	long		value;

	num = (double)va_arg(print->ap, double);
	(print->params & FLAG_ZERO) ? print->precis = print->min_length : 0;
	if (!(print->params & PRECIS))
		print->precis = 6;
	len = (print->precis > 0) ? 1 : 0;
	tmp = (long)(ABS(num));
	while (tmp && ++len)
		tmp /= 10;
	(print->params & FLAG_ZERO) ? print->precis = print->min_length : 0;
	print->writen = print->precis + len + ((num < 0) ? 1 : 0);
	decimal = ((num < 0.0f) ? -num : num);
	decimal = (decimal - (long)(((num < 0.0f) ? -num : num)))
	* ft_pow(10, print->precis + 1);
	decimal = ((long)decimal % 10 > 4) ? (decimal) / 10 + 1 : decimal / 10;
	value = (int)decimal;
	ft_ldtoa_fill(num, print, value);
}
