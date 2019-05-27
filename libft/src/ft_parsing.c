/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:31:53 by yhetman           #+#    #+#             */
/*   Updated: 2019/01/03 14:34:59 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static void	ft_find_flags(t_shit *print)
{
	while ((print->n = ft_strchri("# +-0*",
		*print->format, -1)) > -1 && ++print->format)
		print->params |= (1 << print->n);
	((print->params & FLAG_MINUS) && !(print->params & STAR))
		? print->params &= ~FLAG_ZERO : 0;
	(print->params & FLAG_PLUS) ? print->params &= ~FLAG_SPACE : 0;
	if (print->params & STAR)
	{
		print->params &= ~STAR;
		if ((print->n = (int)va_arg(print->ap, int)) < 0)
		{
			print->params |= FLAG_MINUS;
			print->n = -print->n;
		}
		else
			print->params &= ~FLAG_MINUS;
		if (!(print->params & PRECIS))
			print->min_length = print->n;
		else
		{
			print->precis = (!(print->params & FLAG_MINUS)) ? print->n : 0;
			print->params = (!print->n) ? print->params
				| PRECIS : print->params & ~PRECIS;
		}
	}
}

static void	ft_width_precision(t_shit *print)
{
	if (48 < *print->format && *print->format < 58)
	{
		print->min_length = MAX(1, ft_atoi(print->format));
		while (47 < *print->format && *print->format < 58)
			++print->format;
	}
	if (*print->format == '.')
	{
		++print->format;
		print->precis = MAX(ft_atoi(print->format), 0);
		while (47 < *print->format && *print->format < 58)
			++print->format;
		print->params |= PRECIS;
	}
}

static void	ft_parsing_2(t_shit *print)
{
	ft_find_flags(print);
	ft_width_precision(print);
}

void		ft_parsing(t_shit *print)
{
	print->params = 0;
	print->min_length = 0;
	print->precis = 1;
	ft_parsing_2(print);
	while (1)
	{
		if (*print->format == 'l')
			print->params |= (print->format[1] == 'l' && ++print->format)
				? TYPE_LONG2 : TYPE_LONG;
		else if (*print->format == 'h')
			print->params |= (print->format[1] == 'h' && ++print->format)
				? TYPE_SHORT2 : TYPE_SHORT;
		else if (*print->format == 'j')
			print->params |= TYPE_INTMAX;
		else if (*print->format == 'z')
			print->params |= TYPE_SIZET;
		else
			break ;
		++print->format;
	}
	ft_find_flags(print);
	(print->params & FLAG_PLUS) ? print->params &= ~FLAG_SPACE : 0;
	if (ft_strchr("CDSUOBX", *print->format))
		print->params |= (*print->format != 'X') ? TYPE_LONG : UPCASE;
	ft_conversion(print);
}
