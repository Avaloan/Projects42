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
			if (e->tab_way[x].path_master->size_path > e->tab_way[x + 1].path_master->size_path)
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

void    ants_walk(t_env *e)
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
	t_ants	tab_ants[e->nb_ants];
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
		tot_size_p += e->tab_way[path_travel].path_master->size_path;
		while (i < new_ants)
		{
//		printf("turn = %d, size = %d\n", turn, e->tab_way[i].path_master->size_path);
			if (turn >= papp - e->tab_way[i].path_master->size_path)
				new_ants--;
			i++;
		}
		turn++;
	}
/************************************************ESSAI
	int turn;
	int	ants;
	int	i;
	int	turn_path;
	int	room;
	int deep_level;
	int	actual_start;
	int ants_smoking;
	int	end_count;

	turn = 1;
	actual_start = 0;
	ants = 0;
	ants_smoking = 0;
	end_count = 0;
	printf("papp = %d, ants = %d\n", papp, e->nb_ants);
	while (turn < papp)
	{
		turn_path = actual_start;
		ants += path_travel;
		i = ants;
		if (i > e->nb_ants)
			i = e->nb_ants - ants_smoking;
//			printf("Turn = %d, ants = %d, i = %d, turn_path = %d, room = %d, deep_level = %d, actual_start = %d, ants_smoking = %d\n", turn, ants, i, turn_path, room, deep_level, actual_start, ants_smoking);
		while (i > ants_smoking)
	7	{
			if (turn_path < actual_start)
				deep_level = (i - 1 - ants_smoking) / path_needed;
			else
				deep_level = (i - 1) / path_needed;
//			printf("Path_needed = %d, Turn = %d, ants = %d, i = %d, turn_path = %d, room = %d, deep_level = %d, actual_start = %d, ants_smoking = %d\n", path_needed, turn, ants, i, turn_path, room, deep_level, actual_start, ants_smoking);
//			printf("size path = %d\n", e->tab_way[actual_start].path_master->size_path);
//			printf("size path = %d\n", e->tab_way[actual_start - 1].path_master->size_path);
//			deep_level = (actual_start > 0 ? (i + (actual_start * (e->tab_way[actual_start].path_master->size_path - e->tab_way[actual_start - 1].path_master->size_path) - 1) / path_needed) : (i - 1) / path_needed);
//			printf("i = %d\n", i);
//			printf("deeplevel = %d\n", deep_level);
//			printf("Pathneeded = %d\n", path_needed);
			room = ghettouroom(turn_path, deep_level, e);
			if(i == ants_smoking + 1)
				printfourmi(e, ants - i + ants_smoking + 1, room, 666);
			else
				printfourmi(e, ants - i + ants_smoking + 1, room, 665);
			if (room == e->end)
			{
				end_count++;
			}
			turn_path++;
			turn_path = turn_path == path_needed ? 0 : turn_path;
			i--;
		}
		if (turn > papp - e->tab_way[path_needed - 1].path_master->size_path)
			path_travel--;
		while (end_count > 0)
		{
			actual_start++;
			ants_smoking++;
			if (actual_start == path_needed)
				actual_start = 0;
			end_count--;
		}
		turn++;
	}
//    printf("chemin 1 = %d\n", e->tab_way->path_master[0].path[0].node);
*********************************/
/*********************************************************/
/******************DO THE MATH***************************/
/*  fourmi = X;
    nb_path = Y;
    size_path = sx;
    path = x;
    the number of path we want = 666;
    Total_sx = Tsx = s(0+.+.....+.+x);

    AP = ANTS / PATH = (X + Tsx) / x

    x = 0;
    AP = 0;
    Tsx = 0;
    while (x < Y && X > sx) (si sx > forcement le dernier chemin a prendre)
      Tsx += sx;
      do the AP;
      if (NAP > AP)
        666 = x;
      x++;

    for each path
    while (ya des fourmi)
        balancer fourmi inda pampa (afficher fourmi num (max fourmi - fourmi actuel) + sa\
lle)

*/
/*********************************************************/
/******************DO THE MATH***************************/
}
