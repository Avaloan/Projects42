/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 22:52:04 by snedir            #+#    #+#             */
/*   Updated: 2017/03/11 00:52:17 by snedir           ###   ########.fr       */
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

int		ft_place(char **grid, t_tetr *piece, int pos, int k, int count)
{
	int SIZE;

	SIZE = ft_strlen(*grid);
	//printf("taille %d\n", SIZE);
	if (count == 4)
		return (1);
	ft_points(piece, &pos, &k, SIZE);
	if (pos > (SIZE * SIZE) - 1)
		return (0);
	if (piece->data[k] == '\n')
	{
		pos = pos + SIZE - ft_lenline(piece, k);
		if (pos < SIZE * SIZE)
		{
			/*printf("i = %d\n", cmp->i);
			ui = ft_place(grid, piece, pos, f1(cmp));
			printf("i = %d\n", cmp->i);*/
			return (ft_place(grid, piece, pos, k + 1, count));
			//return (ui);
		}
		return (0);
	}
	if (piece->data[k] && grid[dv_p(pos, SIZE)][md_p(pos, SIZE)] == '.')
	{
		//print_grid(grid);
		grid[dv_p(pos, SIZE)][md_p(pos, SIZE)] = piece->data[k];
		if (md_p(pos, SIZE) == SIZE - 1 && (piece->data[k + 1] != '\n'))
		{
			grid[dv_p(pos, SIZE)][md_p(pos, SIZE)] = '.';
			return (0);
		}
		if (ft_place(grid, piece, pos + 1, k + 1, count + 1))
			return (1);

	}
	if (grid[dv_p(pos, SIZE)][md_p(pos, SIZE)] == piece->piece)
		grid[dv_p(pos, SIZE)][md_p(pos, SIZE)] = '.';
	return (0);
}

int		ft_rabbit_hole(char **grid, t_tetr *piece, int *pos)
{
	int k;
	int	size;
	int	ret;

	k =  0;
	ret = 0;
	size = ft_strlen(*grid);
	while (grid[dv_p(*pos, size)] != 0 && *pos < (size * size))
	{
		if (grid[dv_p(*pos, size)][md_p(*pos, size)] == '.')
		{
			if ((ret = ft_place(grid, piece, *pos, k, 0)))
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
