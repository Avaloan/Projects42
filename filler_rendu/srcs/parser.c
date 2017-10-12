/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 01:34:43 by snedir            #+#    #+#             */
/*   Updated: 2017/10/12 07:14:14 by snedir           ###   ########.fr       */
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
	/*
	 * Possible erreur avec e->player_piece
	 */
	if (e->player_piece)
	{
		return (1);
	}
	/*
	 * Avec la statique plus besoin de ce test
	 */
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
	if (e->map_x && e->map_y)
		return (1);
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
	if (enable_check_piece(e)) //ancienne condition peut etre source d'erreur
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
	if (!e->piece)
	{
		e->size_piece = e->piece_y * e->piece_x + e->piece_y;
		e->piece = (char*)ft_memalloc(sizeof(char) * e->size_piece);
		/*
		 * penser qu'un return apres allocation
		 * pour ne pas le laisser tester la line
		 */
		return (0);
	}
	while (line[i] != '\0')
	{
		/*
		 * Copie de la piece
		 */
		e->piece[e->iter_piece] = line[i];
		i++;
		e->iter_piece++;
	}
	if (line[i] == '\0' && e->iter_piece < e->size_piece - 1)
		// changement au lieu du !=
	{
		e->piece[e->iter_piece] = '\n';
		e->iter_piece++;
	}
	/*
	 * En l'attente d'un vrai parser
	 * REMEMBER LES RETURN APRES ALLOC POUR LE PARSER
	 */
	if (e->iter_piece == e->size_piece - 1)
	{
		printf("PLEASE\n");
		e->size_piece = 0;
		e->iter_piece = 0;
		e->check_piece = 0;
		e->piece_x = 0;
		e->piece_y = 0;
		printf("%s\n\n", e->piece);
		ft_strdel(&e->piece);
		return (1);
	}
	return (0);
}

int parse_map(t_env *e, char *line)
{
	int i;

	i = 4; // manoeuvre risky skip nombre d'espace
	//printf("iter piece %d %d %s\n", e->iter_piece, e->map_y, line);
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
		return (0);
	}
	if (!(e->map_x && e->map_y))
		return (-1);
	/*
	 * penser qu'un return apres allocation
	 * pour ne pas le laisser tester la line
	 */
	while (line[i])
	{
		if (line[i] != e->map[e->iter_map][i - 4])
			e->map[e->iter_map][i - 4] = line[i];
		i++;
	}
	e->iter_map += 1;
	if (e->iter_map == e->map_y)
	{
		e->iter_map = 0;
		e->check_map = 2; //A mieux placer
		printf("ZKKK\n");
		return (1);
	}
	return (0);
}

int parser(t_env *e, char *line)
{
	int opti;
	int opti2;
	static int i = 0;

	opti = 0;
	opti2 = 0;
	if (get_player_number(e, line) != 1)
		return (-1);
	if (get_size_map(e, line) != 1)
		return (-1);
	if (e->check_map != 2)
	{
		opti = parse_map(e, line);
		if (opti == -1)
			return (-1);
		else if (opti == 0)
			return (0);
		print_map(e);
	}
	if (!e->check_piece)
		if (get_size_piece(e, line) == -1)
			return (-1);
	printf("e->chkpiece %d\n", e->check_piece);
	if (e->check_piece)
	{
		i++;
		printf("e->chkpiece %d STAT %d LINE %s\n", e->check_piece, i, line);
		opti2 = get_piece(e, line);
		if (opti2 == -1)
			return (-1);
		else if (opti2 == 0)
			return (0);
	}
	e->check_map = 0;
	return (1);
}

int main()
{
	t_env *e = (t_env*)ft_memalloc(sizeof(t_env));
	char *line = NULL;
	int fd = open("resources/report", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		/*if (!(e->map_x && e->map_y))
			get_size_map(e, line);
		if (parse_map(e, line) == 1)
		{
			print_map(e);
			printf("\n");
		}*/
		parser(e, line);
		free(line);
	}
	return (0);
}
