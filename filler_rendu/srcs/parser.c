/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 01:34:43 by snedir            #+#    #+#             */
/*   Updated: 2017/11/07 05:49:03 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

int			get_player_number(t_env *e, char *line)
{
	char	*str;

	if (e->player_piece)
		return (1);
	if (!(str = ft_strchr(line, '$')))
		return (-1);
	str = ft_strchr(line, 'p');
	if (*(str + 1) == '1' && ft_strstr(line, "snedir"))
	{
		e->player_piece = 'O';
		e->enemy_piece = 'X';
	}
	else if (*(str + 1) == '2' && ft_strstr(line, "snedir"))
	{
		e->player_piece = 'X';
		e->enemy_piece = 'O';
	}
	else
		return (-1);
	return (1);
}

int			get_size_map(t_env *e, char *line)
{
	char	*str;
	int		i;
	int		size;

	i = 0;
	size = 0;
	if (!(str = ft_strstr(line, "Plateau")))
		return (-1);
	while (str[i] && str[i] != ':')
	{
		while (ft_isdigit(str[i]))
		{
			i++;
			size++;
		}
		if (size)
			norme_map_piece(e, ft_strsub(str + i - size, 0, size), &size, 1);
		i++;
	}
	if (e->map_x && e->map_y)
		return (1);
	return (-1);
}

int			get_size_piece(t_env *e, char *line)
{
	char	*str;
	int		i;
	int		size;

	i = 0;
	size = 0;
	if (!(str = ft_strstr(line, "Piece")))
		return (-1);
	while (str[i] && str[i] != ':')
	{
		while (ft_isdigit(str[i]))
		{
			i++;
			size++;
		}
		if (size)
			norme_map_piece(e, ft_strsub(str + i - size, 0, size), &size, 0);
		i++;
	}
	if (enable_check_piece(e))
		return (1);
	return (-1);
}

int			get_piece(t_env *e, char *line)
{
	int		i;

	i = 0;
	if (!(e->piece_x && e->piece_y))
		return (-1);
	if (check_if_piece(line) == -1)
		return (-1);
	e->size_piece = e->piece_y * e->piece_x + e->piece_y;
	if (!e->piece)
		e->piece = (char*)ft_memalloc(sizeof(char) * e->size_piece);
	while (line[i] != '\0')
	{
		e->piece[e->iter_piece] = line[i];
		i++;
		e->iter_piece++;
	}
	if (line[i] == '\0' && e->iter_piece < e->size_piece - 1)
	{
		e->piece[e->iter_piece] = '\n';
		e->iter_piece++;
	}
	if (reset_params(e, 1))
		return (1);
	return (0);
}

int			parse_map(t_env *e, char *line)
{
	int		i;

	i = 4;
	if (e->check_map == 0)
	{
		if (check_space(e, line) < 0)
			return (-1);
		if (!(e->map))
		{
			e->map = create_map(e);
			fill_map(e);
		}
		return (0);
	}
	while (line[i])
	{
		if (line[i] != e->map[e->iter_map][i - 4])
			e->map[e->iter_map][i - 4] = line[i];
		i++;
	}
	e->iter_map += 1;
	if (reset_params(e, 0))
		return (1);
	return (0);
}
