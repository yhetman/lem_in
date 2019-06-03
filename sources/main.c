/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 18:35:51 by yhetman           #+#    #+#             */
/*   Updated: 2019/06/03 14:57:38 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	free_node(void *ptr, size_t size)
{
	ft_bzero(ptr, size);
	ft_memdel(&ptr);
}

void	error_manager(char *str)
{
	ft_printf("%{red}%s%{eoc}", str);
	exit(EXIT_FAILURE);
}

void	free_t_lem(t_lem *ptr)
{
	ft_memdel((void**)&ptr->start);
	ft_memdel((void**)&ptr->end);
	//free_rooms(&(ptr)->rooms);
	//free_split(ptr->pipes);
}

void	in_case_of_error(t_list **temp, t_lem *lem, char *str)
{
	ft_lstdel(temp, &free_node);
	free_t_lem(lem);
	error_manager(str);
}

size_t	strsplen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && !IS_SPACE(str[i]))
		i++;
	return (i);
}

bool	isint(const char *arg)
{
	intmax_t	tmp;
	size_t		len;

	len = strsplen(arg);
	if (len > 11)
		return (false);
	tmp = ft_atoi(arg);
	if ((intmax_t)INT_MAX < (intmax_t)tmp
		|| (intmax_t)tmp < (intmax_t)INT_MIN)
		return (false);
	if (*arg == '+' || *arg == '-')
		arg++;
	if (!IS_DIGIT(*arg))
		return (false);
	while (*arg && !IS_SPACE(*arg))
	{
		if (!IS_DIGIT(*arg))
			return (false);
		arg++;
	}
	return (true);
}

bool			count_ants(t_list **input, int *ants)
{
	while (((char*)(*input)->content)[0] == '#')
	{
		if (ft_strequ((char*)(*input)->content, "##start")
				|| ft_strequ((char*)(*input)->content, "##end"))
			return (false);
		(*input) = (*input)->next;
	}
	if (isint((char*)(*input)->content))
	{
		*ants = ft_atoi((char*)(*input)->content);
		if (*ants >= 0)
			return (true);
		else
			return (false);
	}
	else
		return (false);
}

void	count_rooms(t_list **list, t_lem *lem)
{
	char	type;
	char	*str;
}

void	parsing(t_list **input, t_list **temp, t_lem *lem)
{
	if (!(*input))
		in_case_of_error(temp, lem, "ERROR: wrong number of arguments.");
	if (!(count_ants(input, &lem->ants)))
		in_case_of_error(temp, lem, "ERROR: invalid amount of ants.");
	*input = (*input)->next;
	count_rooms(input, lem);
}

t_list	*save_input(void)
{
	t_list	*input;
	char	*line;
	int		result;

	input = NULL;
	line = NULL;
	while ((result = get_next_line(0, &line)))
	{
		if (result == 1 || !IS_ASCII(line[0]))
			error_manager("ERROR: can't read the file");
		ft_lstadd(&input, ft_lstnew(line, sizeof(char) * (ft_strlen(line) + 1)));
	}
	return (input);
}

int		main(int argc, char **argv)
{
	t_lem	lem;
	t_list	*input;
	t_list	*temp;

	ft_bzero(&lem, sizeof(t_lem));
	input = save_input();
	temp = input;
	parsing(&input, &temp, &lem);//parsing of input and init_lem;

	return (0);
}