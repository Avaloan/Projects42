/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 00:32:44 by snedir            #+#    #+#             */
/*   Updated: 2017/11/29 06:01:20 by snedir           ###   ########.fr       */
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

int		save_path(t_env *e, int i)
{
	if (i == e->start)
	{
		print_name(e, i);
		return (32);
	}
	if (save_path(e, e->matrix[i].parent) == 32)
		print_name(e, i);
	return (32);
}

int			bfs(t_env *e)
{
	int		stock;
	int		iter;
	int		test;

	add_queue_elem(e, e->start);
	e->matrix[E_FILE->id].visited = '1';
	e->matrix[E_FILE->id].parent = -4;
	iter = 0;
	test = 0;
	int labaise = 0;
	while (E_FILE)
	{
		stock = E_FILE->id;
		printf("current elem %d\n", E_FILE->id);
		if (stock == e->end)
		{
			save_path(e, e->end);
			printf("\n");
			test++;
		//	printf("after save path stock %d\n", stock);
		}
		dequeue(e);
		//if(E_FILE){printf("Next elem %d\n", E_FILE->id);}
		while (iter < e->count)
		{
			if (e->matrix[stock].tab[iter] == 1)
			{
				e->matrix[iter].parent = stock;
		//		printf("node connected%d\n", iter);
				if (iter != e->matrix[iter].parent || labaise == 0)
				{
					labaise++;
		//			printf("node not visited%d\n", iter);
//					printf("iter = %d\n", iter);
					if (iter != e->end)
					{
						//e->matrix[iter].visited = '1';
						add_queue_elem(e, iter);
					}
					if (iter == e->end)
					{
						e->matrix[iter].parent = stock;
						save_path(e, e->end);
						printf("\n");
					}
				}
			}
			iter++;
		}
		//printf("\n\n");
		//if (test > 0)
		//	printf("%d ", stock);
		iter = 0;
	}
	return (0);
}

int			path_finding(t_env *e)
{
	if (!e->matrix)
		exit_error(e);
	if (bfs(e))
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
	path_finding(e);
	//print_line(e);
	printf("start = %d | end = %d\n", e->start, e->end);
	//print_room(e);
	
	print_matrix(e);
}
