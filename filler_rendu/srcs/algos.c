/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 01:32:29 by snedir            #+#    #+#             */
/*   Updated: 2017/11/07 05:19:46 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		abs(int a)
{
	return (a > 0 ? a : -a);
}

void	clean_algo(t_env *e)
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

void	output(t_env *e)
{
	ft_putnbr(e->algo[e->input].valid_y);
	write(1, " ", 1);
	ft_putnbr(e->algo[e->input].valid_x);
	write(1, "\n", 1);
	clean_algo(e);
}

void	reach_enemy(t_env *e, int cpy, int *near)
{
	if (*near == -1)
		*near = e->algo[cpy].nearest_enemy;
	if (*near == 1)
	{
		e->input = cpy;
		REACHED = 1;
		return ;
	}
	if (*near >= e->algo[cpy].nearest_enemy)
	{
		e->input = cpy;
		*near = e->algo[cpy].nearest_enemy;
	}
}

void	close_highest_side(t_env *e, int cpy)
{
	if (e->algo[cpy].valid_y == 0)
	{
		e->input = cpy;
		CLOSED = 1;
		return ;
	}
	e->input = 0;
}

void	close_lowest_side(t_env *e, int cpy, int *lowest)
{
	if (*lowest == -1)
		*lowest = e->algo[cpy].valid_y;
	if (*lowest == e->map_y - 1 && e->algo[cpy].valid_x == 0)
	{
		e->input = cpy;
		LOW_CLOSED = 1;
		return ;
	}
	if (*lowest <= e->algo[cpy].valid_y)
	{
		e->input = cpy;
		*lowest = e->algo[cpy].valid_y;
	}
}

void	reach_high_side(t_env *e, int cpy, int *xside)
{
	if (*xside == -1)
		*xside = e->algo[cpy].valid_x;
	/*if (*xside == e->map_x - 1)
	  {
	  e->input = cpy;
	  return ;
	  }*/
	if (*xside >= e->algo[cpy].valid_x)
	{
		*xside = e->algo[cpy].valid_x;
		e->input = cpy;
	}
}

void	algo(t_env *e)
{
	int	cpy;
	int	lowest;
	int	near;
	int	xside;

	cpy = e->nb_possib - 1;
	lowest = -1;
	near = -1;
	xside = -1;
	while (cpy >= 0)
	{
		if (REACHED == 0)
			reach_enemy(e, cpy, &near);
		/*if (CLOSED == 0 && REACHED == 1 && LOW_CLOSED == 1)
		  close_highest_side(e, cpy);*/
		if (LOW_CLOSED == 0 && REACHED == 1)
			close_lowest_side(e, cpy, &lowest);
		if (LOW_CLOSED == 1 && REACHED == 1 && CLOSED == 0)
			reach_high_side(e, cpy, &xside);
		cpy--;
	}
	output(e);
}

void	analyse_map(t_env *e, int pos)
{
	int	i;
	int	j;
	int	dist;

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

void	analyse_algo(t_env *e)
{
	int	i;

	i = 0;
	while (i < e->nb_possib)
	{
		analyse_map(e, i);
		i++;
	}
}

int		try_piece(t_env *e)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < e->map_y)
	{
		while (j < e->map_x)
		{
			if ((i + e->piece_y <= e->map_y && j + e->piece_x <= e->map_x)
					&& put_piece(e, i, j, 0))
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
	return (0);
}
