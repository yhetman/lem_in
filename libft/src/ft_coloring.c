/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coloring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 21:38:04 by yhetman           #+#    #+#             */
/*   Updated: 2018/12/29 18:02:32 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_coloring(t_shit *print)
{
	int	len;

	print->writen = 5;
	if (!ft_strncmp(print->format, "{red}", (len = 5)))
		ft_buffering(print, RED, print->writen);
	else if (!ft_strncmp(print->format, "{green}", (len = 7)))
		ft_buffering(print, GREEN, print->writen);
	else if (!ft_strncmp(print->format, "{yellow}", (len = 8)))
		ft_buffering(print, YELLOW, print->writen);
	else if (!ft_strncmp(print->format, "{blue}", (len = 6)))
		ft_buffering(print, BLUE, print->writen);
	else if (!ft_strncmp(print->format, "{purple}", (len = 8)))
		ft_buffering(print, PURPLE, print->writen);
	else if (!ft_strncmp(print->format, "{cyan}", (len = 6)))
		ft_buffering(print, CYAN, print->writen);
	else if (!ft_strncmp(print->format, "{eoc}", (len = 5)))
		ft_buffering(print, EOC, --print->writen);
	else if (!(len = 0))
		print->writen = 0;
	print->format += len - 1;
	print->len += print->writen;
}
