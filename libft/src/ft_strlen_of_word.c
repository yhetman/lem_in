/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_of_word.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:19:27 by yhetman           #+#    #+#             */
/*   Updated: 2019/06/06 16:26:17 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlen_of_word(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && !IS_SPACE(str[i]))
		i++;
	return (i);
}
