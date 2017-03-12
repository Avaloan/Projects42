/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:25:26 by snedir            #+#    #+#             */
/*   Updated: 2017/03/12 23:57:57 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/fillit.h"

int			ft_size(int lenght)
{
	int		i;

	i = 1;
	while (i * i < lenght * 4)
		i++;
	return (i);
}

void		format_grid(char **grid, int taille)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (grid[i])
	{
		while (j < taille)
		{
			grid[i][j] = '.';
			j++;
		}
		grid[i][j] = '\0';
		j = 0;
		i++;
	}
}

char		**create_grid(int taille)
{
	char	**grid;
	int		i;

	i = 0;
	grid = (char**)malloc(sizeof(char*) * taille + 1);
	while (i < taille)
	{
		grid[i] = (char*)malloc(sizeof(char) * taille + 1);
		i++;
	}
	grid[i] = 0;
	format_grid(grid, taille);
	return (grid);
}

void		print_grid(char **grid)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (grid[i])
	{
		while (grid[i][j])
		{
			ft_putchar(grid[i][j]);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
	ft_putchar('\n');
}

char		**ft_upgrid(int taille, char **grid, int i)
{
	int		w;

	w = 0;
	while (w < taille - i)
	{
		free(grid[w]);
		w++;
	}
	free(grid);
	grid = create_grid(taille + i);
	return (grid);
}
