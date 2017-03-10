/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 22:52:04 by snedir            #+#    #+#             */
/*   Updated: 2017/03/08 21:43:38 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	ft_points(t_tetr *piece, int *pos, int *k, int size)
{
	while (piece->data[*k] && piece->data[*k] == '.')
	{
		if (*k == 0 || *k == 1)
		{
			if (md_p(*pos, size) == *k)
			{
				*k += 1;
				*pos += 1;
			}
			else
				*k += 1;
		}
		else
		{
			*k += 1;
			*pos += 1;
		}
	}
}

int		ft_place(char **grid, t_tetr *piece, int pos, t_iter *cmp)
{
	cmp->start = ft_strlen(*grid);
	if (cmp->count == 4)
		return (1);
	ft_points(piece, &pos, &cmp->i, SIZE);
	if (pos > (SIZE * SIZE) - 1)
		return (0);
	if (piece->data[cmp->i] == '\n')
	{
		pos = pos + SIZE - ft_lenline(piece, cmp->i);
		if (pos < SIZE * SIZE)
			return (ft_place(grid, piece, pos, f1(cmp)));
		return (0);
	}
	if (piece->data[cmp->i] && grid[dv_p(pos, SIZE)][md_p(pos, SIZE)] == '.')
	{
		grid[dv_p(pos, SIZE)][md_p(pos, SIZE)] = piece->data[cmp->i];
		if (md_p(pos, SIZE) == SIZE - 1 && (piece->data[cmp->i + 1] != '\n'))
		{
			grid[dv_p(pos, SIZE)][md_p(pos, SIZE)] = '.';
			return (0);
		}
		if (ft_place(grid, piece, pos + 1, f3(cmp)))
			return (1);
	}
	if (grid[dv_p(pos, SIZE)][md_p(pos, SIZE)] == piece->piece)
		grid[dv_p(pos, SIZE)][md_p(pos, SIZE)] = '.';
	return (0);
}

int		ft_rabbit_hole(char **grid, t_tetr *piece, int *pos)
{
	t_iter cmp;
	int	size;
	int	ret;

	cmp.count = 0;
	ret = 0;
	cmp.i = 0;
	size = ft_strlen(*grid);
	while (grid[dv_p(*pos, size)] != 0 && *pos < (size * size))
	{
		if (grid[dv_p(*pos, size)][md_p(*pos, size)] == '.')
		{
			if ((ret = ft_place(grid, piece, *pos, &cmp)))
				return (1);
		}
		*pos += 1;
	}
	return (0);
}

int		ft_grid(char **grid, t_tetr *piece, int count, int nbpieces)
{
	int	pos;

	pos = 0;
	while (piece && count < nbpieces)
	{
		if (ft_rabbit_hole(grid, piece, &pos))
		{
			count++;
			piece = piece->prev;
			pos = 0;
		}
		else
		{
			count--;
			if (count < 0)
				return (0);
			piece = piece->next;
			pos = ft_searchletter(grid, piece->piece) + 1;
			ft_removepoints(grid, piece->piece);
		}
	}
	if (count == nbpieces)
		return (1);
	return (0);
}
