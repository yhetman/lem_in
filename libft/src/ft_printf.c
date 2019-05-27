/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:52:26 by yhetman           #+#    #+#             */
/*   Updated: 2019/01/07 21:03:57 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_shit	print;

	ft_bzero(&print, sizeof(print));
	print.fd = 1;
	print.format = (char *)format;
	va_start(print.ap, format);
	while (*print.format)
	{
		if (*print.format == '%')
		{
			++print.format;
			if (!*print.format)
				break ;
			ft_parsing(&print);
		}
		else
			ft_buffering(&print, print.format, 1);
		++print.format;
	}
	write(print.fd, print.buffer, print.index);
	va_end(print.ap);
	return (print.len);
}

int		ft_dprintf(int fd, const char *format, ...)
{
	t_shit	print;

	ft_bzero(&print, sizeof(print));
	print.fd = fd;
	print.format = (char *)format;
	va_start(print.ap, format);
	while (*print.format)
	{
		if (*print.format == '%')
		{
			++print.format;
			if (!*print.format)
				break ;
			ft_parsing(&print);
		}
		else
			ft_buffering(&print, print.format, 1);
		++print.format;
	}
	write(print.fd, print.buffer, print.index);
	va_end(print.ap);
	return (print.len);
}
