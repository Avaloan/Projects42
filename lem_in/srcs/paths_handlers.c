/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 05:05:53 by snedir            #+#    #+#             */
/*   Updated: 2018/01/23 05:51:31 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		delete_path(t_env *e)
{
	t_path_m	*tmp_master;
	t_path_m	*stock_free_master;
	t_path		*tmp_path;
	t_path		*stock_free;
	t_path_m	*good_shit;

	tmp_master = e->list_path;
	while (tmp_master)
	{
		tmp_path = tmp_master->path;
		if (tmp_master->selected == 2)
		{
			while (tmp_path)
			{
				stock_free = tmp_path->next;
				free(tmp_path);
				tmp_path->next = stock_free;
				tmp_path = tmp_path->next;
			}
			stock_free_master = tmp_master->next_path;
			free(tmp_master);
			tmp_master->next_path = stock_free_master;
			tmp_master = tmp_master->next_path;
			good_shit->next_path = stock_free_master;
		}
		else
		{
			good_shit = tmp_master;
			tmp_master = tmp_master->next_path;
		}
	}
	e->current = good_shit;
}

int			compare_paths(t_env *e, int src)
{
	t_path	*tmp;
	t_path	*tmp2;
	int		dst;

	dst = e->nb_bfs;
	tmp = NULL;
	tmp2 = NULL;
	while (dst < e->nb_path)
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
				return (1);
			}
			tmp = tmp->next;
			tmp2 = tmp2->next;
		}
		dst++;
	}
	return (0);
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
		compare_paths(e, path_to_check);
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
