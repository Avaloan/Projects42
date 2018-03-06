/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 03:50:39 by snedir            #+#    #+#             */
/*   Updated: 2018/03/06 00:36:52 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			room_exist(t_env *e, char *to_compare)
{
	t_room	*tmp;

	tmp = E_ROOM;
	while (tmp)
	{
		if (!(ft_strcmp(tmp->room_name, to_compare)))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void		pending(t_env *e)
{
	if (PENDING_START)
	{
		e->start = e->count;
		PENDING_START = 0;
	}
	else if (PENDING_END)
	{
		e->end = e->count;
		PENDING_END = 0;
	}
}

int			get_room(char *line, t_env *e)
{
	char	*name;
	int		check;

	check = check_valid_room(line, e);
	if (check == 1000)
		return (FLAG_ROOM);
	if (check != 2)
		return (STOP_FLAG);
	if (!get_room_name(&name, line))
	{
		free(name);
		return (ERROR_MALLOC);
	}
	if (!room_exist(e, name))
		return (ERROR_FLAG);
	if (PENDING_START == 1 && PENDING_END == 1)
		return (ERROR_FLAG);
	else if (PENDING_START == 1 || PENDING_END == 1)
		pending(e);
	add_elem_room(name, e);
	free(name);
	e->count++;
	return (1);
}
