/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 01:32:29 by snedir            #+#    #+#             */
/*   Updated: 2017/11/04 03:38:00 by snedir           ###   ########.fr       */
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

/*
 * Atteindre enemy
 * Fermer le bas
 * jouer sur la position en x la plus petite
 */

/*
 * Lancer Algo analyse dist seulement necessaire
 */



void output(t_env *e)
{
	ft_putnbr(e->algo[e->input].valid_y);
	write(1, " ", 1);
	ft_putnbr(e->algo[e->input].valid_x);
	write(1, "\n", 1);
	clean_algo(e);
}

void reach_enemy(t_env *e, int cpy, int *near)
{
	if (*near == -1)
		*near = e->algo[cpy].nearest_enemy;
	if (*near == 1)
	{
		//dprintf(2, "MDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDR\n");
		e->input = cpy;
		REACHED = 1;
		printf_possible(e, cpy);
		return ;
	}
	if (*near >= e->algo[cpy].nearest_enemy)
	{
		//dprintf(2, "MDDUUUUUUUUUUUUUUUUUUUUUDJJDJDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDR\n");
		e->input = cpy;
		*near = e->algo[cpy].nearest_enemy;
	}
}

void close_highest_side(t_env *e, int cpy)
{
	if (e->algo[cpy].valid_y == 0)
	{
		e->input = cpy;
		CLOSED = 1;
		return ;
	}
	//dprintf(2, "lolwut\n");
	e->input = 0;
}

void close_lowest_side(t_env *e, int cpy, int *lowest)
{
	//dprintf(2, "lolZER\n");
	if (*lowest == -1)
		*lowest = e->algo[cpy].valid_y;
	if (*lowest == e->map_y - 1)
	{
		e->input = cpy;
		LOW_CLOSED = 1;
		return ;
	}
	if (*lowest <= e->algo[cpy].valid_y)
	{
		//dprintf(2, "lolZERMAAAAAAAAAAAAAAX\n");
		e->input = cpy;
		*lowest = e->algo[cpy].valid_y;
	}
}

//void reach_lowest_side

void algo(t_env *e)
{
	int cpy;
	int lowest;
	int near;

	cpy = e->nb_possib - 1;
	lowest = -1;
	near = -1;
	while (cpy >= 0)
	{
		if (REACHED == 0)
			reach_enemy(e, cpy, &near);
		if (CLOSED == 0 && REACHED == 1 && LOW_CLOSED == 1)
			close_highest_side(e, cpy);
		if (LOW_CLOSED == 0 && REACHED == 1)
			close_lowest_side(e, cpy, &lowest);
		cpy--;
	}
	output(e);
}



/*void affich_possib(t_env *e)
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
			if (highest_y == 0)
				highest_y = e->algo[cpy].valid_y;
			dprintf(2,"mapppp_y %d %d\n", highest_y, e->map_y);
			if (highest_y <= e->algo[cpy].valid_y)
			{
				mem = cpy;
				highest_y = e->algo[cpy].valid_y;
				if (e->algo[cpy].valid_x >= e->map_x / 4)
				{
					dprintf(2,"HEEEEEEEEEEEEEEEEEYA %d\n", highest_y);
					e->remonte = 1;
					e->fuite = 1;
					e->ferme = 0;
					break ;
				}
			}
		}
		if (e->fuite == 1 && e->ferme == 0)
		{
			lowest_y = e->algo[cpy].valid_y;
			//dprintf(2,"lowest_y %d\n", lowest_y);
			if (lowest_y == 0)
			{
				mem = cpy;
				dprintf(2,"JUSTICEEEEEEEEEEEEEEEEE %d\n", lowest_y);
				if (e->remonte == 0)
				{
					e->ferme = 1;
					e->fuite = 0;
					break ;
				}
			}*/
			/*if (seed < e->algo[cpy].valid_x && lowest_y >= e->algo[cpy].valid_y)
			{
				mem = cpy;
				seed = e->algo[cpy].valid_x;
				lowest_y = e->algo[cpy].valid_y;
				if (lowest_y == 0)
				{
					dprintf(2, "YAY\n");
					e->ferme = 1;
				}
			}*/
		/*}
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
}*/


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
				if ((i + e->piece_y <= e->map_y && j + e->piece_x <= e->map_x) && put_piece(e, i, j, 0))
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
	if (REACHED == 0)
		analyse_algo(e);
	algo(e);
	//affich_possib(e);
	usleep(500000);
	//sleep(3);
	return (0);
}


