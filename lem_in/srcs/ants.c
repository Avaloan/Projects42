/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 02:32:55 by snedir            #+#    #+#             */
/*   Updated: 2018/03/02 05:29:57 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/lem_in.h"

void	ft_trabul(t_env *e)
{
	int	x;
	int	y;
	t_path_m *tmp;

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
	while (path_travel < e->nb_path && e->nb_ants > e->tab_way[path_travel].path_master->size_path)
	{
		tot_size_p += e->tab_way[path_travel].path_master->size_path;
		path_travel++;
		ants_per_path = (e->nb_ants + tot_size_p) / path_travel;
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

void	init_send_ants(t_send_ants *send_ants)
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

void	menu_ants(t_env *e)
{
	t_ants	*tab_ants;
	t_send_ants	send_ants;
	int		i;

	tab_ants = (t_ants *)ft_memalloc(sizeof(t_ants) * e->nb_ants);
	i = 0;
	ft_trabul(e);
	init_send_ants(&send_ants);
	calculate_papp(e, &send_ants);
	while (i < e->nb_ants)
		tab_ants[i++].deep_level = -1;
	send_ants.new_ants = send_ants.path_needed;
	s_ants(e, &send_ants, tab_ants);

}

void	modif_new_ants(t_send_ants *send_ants, t_env *e)
{
	send_ants->i = 0;
	while (++send_ants->i < send_ants->new_ants)
		if (send_ants->turn >= send_ants->papp - e->tab_way[send_ants->i].path_master->size_path)
			send_ants->new_ants--;
}


void	s_ants(t_env *e, t_send_ants *send_ants, t_ants *tab_ants)
{
	while (send_ants->turn < send_ants->papp)
	{
		if (send_ants->total + send_ants->new_ants > e->nb_ants)
			send_ants->new_ants = e->nb_ants - send_ants->total;
		send_ants->total += send_ants->new_ants;
		send_ants->i = 0;
		while (send_ants->i < send_ants->new_ants)
		{
			tab_ants[send_ants->ants].path = send_ants->i;
			send_ants->ants++;
			send_ants->i++;
		}
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
		send_ants->i = 0;
		modif_new_ants(send_ants, e);
		send_ants->turn++;
	}
}
/*
   void    menu_ants(t_env *e)
   {
   int path_travel;
   int ants_per_path;
   int tot_size_p;
   int path_needed;
   int papp;

   papp = e->nb_ants + e->tab_way[0].path_master->size_path - 1;
   path_travel = 0;
   ants_per_path = 0;
   tot_size_p = 0;
   while (path_travel < e->nb_path && e->nb_ants > e->tab_way[path_travel].path_master->size_path)
   {
   printf("niaue ta mere\n");
   tot_size_p += e->tab_way[path_travel].path_master->size_path;
   path_travel++;
   ants_per_path = (e->nb_ants + tot_size_p) / path_travel;
   if (ants_per_path < papp)
   {
   papp = ants_per_path;
   path_needed = path_travel;
   }
   }
   printf("nb_ants = %d\n", e->nb_ants);
   printf("papp = %d\n", papp);
   printf("pathneeded = %d\n", path_needed);
   printf("nb_path = %d\n\n", e->nb_path);
   t_ants tab_ants[e->nb_ants];
   int ants;
   int turn;
   int new_ants;
   int i;
   int room;
   int total;
   i = 0;
   while (i < e->nb_ants)
   tab_ants[i++].deep_level = -1;
   if (path_needed == 0)
   path_needed++;
   new_ants = path_needed;
   turn = 0;
   ants = 0;
   total = 0;
   while (turn < papp)
   {
   if (total + new_ants > e->nb_ants)
   new_ants = e->nb_ants - total;
   total += new_ants;
   i = 0;
   while (i < new_ants)
   {
   tab_ants[ants].path = i;
   ants++;
   i++;
   }
   i = 0;
   while (i < ants)
   {
   if (tab_ants[i].path != -1)
   {
   tab_ants[i].deep_level += 1;
   room = g_room(tab_ants[i].path, tab_ants[i].deep_level, e);
   if (i == ants - 1)
   printfourmi(e, i + 1, room, 666);
   else
   printfourmi(e, i + 1, room, 665);
   if (room == e->end)
   tab_ants[i].path = -1;
   }
i++;
}
i = 0;
tot_size_p += e->tab_way[path_travel].path_master->size_path;
while (i < new_ants)
{
	printf("turn = %d, size = %d\n", turn, e->tab_way[i].path_master->size_path);
	if (turn >= papp - e->tab_way[i].path_master->size_path)
		new_ants--;
	i++;
}
turn++;
}

}*/

