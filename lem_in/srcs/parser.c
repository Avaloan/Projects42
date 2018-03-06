/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 02:09:23 by snedir            #+#    #+#             */
/*   Updated: 2018/03/06 00:31:38 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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

void		exit_error(void)
{
	write(1, "ERROR\n", 6);
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
			exit_error();
		else if (control == STOP_FLAG)
			return (0);
		free(line);
	}
	return (0);
}

void		printfourmi(t_env *e, int ants, int room, int da)
{
	if (da == DA666BEASTXBAMBOULA)
	{
		write(1, "L", 1);
		ft_putnbr(ants);
		write(1, "-", 1);
		ft_putstr(e->room_tab[room]);
		write(1, "\n", 1);
	}
	else
	{
		write(1, "L", 1);
		ft_putnbr(ants);
		write(1, "-", 1);
		ft_putstr(e->room_tab[room]);
		write(1, " ", 1);
	}
}
