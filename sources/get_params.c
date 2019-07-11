/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:46:18 by yhetman           #+#    #+#             */
/*   Updated: 2019/07/11 21:48:47 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	print_help(char *progname)
{
	ft_printf("Lemin reads from the standard input. \n");
	ft_printf("You may write line by or feed in a file, like this:\n");
	ft_printf("%{blue}%s%{eoc} < test.map\n", progname);
	ft_printf("Your may add the following arguments for: \n");
	ft_printf("    -a | --ant    -> color the ants\n");
	ft_printf("    -p | --path   -> color the paths\n");
	ft_printf("    -r | --room   -> color the rooms\n");
	ft_printf("    -d | --debug  -> for debugging purposes\n");
	exit(0);
	return ;
}

static void	invalid_param(char *arg, char *progname)
{
	ft_printf("Argument %s is invalid!\n", arg);
	ft_printf("Run %s -h or --help to know how use this\n", progname);
	exit(PARAM_ERR);
	return ;
}

void		get_params(int argc, char *argv[], t_lemin *init)
{
	int		i;

	i = 1;
	while (--argc)
	{
		if (ft_strequ(argv[i], "-h") || ft_strequ(argv[i], "--help"))
			print_help(argv[0]);
		else if (ft_strequ(argv[i], "-d") || ft_strequ(argv[i], "--debug"))
			init->param.debug = 1;
		else if (ft_strequ(argv[i], "-a") || ft_strequ(argv[i], "--ant"))
			init->param.ant_colored = 1;
		else if (ft_strequ(argv[i], "-p") || ft_strequ(argv[i], "--path"))
			init->param.path_colored = 1;
		else if (ft_strequ(argv[i], "-r") || ft_strequ(argv[i], "--room"))
			init->param.room_colored = 1;
		else
			invalid_param(argv[i], argv[0]);
		i++;
	}
	return ;
}
