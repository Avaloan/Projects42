/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 23:05:28 by snedir            #+#    #+#             */
/*   Updated: 2017/11/07 05:47:12 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			parser(t_env *e, char *line)
{
	if (e->cheat == 0)
	{
		if (get_player_number(e, line) != 1)
			return (-1);
		if (get_size_map(e, line) != 1)
			return (-1);
		e->cheat++;
	}
	if (e->check_map != 2)
	{
		e->opti = parse_map(e, line);
		if (e->opti != 1)
			return (0);
	}
	if (!e->check_piece)
		if (get_size_piece(e, line) == -1)
			return (-1);
	if (e->check_piece)
	{
		e->opti = get_piece(e, line);
		if (e->opti != 1)
			return (0);
	}
	return (1);
}

int			main(void)
{
	t_env	*e;
	char	*line;

	e = (t_env*)ft_memalloc(sizeof(t_env));
	line = NULL;
	while (get_next_line(0, &line))
	{
		parser(e, line);
		free(line);
	}
	return (0);
}
