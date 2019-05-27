/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 21:24:17 by yhetman           #+#    #+#             */
/*   Updated: 2019/01/03 15:05:52 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_itoa_base_fill(uintmax_t tmp, int base,
		char str[BUFF_SIZE], t_shit *print)
{
	int		length;

	if (tmp && !(print->params & POINTER)
		&& (print->params & FLAG_ZERO) && (print->params & FLAG_HASH)
		&& base == 16 && !(print->params & TYPE_LONG2) && print->writen > 3)
		print->writen -= 2;
	length = print->writen;
	print->type = 'a' - 10 - ((print->params & UPCASE) >> 1);
	while (length--)
	{
		str[length] = tmp % base + ((tmp % base < 10) ? '0' : print->type);
		tmp /= base;
	}
	(print->params & PRECIS && print->params & FLAG_ZERO) ? str[0] = ' ' : 0;
}

static void	ft_print_itoa_base_2(uintmax_t n, int b, char *str, t_shit *pr)
{
	ft_itoa_base_fill(n, b, str, pr);
	ft_buffering(pr, str, pr->writen);
	ft_filled(pr, 1);
}

void		ft_printf_itoa_base(uintmax_t n, int b, t_shit *pr)
{
	uintmax_t	tmp;
	char		str[21];
	int			ext;

	pr->writen = 0;
	tmp = n;
	while (tmp && ++pr->writen)
		tmp /= b;
	(pr->params & FLAG_ZERO) ? pr->precis = pr->min_length : 0;
	ext = (pr->writen >= pr->precis) ? 0 : 1;
	pr->writen = MAX(pr->precis, pr->writen);
	((pr->params & FLAG_HASH) && b == 8 && !ext) ? --pr->min_length : 0;
	((pr->params & FLAG_HASH) && b == 8 && !n && (pr->params & PRECIS)) ?
	++pr->writen : 0;
	((pr->params & FLAG_HASH) && b == 16
		&& !(pr->params & FLAG_ZERO)) ? pr->min_length -= 2 : 0;
	pr->filled = MAX(0, (pr->min_length - pr->writen));
	ft_filled(pr, 0);
	if ((n || (pr->params & POINTER))
		&& (pr->params & FLAG_HASH) && ((b == 8 && !ext) || (b == 16)))
		ft_buffering(pr, "0", 1);
	if ((n || (pr->params & POINTER)) && (pr->params & FLAG_HASH) && b == 16)
		ft_buffering(pr, (pr->params & UPCASE) ? "X" : "x", 1);
	ft_print_itoa_base_2(n, b, str, pr);
}

void		ft_printf_itoa(intmax_t n, t_shit *print, int length)
{
	char		str[21];
	uintmax_t	tmp;

	tmp = ABS(n);
	while (tmp)
	{
		tmp /= 10;
		++length;
	}
	if ((n < 0 || print->params & FLAG_PLUS
		|| print->params & FLAG_SPACE) && print->params & FLAG_ZERO)
		--print->precis;
	print->writen = MAX(length, print->precis);
	if (n < 0 || print->params & FLAG_PLUS || print->params & FLAG_SPACE)
		++print->writen;
	print->filled = (print->writen > print->min_length)
		? 0 : print->min_length - print->writen;
	ft_filled(print, 0);
	tmp = ABS(n);
	ft_itoa_base_fill(tmp, 10, str, print);
	(print->params & FLAG_SPACE) ? str[0] = ' ' : 0;
	(n < 0) ? str[0] = '-' : 0;
	(print->params & FLAG_PLUS && n >= 0) ? str[0] = '+' : 0;
	ft_buffering(print, str, print->writen);
	ft_filled(print, 1);
}
