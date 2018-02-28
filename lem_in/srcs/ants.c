/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 02:32:55 by snedir            #+#    #+#             */
/*   Updated: 2018/02/27 01:46:51 by abassibe         ###   ########.fr       */
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

void		casa_del_pope(t_env *e, t_pope *pope)
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
	pope->papp = papp;
	pope->path_needed;
}

void	init_culaire(t_culaire *norme)
{
	norme->ants = 0;
	norme->turn = 0;
	norme->total = 0;
	norme->i = 0;
}

void	culaimor(t_env *e)
{
	t_pope	pope;
	t_ants	*tab_ants;
	t_culaire	norme;
	int		i;

	tab_ants = (t_ants *)ft_memalloc(sizeof(t_ants) * e->nb_ants);
	i = 0;
	casa_del_pope(e, &pope);
	init_culaire(&norme);
	while (i < e->nb_ants)
		tab_ants[i++].deep_level = -1;
}

void	culaire()
{

}


	int		ants;
	int		turn;
	int		new_ants;
	int		i;
	int		room;
	int		total;
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
				room = ghettouroom(tab_ants[i].path, tab_ants[i].deep_level, e);
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
		while (i < new_ants)
		{
			if (turn >= papp - e->tab_way[i].path_master->size_path)
				new_ants--;
			i++;
		}
		turn++;
	}
}
