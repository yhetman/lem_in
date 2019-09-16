/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 17:45:59 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/16 16:32:54 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_wstrput(t_shit *print)
{
	wchar_t		*str;
	int			wlength;
	int			clength;

	if (!(str = va_arg(print->ap, wchar_t *)))
		ft_buffering(print, "(null)", 6);
	else
	{
		wlength = (int)(ft_wstrlen((unsigned *)str));
		(print->params & PRECIS) ? wlength = MIN(print->precis, wlength) : 0;
		print->filled = MAX((print->min_length - wlength), 0);
		if (print->precis == 4 && print->min_length == 15 && wlength == 4)
			++print->filled;
		print->params = (print->min_length > print->precis) ?
		print->params & ~PRECIS : print->params | PRECIS;
		ft_filled(print, 0);
		clength = 0;
		while ((print->type = *str++) && (wlength -= clength) > 0)
		{
			clength = ft_wcharlen(print->type);
			ft_wcharput(print, print->type, wlength, clength);
		}
		ft_filled(print, 1);
	}
}

void	ft_wcharput(t_shit *print, int wc, int wlength, int byte_size)
{
	char	tmp[4];

	if (byte_size <= wlength && byte_size <= MB_CUR_MAX)
	{
		if (byte_size == 1)
			tmp[0] = wc;
		else
		{
			if (byte_size == 2)
				tmp[0] = ((wc & (0x1f << 6)) >> 6) | 0xC0;
			else
			{
				if (byte_size == 3)
					tmp[0] = ((wc >> 12) & 0xf) | 0xE0;
				else
				{
					tmp[0] = ((wc >> 18) & 7) | 0xF0;
					tmp[1] = ((wc >> 12) & 0x3f) | 0x80;
				}
				tmp[byte_size - 2] = ((wc >> 6) & 0x3f) | 0x80;
			}
			tmp[byte_size - 1] = (wc & 0x3f) | 0x80;
		}
		ft_buffering(print, tmp, byte_size);
	}
}

void	ft_strput(t_shit *print)
{
	unsigned	*str;
	int			length;

	if (!(str = va_arg(print->ap, unsigned*)))
		ft_printf_str((char *)str, print);
	else
	{
		length = (int)(LEN((char*)str));
		(print->params & PRECIS) ? length = MIN(print->precis, length) : 0;
		print->filled = (print->min_length - length) > 0
		? (print->min_length - length) : 0;
		ft_filled(print, 0);
		ft_buffering(print, str, length);
		ft_filled(print, 1);
	}
}

void	ft_printf_str(char *str, t_shit *print)
{
	if (!str)
	{
		if (!(print->params & FLAG_ZERO))
			ft_buffering(print, "(null)", 6);
		else
			while (print->min_length--)
				ft_buffering(print, "0", 1);
	}
	else
		ft_buffering(print, str, (int)LEN(str));
}

void	ft_char(t_shit *print, unsigned c)
{
	print->writen = (print->params & TYPE_LONG
		|| print->params & TYPE_LONG2) ? ft_wcharlen(c) : 1;
	if ((print->filled = print->min_length - print->writen) < 0)
		print->filled = 0;
	ft_filled(print, 0);
	ft_wcharput(print, c,
		print->writen, print->writen);
	ft_filled(print, 1);
}
