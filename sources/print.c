/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:44:23 by yhetman           #+#    #+#             */
/*   Updated: 2019/07/11 21:44:54 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	print_room(void *room)
{
	t_room	*tmp_room;

	if (room)
	{
		tmp_room = (t_room *)room;
		if (tmp_room->flag == STARTROOM)
			ft_putendl_fd("##start", FT_STD_OUT);
		else if (tmp_room->flag == ENDROOM)
			ft_putendl_fd("##end", FT_STD_OUT);
		ft_putstr_fd(tmp_room->name, FT_STD_OUT);
		ft_putchar_fd(' ', FT_STD_OUT);
		ft_putnbr_fd(tmp_room->x, FT_STD_OUT);
		ft_putchar_fd(' ', FT_STD_OUT);
		ft_putnbr_fd(tmp_room->y, FT_STD_OUT);
	}
	ft_putchar_fd('\n', FT_STD_OUT);
	return ;
}

static void	print_path(void *tunnel)
{
	t_path	*path;

	path = (t_path *)tunnel;
	ft_putstr_fd(path->door1, FT_STD_OUT);
	ft_putchar_fd('-', FT_STD_OUT);
	ft_putendl_fd(path->door2, FT_STD_OUT);
	return ;
}

static void	print_room_colored(void *room)
{
	t_room	*tmp;

	if (room != NULL)
	{
		tmp = (t_room *)room;
		if (tmp->flag == STARTROOM)
			ft_putendl_fd("##start", FT_STD_OUT);
		else if (tmp->flag == ENDROOM)
			ft_putendl_fd("##end", FT_STD_OUT);
		ft_printf("%{red}%s %{green}%d %{green}%d%{eoc}", tmp->name, tmp->x, tmp->y);
	}
	ft_putchar_fd('\n', FT_STD_OUT);
	return ;
}

static void	print_path_colored(void *tunnel)
{
	t_path	*path;

	path = (t_path *)tunnel;
	ft_printf("%{blue}%s-%s%{eoc}\n", path->door1, path->door2);
	return ;
}

void		lemin_print(t_lemin *lemin)
{
	if (!lemin->param.ant_colored)
		ft_putnbr_fd(lemin->ant_total, FT_STD_OUT);
	else
		ft_printf("%{yellow}%d%{eoc}", lemin->ant_total);
	ft_putchar_fd('\n', FT_STD_OUT);
	if (!lemin->param.room_colored)
		ft_lstforeach(lemin->room_list, print_room);
	else
		ft_lstforeach(lemin->room_list, print_room_colored);
	if (!lemin->param.path_colored)
		ft_lstforeach(lemin->path_list, print_path);
	else
		ft_lstforeach(lemin->path_list, print_path_colored);
	ft_putchar_fd('\n', FT_STD_OUT);
	return ;
}
