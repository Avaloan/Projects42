/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 05:02:05 by snedir            #+#    #+#             */
/*   Updated: 2018/03/06 00:24:10 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		print_line(t_env *e)
{
	while (E_LINE)
	{
		ft_putstr(E_LINE->line);
		write(1, "\n", 1);
		E_LINE = E_LINE->next;
	}
}

int			check_valid_pipe(t_env *e)
{
	if (e->start != -5 && e->end != -5)
	{
		FLAG_ROOM = 1000;
		return (FLAG_ROOM);
	}
	exit_error();
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
