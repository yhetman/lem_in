/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_buff_unicode.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 20:48:15 by yhetman           #+#    #+#             */
/*   Updated: 2019/06/14 20:50:13 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putchr_buff_unicode(t_buffer *buff, wchar_t uchar)
{
	if (uchar < 128)
		ft_putchr_buff(buff, uchar);
	else if (uchar < 2048)
	{
		ft_putchr_buff(buff, 0b11000000 | ((uchar >> 6) & 0b00011111));
		ft_putchr_buff(buff, 0b10000000 | (uchar & 0b00111111));
	}
	else if (uchar < 65536)
	{
		ft_putchr_buff(buff, 0b11100000 | ((uchar >> 12) & 0b00001111));
		ft_putchr_buff(buff, 0b10000000 | ((uchar >> 6) & 0b00111111));
		ft_putchr_buff(buff, 0b10000000 | (uchar & 0b00111111));
	}
	else
	{
		ft_putchr_buff(buff, 0b11110000 | ((uchar >> 18) & 0b00000111));
		ft_putchr_buff(buff, 0b10000000 | ((uchar >> 12) & 0b00111111));
		ft_putchr_buff(buff, 0b10000000 | ((uchar >> 6) & 0b00111111));
		ft_putchr_buff(buff, 0b10000000 | (uchar & 0b00111111));
	}
}

void	putstr_buf_unicode(t_buffer *buff, wchar_t *ustr)
{
	while (*ustr)
	{
		ft_putchr_buff_unicode(buff, *ustr);
		ustr++;
	}
}

void	putnstr_buf_unicode(t_buffer *buff, wchar_t *ustr, int n)
{
	int		i;

	i = 0;
	while (*ustr && i < n)
	{
		if (*ustr < 128)
			i += 1;
		else if (*ustr < 2048)
			i += 2;
		else if (*ustr < 65536)
			i += 3;
		else
			i += 4;
		if (i <= n)
			ft_putchr_buff_unicode(buff, *ustr);
		ustr++;
	}
}
