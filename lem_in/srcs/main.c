/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 00:32:44 by snedir            #+#    #+#             */
/*   Updated: 2017/11/23 06:48:11 by snedir           ###   ########.fr       */
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

void		exit_error(t_env *e)
{
	printf("ERROR\n");
	print_room(e);
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
			printf("%d ", e->matrix[i][j]);
		printf("\n");
		j = -1;
	}
}

int			check_path(t_env *e)

int			main(void)
{
	t_env	*e;

	e = (t_env*)ft_memalloc(sizeof(t_env));
	e->start = -5;
	e->end = -5;
	e->connection[0] = -5;
	e->connection[1] = -5;
	if (!parser(e))
	{

	print_line(e);
	//print_room(e);
	print_matrix(e);
	printf("start = %d | end = %d\n", e->start, e->end);
}