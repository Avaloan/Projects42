/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 01:32:29 by snedir            #+#    #+#             */
/*   Updated: 2017/11/03 02:27:43 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int abs(int a)
{
	return (a > 0 ? a : -a);
}

/*
 * **Regles selection algo carli**
 *
 * parcourir la liste des possibilites prendre successivement
 * - position la plus loin sur les axes en x puis en y
 * - si position collee a un ennemi ignore ou a un mur
 */

void printf_possible(t_env *e, int pos)
{
	dprintf(2, "valid_y %d | valid_x %d | dist %d\n", e->algo[pos].valid_y, e->algo[pos].valid_x, e->algo[pos].nearest_enemy);
}

void clean_algo(t_env *e)
{
	int i;

	i = -1;
	while (++i < e->nb_possib)
	{
		e->algo[i].valid_x = 0;
		e->algo[i].valid_y = 0;
	}
	e->nb_possib = 0;
}

void affich_possib(t_env *e)
{
	int i = 0;
	int mem = 0;
	int seed = 0;
	int cpy = e->nb_possib - 1;
	int lowest_y = 0;
	int highest_y = 0;
	while (cpy >= 0)
	{
		if (e->ferme == 1)
		{
			highest_y = e->algo[cpy].valid_y;
			if (highest_y == e->map_y)
				dprintf(2,"mapppp_y %d\n", e->map_y);
		}
		if (e->fuite == 1 && e->ferme == 0)
		{
			lowest_y = e->algo[cpy].valid_x;
				dprintf(2,"lowest_y %d\n", lowest_y);
			if (lowest_y == 0)
			{
				e->ferme = 1;
				break ;
			}
			//dprintf(2, "valid_y %d | valid_x %d | seed %d | lowest %d\n", e->algo[cpy].valid_y, e->algo[cpy].valid_x, seed, lowest_y);
			/*if (seed < e->algo[cpy].valid_x && lowest_y >= e->algo[cpy].valid_y)
			{
				mem = cpy;
				seed = e->algo[cpy].valid_x;
				lowest_y = e->algo[cpy].valid_y;
			dprintf(2, "valid_y %d | valid_x %d | seed %d | lowest %d HUSS\n", e->algo[cpy].valid_y, e->algo[cpy].valid_x, seed, lowest_y);
				if (lowest_y == 0)
				{
					dprintf(2, "YAY\n");
					e->ferme = 1;
				}
			}*/
		}
		else
		{
			if (seed == 0)
				seed = e->algo[cpy].nearest_enemy;
			if (seed >= e->algo[cpy].nearest_enemy && e->fuite == 0)
			{
				mem = cpy;
				seed = e->algo[cpy].nearest_enemy;
				if (seed == 1)
				{
					e->fuite = 1;
					break ;
				}
			}
		}
		cpy--;
	}
	ft_putnbr(e->algo[mem].valid_y);
	write(1, " ", 1);
	ft_putnbr(e->algo[mem].valid_x);
	write(1, "\n", 1);
	clean_algo(e);
}


void analyse_map(t_env *e, int pos)
{
	int i;
	int j;
	int dist;

	i = 0;
	j = 0;
	dist = 0;
	while (i < e->map_y)
	{
		while (j < e->map_x)
		{
			if (e->map[i][j] == e->enemy_piece)
			{
				dist = abs(j - e->algo[pos].valid_x) + abs(i -
						e->algo[pos].valid_y);
				if (e->algo[pos].nearest_enemy == 0)
					e->algo[pos].nearest_enemy = dist;
				if (dist < e->algo[pos].nearest_enemy)
					e->algo[pos].nearest_enemy = dist;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void analyse_algo(t_env *e)
{
	int i;

	i = 0;
	while (i < e->nb_possib)
	{
		analyse_map(e, i);
		i++;
	}
}

int try_piece(t_env *e)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < e->map_y)
	{
		while (j < e->map_x)
		{
				if (put_piece(e, i, j, 0))
				{
					e->algo[e->nb_possib].valid_x = j;
					e->algo[e->nb_possib].valid_y = i;
					e->nb_possib++;
				}
			j++;
		}
		j = 0;
		i++;
	}
	analyse_algo(e);
	affich_possib(e);
	usleep(250000);
	return (0);
}


