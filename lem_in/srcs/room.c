/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 03:50:39 by snedir            #+#    #+#             */
/*   Updated: 2017/11/23 04:29:07 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			check_valid_pipe(t_env *e)
{
	if (e->start != -5 && e->end != -5)
	{
		FLAG_ROOM = 1000;
		return (FLAG_ROOM);
	}
	exit_error(e);
	return (0);
}


int			check_valid_room(char *line, t_env *e)
{
	int		i;
	int		spaceballs;
	
	spaceballs = 0;
	i = 0;
	if (line[0] == ' ' || line[0] == 'L' || line[0] == '-')
		return (0);
	while (line[++i])
	{
		if (line[i] == '-')
			return (check_valid_pipe(e));
		else if (line[i] < 32 || line[i] > 126)
			return (0);
		if (line[i] == ' ')
		{
			while (line[i] == ' ')
				i++;
			if (!(line[i]) || !(ft_isdigit(line[i])))
				return (spaceballs);
			spaceballs++;
		}
	}
	return (spaceballs);
}

int			get_room_name(char **name, char *line)
{
	size_t	i;

	i = -1;
	while (line[++i] != ' ')
		;
	if (!(*name = ft_strnew(i)))
		return (0);
	*name = ft_strncpy(*name, line, i);
	return (1);
}

int			room_exist(t_env *e, char *to_compare)
{
	t_room	*tmp;

	tmp = E_ROOM;
	while (tmp)
	{
		if (!(ft_strcmp(tmp->room_name, to_compare)))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void		pending(t_env *e)
{
	if (PENDING_START)
	{
		e->start = e->count;
		PENDING_START = 0;
	}
	else if (PENDING_END)
	{
		e->end = e->count;
		PENDING_END = 0;
	}
}

int			get_room(char *line, t_env *e)
{
	char	*name;
	int		check;

	check = check_valid_room(line, e);
	if (check == 1000)
		return (FLAG_ROOM);
	if (check != 2)
		return (STOP_FLAG);
	if (!get_room_name(&name, line))
	{
		free(name);
		return (ERROR_MALLOC);
	}	// MALLOC ERROR
	if (!room_exist(e, name))
		return (ERROR_FLAG);
	if (PENDING_START == 1 && PENDING_END == 1)
		return (ERROR_FLAG); // ERREUR SORTIE ERROR ENTREE STANDARD
	else if (PENDING_START == 1 || PENDING_END == 1)
		pending(e);
	add_elem_room(name, e);
	free(name);
	e->count++;
	return (1);
}
