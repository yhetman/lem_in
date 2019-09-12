/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 05:19:37 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/12 18:53:51 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error_manager(char *str)
{
	ft_printf("%{red}%s%{eoc}", str);
	system("leaks lem-in");
	exit(FAIL);
}
