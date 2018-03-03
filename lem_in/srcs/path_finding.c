/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 05:09:48 by snedir            #+#    #+#             */
/*   Updated: 2018/03/03 04:02:59 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			save_path(t_env *e, int i, int size_path)
{
	if (i == e->start)
	{
		add_elem_path(e, size_path + 1, i);
		return (32);
	}
	if (save_path(e, e->matrix[i].parent, size_path + 1) == 32)
		add_elem_node(e, i);
	return (32);
}

void		do_bfs(t_env *e, int *iter, int stock)
{
	if (e->matrix[stock].tab[*iter] == 1)
	{
		if (e->matrix[*iter].parent == -1 || *iter == e->end)
		{
			e->matrix[*iter].parent = stock;
			if (*iter != e->end)
				add_queue_elem(e, *iter);
			else
			{
				save_path(e, e->end, 0);
				e->nb_path++;
			}
		}
	}
	*iter += 1;
}

int			bfs(t_env *e)
{
	int		stock;
	int		iter;

	add_queue_elem(e, e->start);
	iter = 0;
	e->matrix[e->start].parent = -2;
	while (E_FILE)
	{
		stock = E_FILE->id;
		dequeue(e);
		while (iter < e->count)
			do_bfs(e, &iter, stock);
		iter = 0;
	}
	if (e->tab_way)
	{
		e->nb_bfs += 1;
		e->rustine = 0;
	}
	return (e->nb_path);
}

void		wash_matrix(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < e->count)
		e->matrix[i].parent = -1;
}

int			path_finding(t_env *e)
{
	int		ret;

	ret = 0;
	if (!e->matrix)
		exit_error();
	if (bfs(e))
	{
		if (!e->tab_way)
		{
			e->tab_way = (t_tabpath*)ft_memalloc(sizeof(t_tabpath) * e->nb_path);
			assign_path_to_tab(e);
			e->rustine = 1;
		}
		ret = select_path(e);
		while (ret != 0)
		{
			bfs(e);
			ret = select_path(e);
		}
		return (1);
	}
	return (0);
}
