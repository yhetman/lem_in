/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charinstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 12:51:20 by yhetman           #+#    #+#             */
/*   Updated: 2019/01/29 13:00:26 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_charinstr(char *str, char *search)
{
	char	*temp;
	size_t	length_search;
	int		nb_occur;

	temp = str;
	length_search = 0;
	nb_occur = 0;
	length_search = ft_strlen(search);
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
