/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:32:23 by yhetman           #+#    #+#             */
/*   Updated: 2019/07/11 21:38:13 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			main(int argc, char *argv[])
{
	t_lemin	*lemin;

	lemin = lemin_init(argc, argv);
	lemin_print(lemin);
	lemin_start(lemin);
	if (!lemin_validate(lemin))
	{
		lemin_end(lemin);
		ft_strerr("Error: Something went wrong, check your input.");
	}
	lemin_loop(lemin);
	return (0);
}
