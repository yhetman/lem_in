/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 18:35:58 by yhetman           #+#    #+#             */
/*   Updated: 2019/05/28 22:02:39 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"
# include <time.h>
# include <mlx.h>
# include "structs.h"

/*
**		main.c
*/
t_list	*save_input(void);
//parsing(t_list **input, t_list **temp, t_lem *lem);

/*
**		error.c
*/
void	read_file_error(void);
void	arg_error(void);
#endif
