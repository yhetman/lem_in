/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 18:02:06 by yhetman           #+#    #+#             */
/*   Updated: 2019/01/03 12:27:00 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_no_chars(t_shit *print)
{
	if ((print->filled = print->min_length - 1) > 0)
	{
		ft_filled(print, 0);
		ft_buffering(print, print->format, 1);
		ft_filled(print, 1);
		return ;
	}
	ft_buffering(print, print->format, 1);
}

void	ft_filled(t_shit *print, int n)
{
	if (!print->filled)
		return ;
	print->type = 32 | (print->params & FLAG_ZERO);
	if (!n && !(print->params & FLAG_MINUS))
		while (print->filled--)
			ft_buffering(print, &print->type, 1);
	else if (n && (print->params & FLAG_MINUS))
		while (print->filled--)
			ft_buffering(print, &print->type, 1);
}

void	ft_conversion(t_shit *print)
{
	print->type = *print->format;
	if (print->type == 's')
		(print->params & TYPE_LONG || print->params & TYPE_LONG2)
		? ft_wstrput(print) : ft_strput(print);
	else if (ft_strchr("dDi", print->type))
		ft_nbput(print);
	else if (print->type == 'f' || print->type == 'F')
		(print->params & PRECIS && !print->precis)
		? ft_nbput(print) : ft_putfloats(print);
	else if (print->type == 'c' || print->type == 'C')
		ft_char(print, va_arg(print->ap, unsigned));
	else if (ft_strchr("oOuUbBxX", print->type))
		ft_nbput_base(ft_strchri_lu(".b..ou..x", print->type, -1) << 1, print);
	else if (print->type == 'S')
		ft_wstrput(print);
	else if (print->type == 'p')
		ft_pointers(print);
	else if (print->type == 'n')
		*va_arg(print->ap, int *) = print->len;
	else if (print->type == 'm')
		ft_printf_str(STRERR(errno), print);
	else if (print->type == '{')
		ft_coloring(print);
	else
		ft_no_chars(print);
}
