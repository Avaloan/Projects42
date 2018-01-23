/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 03:56:53 by snedir            #+#    #+#             */
/*   Updated: 2018/01/23 05:26:10 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			check_start_end(char *line, t_env *e)
{
	if (ft_strcmp(line, "##start") == 0)
	{
		PENDING_START = 1;
		return (1);
	}
	if (ft_strcmp(line, "##end") == 0)
	{
		PENDING_END = 1;
		return (1);
	}
	return (0);
}

int			check_hashtag(char *line, t_env *e)
{
	int		i;

	i = 0;
	if (line[i] != '#')
		return (2);
	if (line[i + 1] == '#')
	{
		if (check_start_end(line, e) == 1)
		{
			if (!NB_ANTS)
				return (ERROR_FLAG);
			if (FLAG_ROOM)
				return (STOP_FLAG);
			return (0);
		}
	}
	return (1);
}

int			get_nb_ants(char *line, t_env *e)
{
	int		i;

	i = -1;
	while (line[++i])
		if (!ft_isdigit(line[i]))
			return (ERROR_FLAG);
	if (!(NB_ANTS = ft_atoi(line)))
		return (ERROR_FLAG);
	if (i > 10)
		return (ERROR_FLAG);
	return (1);
}
