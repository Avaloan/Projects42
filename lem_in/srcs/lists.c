/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 03:52:46 by snedir            #+#    #+#             */
/*   Updated: 2017/12/14 04:55:28 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
 * GESTION LISTE ROOM
 */

t_room		*new_room(char *line, t_env *e)
{
	t_room	*elem;

	elem = (t_room*)ft_memalloc(sizeof(t_room));
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

	elem = (t_line*)ft_memalloc(sizeof(t_line));
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

/*
 * GESTION PATHS
 */

t_path		*new_node(int path)
{
	t_path	*elem;

	elem = (t_path*)ft_memalloc(sizeof(t_path));
	elem->node = path;
	elem->next = NULL;
	return (elem);
}

void		add_elem_node(t_env *e, int path)
{
	t_path	*tmp;

	tmp = e->current->path;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node(path);
}

t_path_m	*new_elem_path(int size_path, int path)
{
	t_path_m	*new_path;

	new_path = (t_path_m*)ft_memalloc(sizeof(t_path_m));
	new_path->next_path = NULL;
	new_path->path = new_node(path);
	new_path->size_path = size_path;
	new_path->selected = -1;
	return (new_path);
}

void		add_elem_path(t_env *e, int size_path, int path)
{
	int			i;

	i = 0;
	if (!e->list_path)
	{
		e->list_path = new_elem_path(size_path, path);
		e->current = e->list_path;
		return ;
	}
	else
	{
		if (!e->current->next_path)
		{
			e->current->next_path = new_elem_path(size_path, path);
			e->current = e->current->next_path;
		}
	}
}
