/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_bufferf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 20:39:23 by yhetman           #+#    #+#             */
/*   Updated: 2019/06/14 20:46:11 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void			ft_flush_buff(t_buffer *buf)
{
	if (buf->pos)
	{
		write(buf->fd, buf->step, buf->pos);
		buf->pos = 0;
	}
}

void            ft_putchr_buff(t_buffer *buff, char c)
{
    buff->step[buff->pos] = c;
	buff->pos++;
	buff->printed++;
	if (buff->pos == BUFF_SIZE)
		ft_flush_buff(buff);
}

void			ft_putstr_buf(t_buffer *buf, char *str)
{
	while (*str)
	{
		ft_putchr_buff(buf, *str);
		str++;
	}
}

void			ft_putnstr_buf(t_buffer *buf, char *str, int n)
{
	int	i;

	i = 0;
	while (str[i] && i < n)
	{
		ft_putchr_buff(buf, str[i]);
		i++;
	}
}

void			ft_repeat_buf(t_buffer *buf, char c, int n)
{
	while (n)
	{
		ft_putchr_buff(buf, c);
		n--;
	}
}
