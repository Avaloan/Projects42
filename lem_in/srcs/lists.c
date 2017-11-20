/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 03:52:46 by snedir            #+#    #+#             */
/*   Updated: 2017/11/20 04:54:21 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
 * GESTION LISTE ROOM
 */

t_room		*new_room(char *line, t_env *e)
{
	t_room	*elem;

	elem = (t_room*)malloc(sizeof(t_room));
	elem->id = e->count;
	elem->next = NULL;
	elem->room_name = ft_strdup(line);
	return (elem);
}


void		add_elem_room(char *line, t_env *e)
{
	t_room	*tmp;
	
	tmp = E_ROOM;
	if (!E_ROOM)
	{
		E_ROOM = new_room(line, e);
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_room(line, e);
}

/*
 * GESTION LISTE LINE
 */

t_line		*new_line(char *line)
{
	t_line	*elem;

	elem = (t_line*)malloc(sizeof(t_line));
	elem->line = ft_strdup(line);
	elem->next = NULL;
	return (elem);
}

void		add_elem_line(t_env *e, char *line)
{
	t_line	*tmp;

	tmp = E_LINE;
	if (!E_LINE)
	{
		E_LINE = new_line(line);
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_line(line);
}

