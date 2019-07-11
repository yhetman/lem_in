/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:04:02 by yhetman           #+#    #+#             */
/*   Updated: 2019/07/10 16:57:05 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"


/*
**			READING FROM THE STDIN
*/
void	delone_t_stdin(t_stdin *input, void(*del)(void *, size_t)
{
	if (input)
	{
		del((*input)->info, (*input)->info_size);
		ft_memdel((void**)input);
	}
}

void	del_t_stdin(t_stdin **input, void (*del)(void *, size_t))
{
	t_stdin *temp;

	while (*input)
	{
		temp = (*input)->next;
		delone_t_stdin(input, del);
		*input = temp;
	}
}

t_stdin	*new_t_stdin(char const *info, size_t info_size)
{
	t_stdin	*new;

	if (!(new = (t_stdin *)malloc(sizeof(t_stdin))))
		return (NULL);
	if (info == NULL)
	{
		new->info = NULL;
		new->info_size = 0;
		new->next = NULL;
	}
	else
	{
		if (!(new->info = malloc(info_size)))
			return (NULL);
		new->info = ft_memcpy(new->info,
			info, info_size);
		new->info_size = info_size;
		new->next = NULL;
	}
	return (new);
}

void	add_t_stdin(t_stdin **input, t_stdin *add)
{
	if (input != NULL && *input != NULL && add != NULL)
	{
		add->next = *input;
		*input = add;
	}
}


t_stdin	*save_input(void)
{
	t_stdin	*input;
	char	*line;
	int		result;

	input = NULL;
	line = NULL;
	while ((result = get_next_line(0, &line)))
	{
		if (result == 1 || !IS_ASCII(line[0]))
			ft_error_manager("ERROR: can't read the file\n");
		add_t_stdin(&input, new_t_stdin(line, sizeof(char) * (LEN(line) + 1)));
	}
	return (input);
}