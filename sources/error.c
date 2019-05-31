/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 22:16:14 by yhetman           #+#    #+#             */
/*   Updated: 2019/05/31 15:51:53 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	error_manager(char *str)
{
	ft_printf("%{red}%s%{eoc}", str);
	exit(EXIT_FAILURE);
}

void	arg_error(void)
{
	ft_printf("%{red} ERROR: wrong number of arguments. %{eoc}");
	exit(EXIT_FAILURE);
}