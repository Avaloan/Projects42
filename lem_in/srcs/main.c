/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 00:32:44 by snedir            #+#    #+#             */
/*   Updated: 2018/03/06 00:33:44 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		assign_path_to_tab(t_env *e)
{
	t_path_m	*tmp;
	int			i;

	tmp = e->list_path;
	i = 0;
	while (i < e->nb_path)
	{
		e->tab_way[i].path_master = tmp;
		i++;
		if (tmp && tmp->next_path)
			tmp = tmp->next_path;
		else
			tmp = NULL;
	}
}

int			nb_wrong_path(t_env *e)
{
	int			i;
	t_path_m	*tmp;

	i = 0;
	tmp = e->list_path;
	while (tmp)
	{
		if (tmp->selected == 2)
			i++;
		tmp = tmp->next_path;
	}
	return (i);
}

void		room_mapping(t_env *e)
{
	int		i;
	t_room	*tmp;

	i = 0;
	if (!(e->room_tab))
		fmalloc((void**)&e->room_tab, sizeof(char*) * e->count);
	tmp = e->e_room;
	while (tmp && i < e->count)
	{
		e->room_tab[i] = tmp->room_name;
		tmp = tmp->next;
		i++;
	}
}

int			g_room(int turn_path, int deep_level, t_env *e)
{
	t_path	*tmp;
	int		i;

	i = -1;
	tmp = e->tab_way[turn_path].path_master->path->next;
	while (tmp && ++i < deep_level)
		tmp = tmp->next;
	return (tmp->node);
}

int			main(void)
{
	t_env	*e;

	fmalloc((void**)&e, sizeof(t_env));
	e->start = -5;
	e->end = -5;
	e->connection[0] = -5;
	e->connection[1] = -5;
	parser(e);
	if (!path_finding(e))
		exit_error();
	print_line(e);
	write(1, "\n\n", 2);
	ft_trabul(e);
	room_mapping(e);
	menu_ants(e);
}
