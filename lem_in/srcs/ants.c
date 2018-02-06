/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 02:32:55 by snedir            #+#    #+#             */
/*   Updated: 2018/02/06 04:20:32 by snedir           ###   ########.fr       */
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
	int		path_needed;
	int		ants_per_path;
	int		tot_size_p;
	int		papp;

	papp = e->nb_ants + e->tab_way[0].path_master->size_path + 1;
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
    printf("nb_ants = %d\n", e->nb_ants);
    printf("papp = %d\n", papp);
    printf("pathtravel = %d\n", path_travel);
	printf("nb_path = %d\n", e->nb_path);
	}
	int ants = 0, ants_walking = 0;
	while (papp > 0)
	{
		ants += path_needed;
		ants_walking += path_needed;
		int current_path = 0;
		for (int i = 1; i <= ants_walking; i++)
		{
			add_fourmi(i, current_path, ants_walking, ants);
			current_path++;
			if (current_path % e->nb_path == 0)
				current_path = 0;
		}
		papp--;
	}
//    printf("chemin 1 = %d\n", e->tab_way->path_master[0].path[0].node);

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

void	do()
