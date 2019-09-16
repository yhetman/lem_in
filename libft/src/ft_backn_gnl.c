/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backn_gnl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:42:23 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/16 16:18:58 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char		*ft_strrealloc(char *str, size_t size)
{
	char		*mem;

	mem = ft_strnew(size);
	if (str)
	{
		ft_strcpy(mem, str);
		ft_strdel(&str);
	}
	return (mem);
}

static void		free_cat(char **gnl, char *tmp)
{
	size_t		combined_size;

	if (!tmp || !(*tmp))
		return ;
	combined_size = 0;
	if (gnl && *gnl)
		combined_size += LEN(*gnl);
	combined_size += LEN(tmp);
	*gnl = ft_strrealloc(*gnl, combined_size);
	*gnl = ft_strcat(*gnl, tmp);
}

static void		get_one_line(char **gnl, char **line)
{
	int			split;
	char		*tmp;

	if (!gnl)
		return ;
	split = ft_strclen(*gnl, '\n');
	if (split != -1)
	{
		*(*gnl + split) = 0;
		*line = ft_strdup(*gnl);
		tmp = *gnl;
		*gnl = ft_strdup(tmp + split + 1);
		ft_strdel(&tmp);
	}
	else
	{
		*line = ft_strdup(*gnl);
		ft_strdel(gnl);
	}
}

int				ft_backn_gnl(const int fd, char **line)
{
	static char	*gnl[OPEN_MAX];
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if (!line || fd < 0)
		return (-1);
	if (*line)
		ft_strdel(line);
	while ((ret = read(fd, buf, BUFF_SIZE)) || (gnl[fd] && *(gnl[fd])))
	{
		if (ret < 0 || (buf[ret] = 0))
			return (-1);
		if (buf[0])
			free_cat(&gnl[fd], buf);
		if (gnl[fd] && *(gnl[fd]) && (ft_strchr(gnl[fd], '\n')
					|| ret < BUFF_SIZE))
		{
			get_one_line(&(gnl[fd]), line);
			return (1);
		}
	}
	ft_strdel(&gnl[fd]);
	return (0);
}
