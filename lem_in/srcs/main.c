/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 00:32:44 by snedir            #+#    #+#             */
/*   Updated: 2018/01/17 04:38:27 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
 * FONCTIONS PARSER
 */

int			get_pipe(char *line, t_env *e);

int			get_infos(char *line, t_env *e)
{
	int		value_hash;
	
	value_hash = check_hashtag(line, e);
	if (value_hash == 1)
		return (1);
	else if (value_hash == ERROR_FLAG)
		return (ERROR_FLAG);
	else if (value_hash == STOP_FLAG)
		return (STOP_FLAG);
	else if (value_hash == 2)
	{
		if (NB_ANTS == 0)
			return (get_nb_ants(line, e));
		if (!FLAG_ROOM)
			return (get_room(line, e));
		if (FLAG_ROOM && (get_pipe(line, e) == STOP_FLAG))
			return (STOP_FLAG);
	}
	return (1);
}

void		exit_error()
{
	printf("ERROR\n");
	exit(0);
}

int			parser(t_env *e)
{
	char	*line;
	int		control;

	line = NULL;
	control = 0;
	while (get_next_line(0, &line))
	{
		control = get_infos(line, e);
		if (control == FLAG_ROOM)
			control = get_infos(line, e);
		if (control == 1)
			add_elem_line(e, line);
		else if (control == ERROR_FLAG)
			exit_error(e);
		else if (control == STOP_FLAG)
			return (0);
		free(line);
	}
	return (0);
}

void		print_line(t_env *e)
{
	while (E_LINE)
	{
		printf("%s\n", E_LINE->line);
		E_LINE = E_LINE->next;
	}
}

void		print_room(t_env *e)
{
	while (E_ROOM)
	{
		printf("ROOM %s ID %d\n", E_ROOM->room_name, E_ROOM->id);
		E_ROOM = E_ROOM->next;
	}
}

void		print_matrix(t_env *e)
{
	int		i;
	int		j;
	int		z;

	i = -1;
	j = -1;
	z = -1;
	printf(" ");
	while (++z < e->count)
		printf(" \033[34;01m%d\033[00m", z);
	printf("\n");
	z = -1;
	while (++i < e->count)
	{
		printf("\033[35;01m%d\033[00m ", i);
		while (++j < e->count)
			printf("%d ", e->matrix[i].tab[j]);
		printf("\n");
		j = -1;
	}
}

void	print_name(t_env *e, int i)
{
	t_room *tmp;

	tmp = E_ROOM;
	while (tmp)
	{
		if (tmp->id == i)
		{
			printf("%s ", tmp->room_name);
			return ;
		}
		tmp = tmp->next;
	}
}

int		save_path(t_env *e, int i, int size_path)
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

/*
void		compare_paths(t_env *e)
{
	t_path		*tmp2;
	t_path_m	*tmp;

	tmp = e->list_path;
	while (tmp)
	{
	}
}*/

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
						save_path(e, e->end, 0);
						e->nb_path++;
					}
				}
			}
			iter++;
		}
		iter = 0;
	}
	return (e->nb_path);
}

void		read_path_tab(t_env *e)
{
	int i = -1;
	while (++i < e->nb_path)
		printf("%d\n", e->tab_way[i].path_master->size_path);
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

void		wash_matrix(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < e->count)
		e->matrix[i].parent = -1;
}

void		select_path(t_env *e)
{
	int		path_to_check;
	int		nb_failed;

	path_to_check = 0;
	nb_failed = 0;
	while (++path_to_check < e->nb_path)
		nb_failed += compare_paths(e, path_to_check);
	printf("nb_failed %d\n", nb_failed);
	if (nb_failed)
	{
		wash_matrix(e);
	}
}

void		print_selected_path(t_env *e)
{
	int		i = -1;
	t_path	*tmp;

	while (++i < e->nb_path)
	{
		printf("e->nb_path = %d || i = %d || selected = %d\n", e->nb_path, i, e->tab_way[i].path_master->selected);
		if (e->tab_way[i].path_master->selected == -1)
		{
			printf("euh?\n");
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
	if (!e->matrix)
		exit_error(e);
	if (bfs(e))
	{
		if (!e->tab_way)
		{
			e->tab_way = (t_tabpath*)ft_memalloc(sizeof(t_tabpath) * e->nb_path);
			assign_path_to_tab(e);
			//read_path_tab(e);
			select_path(e);
			print_selected_path(e);
			bfs(e);
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
