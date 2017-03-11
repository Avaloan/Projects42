/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 22:52:04 by snedir            #+#    #+#             */
/*   Updated: 2017/03/11 02:26:12 by snedir           ###   ########.fr       */
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

int		ft_place(t_map *map, int pos, int k, int count)
{
	SIZE = ft_strlen(*GRIDP);
	if (count == 4)
		return (1);
	ft_points(ELEMP, &pos, &k, SIZE);
	if (pos > (SIZE * SIZE) - 1)
		return (0);
	if (EDATA[k] == '\n')
	{
		pos = pos + SIZE - ft_lenline(ELEMP, k);
		return ((pos < SIZE * SIZE) ? (ft_place(map, pos, k + 1, count)) : 0);
	}
	if (EDATA[k] && GRIDP[dv_p(pos, SIZE)][md_p(pos, SIZE)] == '.')
	{
		GRIDP[dv_p(pos, SIZE)][md_p(pos, SIZE)] = EDATA[k];
		if (md_p(pos, SIZE) == SIZE - 1 && (EDATA[k + 1] != '\n'))
		{
			GRIDP[dv_p(pos, SIZE)][md_p(pos, SIZE)] = '.';
			return (0);
		}
		if (ft_place(map, pos + 1, k + 1, count + 1))
			return (1);
	}
	if (GRIDP[dv_p(pos, SIZE)][md_p(pos, SIZE)] == PIECE)
		GRIDP[dv_p(pos, SIZE)][md_p(pos, SIZE)] = '.';
	return (0);
}

int		ft_rabbit_hole(t_map *map, int *pos)
{
	int k;
	int	size;
	int	ret;

	k = 0;
	ret = 0;
	size = ft_strlen(*GRIDP);
	while (GRIDP[dv_p(*pos, size)] != 0 && *pos < (size * size))
	{
		if (GRIDP[dv_p(*pos, size)][md_p(*pos, size)] == '.')
		{
			if ((ret = ft_place(map, *pos, k, 0)))
				return (1);
		}
		*pos += 1;
	}
	return (0);
}

int		ft_grid(t_map *map, int count, int nbpieces)
{
	int	pos;

	pos = 0;
	while (ELEMP && count < nbpieces)
	{
		if (ft_rabbit_hole(map, &pos))
		{
			count++;
			ELEMP = ELEMP->prev;
			pos = 0;
		}
		else
		{
			count--;
			if (count < 0)
				return (0);
			ELEMP = ELEMP->next;
			pos = ft_searchletter(GRIDP, PIECE) + 1;
			ft_removepoints(GRIDP, PIECE);
		}
	}
	if (count == nbpieces)
		return (1);
	return (0);
}
