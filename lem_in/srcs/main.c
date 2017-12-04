/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 00:32:44 by snedir            #+#    #+#             */
/*   Updated: 2017/12/04 05:59:43 by snedir           ###   ########.fr       */
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
/*
int		save_path(t_env *e, int i)
{
	if (i == e->start)
	{
		print_name(e, i);
		return (32);
	}
	if (save_path(e, e->matrix[i].path->id) == 32)
		print_name(e, i);
	return (32);
}*/

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

/*
int			dfs(t_env *e)
{
*/

void		print_path(t_env *e, int from)
{
	t_path	*tmp;

	tmp = e->matrix[from].path;
	while (tmp)
	{
		printf("%d ", tmp->id);
		tmp = tmp->next;
	}
}

int			is_in_path(t_env *e, int to_add, int from)
{
	t_path	*tmp;
	t_path	*tmp2;
	
	tmp = e->matrix[from].path;
	tmp2 = e->matrix[to_add].path;
	printf("%p %p\n", tmp, tmp2);
	printf("to_add %d from %d\n", to_add, from);
	while (tmp)
	{
		if (tmp->id == to_add)
			return (0);
		tmp = tmp->next;
	}
	while (tmp2)
	{
		if (tmp2->id == from)
			return (0);
		tmp2 = tmp2->next;
	}
	return (1);
}

int			bfs_stock(t_env *e)
{
	int		stock;
	int		i;

	add_queue_elem(e, e->start);
	i = 0;
	while (E_FILE)
	{
		stock = E_FILE->id;
		dequeue(e);
		while (i < e->count)
		{
			if (e->matrix[stock].tab[i] == 1 && is_in_path(e, i, stock))
			{
				add_elem_path(e, i, stock);
				print_path(e, i);
				printf("\n");
				if (i != e->end)
					add_queue_elem(e, i);
				else
				{
					print_path(e, i);
					printf("yay\n");
				}
			}
			i++;
		}
		i = 0;
	}
	return (1);
}


/*
int			bfs(t_env *e)
{
	int		stock;
	int		iter;

	add_queue_elem(e, e->start, 0);
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
				if (e->matrix[iter].parent == -1)
				{
					e->matrix[iter].parent = stock;
					if (iter != e->end)
						add_queue_elem(e, iter, 0);
					else
					{
						save_path(e, e->end);
						printf("\n");
					}
				}
				else if (e->matrix[stock].parent != iter)
				{
					//print_name(e, stock);
					//print_name(e, iter);
					//printf("ihaha \n");
					if (iter == e->end)
					{
						e->matrix[iter].parent = stock;
						save_path(e, e->end);
						printf("\n");
					}
					else
						add_queue_elem(e, iter, 1);
				}
				if (e->matrix[iter].visited != '1')
				{
					e->matrix[iter].parent = stock;
					if (iter != e->end)
					{
						e->matrix[iter].visited = '1';
						add_queue_elem(e, iter);
					}
					if (iter == e->end)
					{
						e->matrix[iter].parent = stock;
						save_path(e, e->end);
						printf("\n");
						//return (1);
					}
				}
			}
			iter++;
		}
		iter = 0;
	}
	printf("yolo\n");
	//bfs2(e);
	return (0);
}*/

int			path_finding(t_env *e)
{
	if (!e->matrix)
		exit_error(e);
	if (bfs_stock(e))
		return (1);//	print_line(e);
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
	//print_line(e);
	//print_room(e);
	
	print_matrix(e);
}
