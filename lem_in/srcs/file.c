/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 01:24:15 by snedir            #+#    #+#             */
/*   Updated: 2018/02/06 05:06:06 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_file		*new_queue_elem(int id)
{
	t_file	*elem;

	elem = (t_file*)malloc(sizeof(t_file));
	elem->id = id;
	elem->prev = NULL;
	elem->next = NULL;
	return (elem);
}

void		add_queue_elem(t_env *e, int id)
{
	t_file	*tmp;

	tmp = E_FILE;
	if (!E_FILE)
	{
		E_FILE = new_queue_elem(id);
		return ;
	}
	while (tmp->prev)
		tmp = tmp->prev;
	tmp->prev = new_queue_elem(id);
	tmp->prev->next = tmp;
}

void		dequeue(t_env *e)
{
	t_file	*tmp;

	tmp = E_FILE->prev;
	if (!E_FILE)
		return ;
	free(E_FILE);
	E_FILE = tmp;
	if (tmp)
		tmp->next = NULL;
}

t_kyuuh		*new_kyuuh_elem(int id_room, int cur_ant, t_path *cur_room)
{
	t_kyuuh	*elem;

	elem = (t_kyuuh*)malloc(sizeof(t_kyuuh));
	elem->id_room = id_room;
	elem->current_ant = cur_ant;
	elem->current_room = cur_room;
	elem->prev = NULL;
	elem->next = NULL;
	return (elem);
}

void		add_kyuuh_elem(t_env *e, int i, int id_room, int cur_ant, t_path *cur_room)
{
	t_kyuuh	*tmp;

	tmp = e->tab_way[i].ants_in_path;
	if (!e->tab_way[i].ants_in_path)
	{
		e->tab_way[i].ants_in_path = new_kyuuh_elem(id_room, cur_ant, cur_room);
		return ;
	}
	while (tmp->prev)
		tmp = tmp->prev;
	tmp->prev = new_kyuuh_elem(id_room, cur_ant, cur_room);
	tmp->prev->next = tmp;
}

void		dekyuuh(t_env *e, int i)
{
	t_kyuuh	*tmp;

	tmp = e->tab_way[i].ants_in_path->prev;
	if (e->tab_way[i].ants_in_path->prev)
		return ;
	free(E_FILE);
	e->tab_way[i].ants_in_path->prev = tmp;
	if (tmp)
		tmp->next = NULL;
}
