/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 00:32:44 by snedir            #+#    #+#             */
/*   Updated: 2018/01/18 05:44:15 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
 * FONCTIONS PARSER
 */


int		save_path(t_env *e, int i, int size_path)
{
	if (i == e->start)
	{
		add_elem_path(e, size_path + 1, i);
		return (32);
	}
	if (save_path(e, e->matrix[i].parent, size_path + 1) == 32)
	{
		//printf("nik\n");
		add_elem_node(e, i);
		//printf("nik MAX\n");
	}
	return (32);
}

int			seek_end(t_env *e, int stock)
{
	int		i;

	i = 0;
	while (i < e->count)
	{
		if (e->matrix[stock].tab[i] == 1 && i == e->end)
			return (1);
		i++;
	}
	return (0);
}

void		print_path(t_env *e)
{
	t_path_m	*tmp;
	t_path		*tmp2;

	tmp = e->list_path;
	while (tmp)
	{
		tmp2 = tmp->path;
		while (tmp2)
		{
			print_name(e, tmp2->node);
			tmp2 = tmp2->next;
		}
		printf("\n");
		tmp = tmp->next_path;
	}
}

int			loop_cmp(t_path *src, t_path *target)
{
	while (src && target)
	{
		if (src->node == target->node)
			return (0);
		src = src->next;
		target = target->next;
	}
	return (1);
}

void		assign_path_to_tab(t_env *e)
{
	t_path_m	*tmp;
	int			i;

	tmp = e->list_path;
	i = 0;
	while (tmp)
	{
		e->tab_way[i].path_master = tmp;
		i++;
		tmp = tmp->next_path;
	}
	printf("pelase\n");
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
		{
			if (e->matrix[stock].tab[iter] == 1)
			{
				if (e->matrix[iter].parent == -1 || iter == e->end)
				{
					e->matrix[iter].parent = stock;
					if (iter != e->end)
						add_queue_elem(e, iter);
					else
					{
						//printf("what the flying fuck ?\n");
						save_path(e, e->end, 0);
						//printf("what the flying fuckening ?\n");
						e->nb_path++;
					}
				}
			}
			iter++;
		}
		iter = 0;
	}
	printf("why ?\n");
	return (e->nb_path);
}

void		read_path_tab(t_env *e)
{
	int i = -1;
	while (++i < e->nb_path)
		printf("%d\n", e->tab_way[i].path_master->size_path);
}

/*
 * Perte du chainage et attention au current pour le prochain bfs
 */

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
		//printf("selected %d\n", tmp_master->selected);
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

/*
 * Penser test selon taille du chemin pour init
 * tmp et tmp2 avant la boucle de compare_paths
 */

int			compare_paths(t_env *e, int src)
{
	t_path	*tmp;
	t_path	*tmp2;
	int		dst;
	
	dst = 0;
	while (dst < e->nb_path)
	{
		tmp = e->tab_way[dst].path_master->path->next;
		tmp2 = e->tab_way[src].path_master->path->next;
		if (dst == src)
		{
			dst++;
			continue ;
		}
		printf("dst %d || nb_path %d\n", dst, e->nb_path);
		while (tmp->next && tmp2->next)
		{
			printf("done ?\n");
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

void		wash_matrix(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < e->count)
		e->matrix[i].parent = -1;
}

int			select_path(t_env *e)
{
	int		path_to_check;
	int		nb_failed;

	path_to_check = 0;
	nb_failed = 0;
	printf("inb path %d\n", e->nb_path);
	while (++path_to_check < e->nb_path)
		nb_failed += compare_paths(e, path_to_check);
	printf("nb_failed %d\n", nb_failed);
	printf("numero nodembre %d\n", e->nb_path);
	if (nb_failed)
	{
		e->nb_path -= nb_failed;
		wash_matrix(e);
	}
	return (nb_failed);
}

void		block_selected_path(t_env *e)
{
	int		i = -1;
	t_path	*tmp;

	while (++i < e->nb_path)
	{
		//printf("e->nb_path = %d || i = %d || selected = %d\n", e->nb_path, i, e->tab_way[i].path_master->selected);
		if (e->tab_way[i].path_master->selected == -1)
		{
			//printf("euh?\n");
			tmp = e->tab_way[i].path_master->path;
			while (tmp)
			{
				e->matrix[tmp->node].parent = 654;
				tmp = tmp->next;
			}
		}
	}
}

int			path_finding(t_env *e)
{
	int i = 0;
	if (!e->matrix)
		exit_error(e);
	if (bfs(e))
	{
		if (!e->tab_way)
			e->tab_way = (t_tabpath*)ft_memalloc(sizeof(t_tabpath) * e->nb_path);
		assign_path_to_tab(e);
		//read_path_tab(e);
		if (select_path(e) != 0)
		{
			block_selected_path(e);
			delete_path(e);
			bfs(e);
			i++;
		}
		return (1);//	print_line(e);
	}
	return (0);
}

int			main(void)
{
	t_env	*e;

	e = (t_env*)ft_memalloc(sizeof(t_env));
	e->start = -5;
	e->end = -5;
	e->connection[0] = -5;
	e->connection[1] = -5;
	parser(e);
	printf("start = %d | end = %d\n", e->start, e->end);
	path_finding(e);
	print_path(e);
	//print_line(e);
	//print_room(e);
	//print_matrix(e);
}
