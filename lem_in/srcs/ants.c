/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 02:32:55 by snedir            #+#    #+#             */
/*   Updated: 2018/03/06 00:10:48 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		ft_trabul(t_env *e)
{
	int			x;
	int			y;
	t_path_m	*tmp;

	x = 0;
	y = e->nb_path;
	while (y > 0)
	{
		x = 0;
		while (x < y - 1)
		{
			if (e->tab_way[x].path_master->size_path >
					e->tab_way[x + 1].path_master->size_path)
			{
				tmp = e->tab_way[x].path_master;
				e->tab_way[x].path_master = e->tab_way[x + 1].path_master;
				e->tab_way[x + 1].path_master = tmp;
			}
			x++;
		}
		y--;
	}
}

void		calculate_papp(t_env *e, t_send_ants *send_ants)
{
	int		path_travel;
	int		ants_per_path;
	int		tot_size_p;
	int		path_needed;
	int		papp;

	papp = e->nb_ants + e->tab_way[0].path_master->size_path - 1;
	path_travel = 0;
	ants_per_path = 0;
	tot_size_p = 0;
	while (path_travel < e->nb_path && e->nb_ants >
			e->tab_way[path_travel].path_master->size_path)
	{
		tot_size_p += e->tab_way[path_travel].path_master->size_path;
		ants_per_path = (e->nb_ants + tot_size_p) / ++path_travel;
		if (ants_per_path < papp)
		{
			papp = ants_per_path;
			path_needed = path_travel;
		}
	}
	send_ants->papp = papp;
	send_ants->path_needed = path_needed;
	if (send_ants->path_needed == 0)
		send_ants->path_needed += 1;
}

void		init_send_ants(t_send_ants *send_ants)
{
	send_ants->ants = 0;
	send_ants->turn = 0;
	send_ants->total = 0;
	send_ants->i = 0;
	send_ants->i2 = 0;
	send_ants->new_ants = 0;
	send_ants->room = 0;
	send_ants->papp = 0;
	send_ants->path_needed = 0;
}

void		menu_ants(t_env *e)
{
	t_ants		*tab_ants;
	t_send_ants	send_ants;
	int			i;

	if (!(tab_ants = (t_ants*)ft_memalloc(sizeof(t_ants) * e->nb_ants)))
	{
		perror("");
		exit(0);
	}
	i = 0;
	ft_trabul(e);
	init_send_ants(&send_ants);
	calculate_papp(e, &send_ants);
	while (i < e->nb_ants)
		tab_ants[i++].deep_level = -1;
	send_ants.new_ants = send_ants.path_needed;
	s_ants(e, &send_ants, tab_ants);
	free(tab_ants);
}

void		s_ants(t_env *e, t_send_ants *send_ants, t_ants *tab_ants)
{
	while (send_ants->turn < send_ants->papp)
	{
		if (send_ants->total + send_ants->new_ants > e->nb_ants)
			send_ants->new_ants = e->nb_ants - send_ants->total;
		ft_pukutak(send_ants, tab_ants);
		send_ants->i = 0;
		while (send_ants->i < send_ants->ants)
		{
			if (tab_ants[send_ants->i].path != -1)
			{
				tab_ants[send_ants->i].deep_level += 1;
				ROOM = g_room(tab_ants[I].path, tab_ants[I].deep_level, e);
				if (send_ants->i == send_ants->ants - 1)
					printfourmi(e, send_ants->i + 1, send_ants->room, 666);
				else
					printfourmi(e, send_ants->i + 1, send_ants->room, 665);
				if (send_ants->room == e->end)
					tab_ants[send_ants->i].path = -1;
			}
			send_ants->i++;
		}
		modif_new_ants(send_ants, e);
	}
}
