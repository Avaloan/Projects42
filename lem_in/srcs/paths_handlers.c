/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 05:05:53 by snedir            #+#    #+#             */
/*   Updated: 2018/01/24 02:52:45 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		norme_delete_path(t_norme *st_l)
{
	st_l->stock_free = st_l->tmp_path->next;
	free(st_l->tmp_path);
	st_l->tmp_path->next = st_l->stock_free;
	st_l->tmp_path = st_l->tmp_path->next;
}

void		delete_path(t_env *e)
{
	t_norme		st_l;

	st_l.tmp_master = e->list_path;
	while (st_l.tmp_master)
	{
		st_l.tmp_path = st_l.tmp_master->path;
		if (st_l.tmp_master->selected == 2)
		{
			while (st_l.tmp_path)
				norme_delete_path(&st_l);
			st_l.stock_free_master = st_l.tmp_master->next_path;
			free(st_l.tmp_master);
			st_l.tmp_master->next_path = st_l.stock_free_master;
			st_l.tmp_master = st_l.tmp_master->next_path;
			st_l.good_shit->next_path = st_l.stock_free_master;
		}
		else
		{
			st_l.good_shit = st_l.tmp_master;
			st_l.tmp_master = st_l.tmp_master->next_path;
		}
	}
	e->current = st_l.good_shit;
}

void		compare_paths(t_env *e, int src, int dst, t_path *tmp)
{
	t_path	*tmp2;

	while (++dst < e->nb_path)
	{
		tmp = e->tab_way[dst].path_master->path->next;
		tmp2 = e->tab_way[src].path_master->path->next;
		if (dst == src)
		{
			dst++;
			continue ;
		}
		while (tmp->next && tmp2->next)
		{
			if (tmp->node == tmp2->node)
			{
				if (src > dst)
					e->tab_way[src].path_master->selected = 2;
				else
					e->tab_way[dst].path_master->selected = 2;
				return ;
			}
			tmp = tmp->next;
			tmp2 = tmp2->next;
		}
	}
}

void		block_selected_path(t_env *e)
{
	int		i;
	t_path	*tmp;

	i = -1;
	while (++i < e->nb_path)
	{
		if (e->tab_way[i].path_master->selected != 2)
		{
			tmp = e->tab_way[i].path_master->path;
			while (tmp)
			{
				e->matrix[tmp->node].parent = 654;
				tmp = tmp->next;
			}
		}
	}
}

int			select_path(t_env *e)
{
	int		path_to_check;
	int		nb_failed;

	path_to_check = 0;
	nb_failed = 0;
	if (e->rustine == 0)
	{
		assign_path_to_tab(e);
		e->rustine = 1;
	}
	while (++path_to_check < e->nb_path)
		compare_paths(e, path_to_check, e->nb_bfs - 1, NULL);
	nb_failed = nb_wrong_path(e);
	if (nb_failed)
	{
		e->nb_path -= nb_failed;
		wash_matrix(e);
		delete_path(e);
		assign_path_to_tab(e);
		block_selected_path(e);
	}
	return (nb_failed);
}
