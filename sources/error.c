/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 22:16:14 by yhetman           #+#    #+#             */
/*   Updated: 2019/05/27 22:18:54 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	read_file_error(void)
{
	ft_printf("%{red} ERROR: can't read the file. %{eoc}");
	exit(EXIT_FAILURE);
}