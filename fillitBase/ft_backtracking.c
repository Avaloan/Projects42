/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 22:52:04 by snedir            #+#    #+#             */
/*   Updated: 2017/02/09 08:29:15 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void print_grid(char **grid);

int ft_searchletter(char **grid, char lettre);

int ft_removepoints(char **grid, char lettre);


int dv_p(int pos, int taille)
{
	return (pos / taille);
}

int md_p(int pos, int taille)
{
	return (pos % taille);
}

int ft_place(char **grid, x_list *piece, int pos, int k, int count)
{
	int size;
	
	size = ft_strlen(*grid);
	if (count == 4)
		return (1);
	while (piece->data[k] && piece->data[k] == '.')
	{
		//ft_putchar('h');
		//ft_putchar('\n');
		k++;
		pos++;
	}
	if (pos > (size * size) - 1)
		return (0);
	if (piece->data[k] == '\n')
	{
		pos = pos + size - ft_lenline(piece, k);
		if ((pos < size * size) && grid[dv_p(pos, size)][md_p(pos, size)] == '.')
			return (ft_place(grid, piece, pos, k + 1, count));
		return (0);
	}
	if (piece->data[k] && grid[dv_p(pos, size)][md_p(pos, size)] == '.')
	{
		grid[dv_p(pos, size)][md_p(pos, size)] = piece->data[k];
		//print_grid(grid);
		if (md_p(pos, size) == size - 1 && (piece->data[k + 1] != '\n'))
		{
			grid[dv_p(pos, size)][md_p(pos, size)] = '.';
			return (0);
		}
		if (ft_place(grid, piece, pos + 1, k + 1, count + 1))
			return (1);
	}
	if (grid[dv_p(pos, size)][md_p(pos, size)] == piece->piece)
		grid[dv_p(pos, size)][md_p(pos, size)] = '.';
	return (0);
}


int ft_rabbit_hole(char **grid, x_list *piece, int *pos)
{
	int k;
	int size;
	int ret = 0;

	k = 0;
	size = ft_strlen(*grid);
	//printf("salut\n");
	while (grid[dv_p(*pos, size)] != 0 && *pos < (size * size))
	{
		while (grid[dv_p(*pos, size)][md_p(*pos, size)] != '.' && ((k == 1 || k == 0) && (piece->data[k] == '.')))
		{
			//ft_putchar('k');
			//ft_putchar('\n');
			k++;
		}
		if (grid[dv_p(*pos, size)][md_p(*pos, size)] == '.')
		{
			if ((ret = ft_place(grid, piece, *pos, k, 0)))
				return (1);
		}
		*pos += 1;
	}
	return (0);
}

int ft_grid(char **grid, x_list *piece, int count, int nbpieces)
{
	int pos;
	int ret;

	pos = 0;
	ret = 0;
	//int h = 0;
	while (piece && count < nbpieces)
	{
		//printf("nbpieces = %d, count = %d\n", nbpieces, count);
		if ((ret = ft_rabbit_hole(grid, piece, &pos)))
		{
			//printf("countiii = %d  ret = %d\n", count, ret);
			count++;
			piece = piece->prev;
			//printf("%s\n", piece->data);
			pos = 0;
		}
		else
		{
			count--;
			//printf("countu = %d\n", count);
			if (count < 0)
				return (0);
			piece = piece->next;
			pos = ft_searchletter(grid, piece->piece) + 1;
			//printf("la possssss %d\n", pos);
			//ft_putstr("lala\n");
			ft_removepoints(grid, piece->piece);
		}
	}
	if (count == nbpieces)
		return (1);
	return (0);
}
