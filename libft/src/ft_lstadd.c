/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 07:33:37 by yhetman           #+#    #+#             */
/*   Updated: 2019/08/16 18:18:47 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_lst **alst, t_lst *new)
{
	if (alst != NULL && *alst != NULL && new != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
}
