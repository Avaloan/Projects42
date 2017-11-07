/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash_norme.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 04:26:35 by snedir            #+#    #+#             */
/*   Updated: 2017/11/07 05:48:38 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		enable_check_piece(t_env *e)
{
	if (e->piece_x && e->piece_y)
	{
		e->check_piece = 1;
		return (1);
	}
	return (0);
}

int		reset_params(t_env *e, int flag)
{
	if (e->iter_piece == e->size_piece - 1 && flag == 1)
	{
		try_piece(e);
		e->size_piece = 0;
		e->iter_piece = 0;
		e->check_piece = 0;
		e->piece_x = 0;
		e->piece_y = 0;
		e->check_map = 0;
		ft_strdel(&e->piece);
		return (1);
	}
	if (e->iter_map == e->map_y && flag == 0)
	{
		e->iter_map = 0;
		e->check_map = 2;
		return (1);
	}
	return (0);
}

int		put_piece(t_env *e, int y, int x, int anchor)
{
	int	i;
	int	j;
	int	ip;

	i = -1;
	j = -1;
	ip = 0;
	while (++i < e->piece_y)
	{
		while (++j < e->piece_x)
		{
			if (e->piece[ip] == '*' && e->map[y + i][x + j] == e->enemy_piece)
				return (0);
			if (e->piece[ip] == '*' && e->map[y + i][x + j] == e->player_piece)
				anchor++;
			(ip < e->size_piece - 1) ? ip++ : ip + 0;
		}
		(ip < e->size_piece - 1) ? ip++ : ip + 0;
		j = -1;
	}
	if (anchor == 1)
		return (1);
	return (0);
}

void	norme_map_piece(t_env *e, char *str, int *size, int flag)
{
	if (flag == 0)
	{
		if (e->piece_y)
			e->piece_x = ft_atoi(str);
		else
			e->piece_y = ft_atoi(str);
		ft_strdel(&str);
		*size = 0;
	}
	else
	{
		if (e->map_y)
			e->map_x = ft_atoi(str);
		else
			e->map_y = ft_atoi(str);
		ft_strdel(&str);
		*size = 0;
	}
}
