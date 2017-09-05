/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_revoir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 01:06:29 by snedir            #+#    #+#             */
/*   Updated: 2017/07/26 03:33:03 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int search_first_pos(t_map *map, t_play *player)
{
	int i =			0;
	int j = 0;
	char c;

	c = PIECE;
	while (i < Y)
	{
		while (j < X)
		{
			if (MAP[i][j] == c)
			{
				/*ajouter cette position a la liste chainee*/
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

int search_closest_enemy(t_map *map, t_play *player, int _32)
{
	int i;
	int j;

	i = Y_POS; //0
	j = X_POS; //0
	while (i < Y)
	{
		while (j < X)
		{
			if (MAP[i][j] == ENEMY_LAST + troll)
			{
				CLOSE = abs(i - Y_POS) + abs(j - X_POS);
				printf("close the gap to the heaveeeen %d\n", CLOSE);
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int smallest_distance(t_	play *player)
{
	t_lst *ret;
	int close;

	close = 0;
	if (ELEM)
	{
		close = CLOSE;
		while (ELEM)
		{
			if (close > CLOSE)
				close = CLOSE;
			ELEM = NEXT_ELEM;
		}
	}
	return (close);
}

t_lst *return_closest(t_play *player, int close)
{
	while (ELEM)
	{
		if (close == CLOSE)
			return (ELEM);
		ELEM = NEXT_ELEM;
	}
	return (NULL);
}


int put_piece(t_map *map, t_play *player)
{
	int y;
	int x;
	int p_y;
	int p_x;
	int save;

	y = Y_POS;
	x = X_POS;
	save = X_POS;
	p_y = 0;
	p_x = 0;
	while (y < Y && p_y < SIZE_Y)
	{
		while (x < X && p_x < SIZE_X)
		{
			if (INPUT[p_y][p_x] == '*' && (MAP[y][x] == PIECE ||
						MAP[y][x] == PIECE + 32))
				ANCHOR++;
			if (ANCHOR > 1)
				return (0);
			if (INPUT[p_y][p_x] == '*' && (MAP[y][x] != '.' &&
						MAP[y][x] != PIECE && MAP[y][x] != PIECE + 32))
				return (0);
			if (INPUT[p_y][p_x] == '*')
			{
				MAP[y][x] = INPUT[p_y][p_x];
				add_list(player, y, x);
			}
			x++;
			p_x++;
		}
		x = save;
		p_x = 0;
		p_y++;
		y++;
	}
	if (ANCHOR == 1)
		return (1);
	return (0);
}

