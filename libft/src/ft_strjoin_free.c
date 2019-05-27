/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 19:12:02 by yhetman           #+#    #+#             */
/*   Updated: 2019/03/08 14:20:20 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin_free(char *s1,
			int free1, char *s2, int free2)
{
	char	*temp1;
	char	*temp2;
	char	*mew;

	temp1 = s1;
	temp2 = s2;
	mew = ft_strjoin(s1, s2);
	if (free1 == 1)
		free(temp1);
	if (free2 == 1)
		free(temp2);
	return (mew);
}
