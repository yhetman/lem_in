/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 18:35:51 by yhetman           #+#    #+#             */
/*   Updated: 2019/05/28 22:04:46 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	parsing(t_list **input, t_list **temp, t_lem *lem)
{
	if (!(*input))
	{
		free_lem(temp, lem);
		arg_error();
	}
	if (!(count_ants(input, &lem->ants)))
	{
		free_lem(temp, lem);
	}
	*input = (*input)->next;
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
			read_file_error();
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