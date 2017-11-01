/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 01:34:43 by snedir            #+#    #+#             */
/*   Updated: 2017/11/01 03:59:09 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>


/*
 * Penser a controler les flags de check pour entree ou sortie de fonction
 * Pour pouvoir faire les free et remettre a 0 ceux necessaires
 */

/*
 * A ne lancer qu'une fois
 */

int get_player_number(t_env *e, char *line)
{
	char *str;

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

int get_size_map(t_env *e, char *line)
{
	char *str;
	int i;
	int size;

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

/*
 * Trash pour la norme
 */

/*
 * END
 */

/*
 * MISC
 */

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
	if (enable_check_piece(e))
		return (1);
	return (-1);
}

int get_piece(t_env *e, char *line)
{
	int i;

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

int parse_map(t_env *e, char *line)
{
	int i;

	i = 4;
	if (e->check_map == 0)
	{
		if (check_space(e, line) < 0)
			return (-1);
		if (!(e->map))
		{
			e->map = create_map(e);
			fill_map(e);
			return (0);
		}
		else
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

int parser(t_env *e, char *line)
{
	static int i = 0;

	if (i == 0)
	{
		if (get_player_number(e, line) != 1)
			return (-1);
		if (get_size_map(e, line) != 1)
			return (-1);
		i++;
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

/*
 * Penser a changer le type de map, en une structure
 * Pour avoir un flag qui verifie la proximite immediate de l'ennemi
 */

#include <unistd.h>

/*
 * attention a ne pas sortir de la map
 */

int put_piece(t_env *e, int y, int x, int anchor)
{
	int i;
	int ycopy;
	int xcopy;

	ycopy = y;
	xcopy = x;
	i = 0;
	if ((ycopy + e->piece_y) >= e->map_y)
		return (0);
	if ((xcopy + e->piece_x) >= e->map_x)
		return (0);
	while (i < ft_strlen(e->piece) && xcopy < e->map_x && ycopy < e->map_y)
	{
		//dprintf(2, "%c %c\n\n", e->piece[i], e->map[ycopy][xcopy]);
		if (e->piece[i] == '*' && e->map[ycopy][xcopy] == e->enemy_piece)
			return (0);
		if (e->piece[i] == '\n')
		{
			i++;
			ycopy++;
			xcopy = x;
		}
		if (xcopy > e->map_x || ycopy >= e->map_y)
			return (0);
		if (e->map[ycopy][xcopy] == e->player_piece && e->piece[i] == '*')
		{
			anchor++;
			xcopy++;
			i++;
		}
		if (e->piece[i] == '*' && e->map[ycopy][xcopy] == '.')
		{
			i++;
			xcopy++;
		}
		if (e->piece[i] == '*' && e->map[ycopy][xcopy] != '.' && anchor != 0)
			return (0);
		if (e->piece[i] != '\n' && e->piece[i] != '*')
		{
			i++;
			xcopy++;
		}
	}
	if (anchor == 1)
		return (1);
	return (0);
}

/*
 * RAISONNEMENT
 * prendre la position la plus proche de l'ennemi
 * si une position est collee a l'ennemi priorite
 */


/*
 * avoir un tableau statique a mettre a jour qui contient les possibilites
 */

#include <stdlib.h>
#include <time.h>
int main()
{
	t_env *e = (t_env*)ft_memalloc(sizeof(t_env));
	char *line = NULL;
	//int fd = open("resources/report", O_RDWR);
	//dprintf(2,"%d\n", fd);
	while (get_next_line(0, &line))
	{
		//dprintf(fd, "%s\n", line);
		parser(e, line);
		free(line);
	}
	return (0);
}
