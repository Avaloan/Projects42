/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 06:56:53 by snedir            #+#    #+#             */
/*   Updated: 2017/06/15 05:31:29 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_map *allocate(void)
{
	t_map *map;

	map = (t_map*)malloc(sizeof(t_map));
	X = 0;
	Y = 0;
	Z = 0;
	CHECK = 0;
	MAP = NULL;/*
	map->size_x = 0;
	map->size_y = 0;*/
	return (map);
}

t_play *init(void)
{
	t_play *player;

	player = (t_play*)malloc(sizeof(t_play));
	PLAYER_NB = 0;
	CHECK_P = 0;
	INPUT = NULL;
	SIZE_Y = 0;
	SIZE_X = 0;
	PIECE = '\0';
	ITER = 0;
	ENEMY_LAST = '\0';
	return (player);
}

char **create_map(int y, int x) //allocate 2d array or 1d
{
	char **ptr;
	int i;

	ptr = (char**)malloc(sizeof(char*) * y + 1);
	i = 0;
	while (i < x)
	{
		ptr[i] = (char*)malloc(sizeof(char) * x + 1);
		i++;
	}
	return (ptr);
}

void fill_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < Y)
	{
		while (j < X)
		{
			MAP[i][j] = '.';
			j++;
		}
		MAP[i][j] = '\0';
		j = 0;
		i++;
	}
	MAP[i] = NULL;
}

int get_size_map(char *line, t_map *map)
{
	char *tmp;
	int i;
	int size;

	i = 0;
	size = 0;
	if(!(tmp = ft_strstr(line, "Plateau")))
		return (0);
	while (tmp[i] && tmp[i] != '\n')
	{
		while (ft_isdigit(tmp[i]))
		{
			i++;
			size++;
		}
		if (size)
		{
			if (map->y)
				X = ft_atoi(ft_strsub(tmp + i - size, 0, size));
			else
				Y = ft_atoi(ft_strsub(tmp + i - size, 0, size));
			size = 0;
		}
		i++;
	}
	if (map->x && map->y)
		return (1);
	return (0);
} 

int get_size_piece(char *line, t_play *player)
{
	char *tmp;
	int i;
	int size;

	i = 0;
	size = 0;
	if (!(tmp = ft_strstr(line, "Piece")))
		return (0);
	while (tmp[i] && tmp[i] != '\n')
	{
		while (ft_isdigit(tmp[i]))
		{
			i++;
			size++;
		}
		if (size)
		{
			if (SIZE_Y)
				SIZE_X = ft_atoi(ft_strsub(tmp + i - size, 0, size));
			else
				SIZE_Y = ft_atoi(ft_strsub(tmp + i - size, 0, size));
			size = 0;
		}
		i++;
	}
	if (SIZE_Y && SIZE_X)
		return (1);
	return (0);
} 

int	get_player_number(char *line, t_play *player)
{
	char *str;

	if (!(str = ft_strchr(line, 'p')))
		return (0);
	if (*(str + 1) == '1')
	{
		PLAYER_NB = 1;
		PIECE = 'O';
		ENEMY_LAST = 'x';
	}
	else if (*(str + 1) == '2')
	{
		PLAYER_NB = 2;
		PIECE = 'X';
		ENEMY_LAST = 'o';
	}
	else
		return (0);
	return (1);
}

int get_space_parsing_map(t_map *map)
{
	char *str2;
	int size;

	str2 = ft_itoa(map->y);
	size = ft_strlen(str2);
	free(str2);
	return (size + 2);
}

int check(char *line, int nb_space, t_map *map)
{
	int i;

	i = 0;
	
	while (i < nb_space - 1)
	{
		if (line[i] != '0')
			return (0);
		i++;
	}
	if (line[i] != ' ')
		return (0);
	CHECK = 1;
	return (1);
}


void diff_piece(char *line, t_play *player)
{
	int i;

	i = 0;
	while (i < SIZE_X)
	{
		INPUT[ITER][i] = line[i];
		i++;
	}
}

void parse_piece(t_play *player, char *line)
{
	char *tmp;
	char **piece;

	if (CHECK_P)
	{
		diff_piece(line, player);
		ITER++;
		if (ITER >= SIZE_Y)
		{
			ITER = 0;
			CHECK_P = 0;
		}
	}
	if ((get_size_piece(line, player)))
	{
		CHECK_P = 1;
		INPUT = create_map(SIZE_Y, SIZE_X);
	}
}

void parse_map(t_map *map, char *line)
{
	int nb_space;
	int i;

	if (Z == Y)
	{
		CHECK = 0;
		Z = 0;
		return ;
	}
	i = 0;
	nb_space = get_space_parsing_map(map);
	if (MAP == NULL)
	{
		MAP = create_map(Y, X);
		fill_map(map);
	}
	if (!CHECK)
	{
		if (!check(line, nb_space, map))
				return ;
	}
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == 'O' || line[i] == 'X' ||
				line[i] == 'o' || line[i] == 'x' )
			MAP[Z][i - nb_space] = line[i];
		i++;
	}
	Z++;
}

void	parser(t_play *player, t_map *map, char *line)
{
	int i = 0;
	get_player_number(line, player);
	get_size_map(line, map);
	parse_map(map, line);
	parse_piece(player, line);
}

int		search_enemy(t_map *map, t_play *player, int pos[], int use)
{
	int i = 0;
	int j = 0;
	char c;
	
	if (use == 0)
		c = ENEMY_LAST;
	else
		c = PIECE;
	while (i < Y)
	{
		while (j < X)
		{
			if (MAP[i][j] == c || MAP[i][j] == c - 32)
			{
				pos[0] = i;
				pos[1] = j;
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

/*
int		niklebatard(t_map *map, t_play *player)
{
	int i = 0;
	int j = 0;
	int enemy_pos[2];
	char player_pos[2];
*/





int main(int argc, char **argv)
{
	char *line = NULL;
	int i = 0;
	int ret = open("test2ParseMap", O_RDONLY);
	t_map *map = allocate();
	t_play *player = init();
	while (get_next_line(ret, &line))
	{
		parser(player, map, line);
	}
	int pos[2];
	search_enemy(map, player, pos, 0);
	i = 0;
	while (i < 2)
	{
		printf("%d\n", pos[i]);
		i++;
	}
}
