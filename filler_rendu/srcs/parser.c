/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 01:34:43 by snedir            #+#    #+#             */
/*   Updated: 2017/10/11 06:22:59 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

/*
 * A ne lancer qu'une fois
 */
int get_player_number(t_env *e, char *line)
{
	char *str;

	if (!(str = ft_strchr(line, '$')))
		return (-1);
	str = ft_strchr(line, 'p');
	if (*(str + 1) == '1' && ft_strstr(line, "snedir"))
	{
		e->player_piece = 'O';
		e->player_piece = 'o';
		e->enemy_piece = 'X';
		e->enemy_last = 'x';
	}
	else if (*(str + 1) == '2' && ft_strstr(line, "snedir"))
	{
		e->player_piece = 'X';
		e->player_piece = 'x';
		e->enemy_piece = 'O';
		e->enemy_last = 'o';
	}
	else
		return (-1);
	return (1);
}

int get_size_map(t_env *e, char *line)
{
	char *str;
	int i;
	int size;

	i = 0;
	size = 0;
	e->map_y = 0;
	e->map_x = 0;
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
		{
			if (e->map_y)
				e->map_x = ft_atoi(ft_strsub(str + i - size, 0, size));
			else
				e->map_y = ft_atoi(ft_strsub(str + i - size, 0, size));
			size = 0;
		}
		i++;
	}
	if (e->map_x && e->map_y)
		return (1);
	return (-1);
}
/*
 * END
 */

int get_size_piece(t_env *e, char *line)
{
	char *str;
	int i;
	int size;

	i = 0;
	size = 0;
	e->piece_y = 0;
	e->piece_x = 0;
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
		{
			if (e->piece_y)
				e->piece_x = ft_atoi(ft_strsub(str + i - size, 0, size));
			else
				e->piece_y = ft_atoi(ft_strsub(str + i - size, 0, size));
			size = 0;
		}
		i++;
	}
	if (e->piece_x && e->piece_y)
	{
		e->check_piece = 1;
		return (1);
	}
	return (-1);
}

int check_if_piece(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '.' && line[i] != '*' && line[i] != '\0')
			return (-1);
		i++;
	}
	return (1);
}

int get_piece(t_env *e, char *line)
{
	int i;
	
	i = 0;
	if (!(e->piece_x && e->piece_y))
		return (-1);
	if (check_if_piece(line) == -1)
		return (-1);
	if (!e->piece)
	{
		e->size_piece = e->piece_y * e->piece_x + e->piece_y;
		e->piece = (char*)ft_memalloc(sizeof(char) * e->size_piece);
	}
	while (line[i] != '\0')
	{
		e->piece[e->iter_piece] = line[i];
		i++;
		e->iter_piece++;
	}
	if (line[i] == '\0' && e->iter_piece != e->size_piece - 1)
	{
		e->piece[e->iter_piece] = '\n';
		e->iter_piece++;
	}
	/*
	 * En l'attente d'un vrai parser
	 */
	if (e->iter_piece == e->size_piece - 1)
	{
		e->size_piece = 0;
		e->iter_piece = 0;
		e->check_piece = 0;
		e->piece_x = 0;
		e->piece_y = 0;
		ft_strdel(&e->piece);
	}
	return (0);
}


int main()
{
	t_env *e = (t_env*)ft_memalloc(sizeof(t_env));
	char *line = NULL;
	int fd = open("resources/report", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (!e->check_piece)
			get_size_piece(e, line);
		if (e->check_piece)
			get_piece(e, line);
		//free(line);
	}
	//printf("e->map_y %d | e->map_x %d\n", e->piece_y, e->piece_x);
	return (0);
}
