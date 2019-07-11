/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_rec_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:05:51 by yhetman           #+#    #+#             */
/*   Updated: 2019/07/11 10:06:26 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lst_rec_free(t_list *first)
{
	if (first)
	{
		ft_lst_rec_free(first->next);
		free(first);
	}
}
