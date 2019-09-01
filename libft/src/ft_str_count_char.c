/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_count_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 12:51:20 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/01 19:08:54 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_str_count_char(char *str, char *search)
{
	size_t	length_search;
	int		nb_occur;

	length_search = 0;
	nb_occur = 0;
	length_search = LEN(search);
	while (str)
	{
		if ((str = ft_strstr(str, search)))
		{
			nb_occur++;
			str = str + length_search;
		}
	}
	return (nb_occur);
}
