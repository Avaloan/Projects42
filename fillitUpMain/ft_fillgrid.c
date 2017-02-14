/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillgrid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 07:56:08 by gquerre           #+#    #+#             */
/*   Updated: 2017/02/07 06:10:10 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char **ft_upgrid(int taille, char **grid);

typedef struct v_list
{
	char *data;
	char piece;
	struct v_list *prev;
	struct v_list *next;
}x_list;

typedef struct head
{
	struct v_list *first_element;
	int lenght;
}head;

void print_grid(char **grid);

int ft_lenline(x_list *piece, int i)
{

	int len;
	int k;
	int tmp;

	len  = 0;
	k = 0;
	while (len < i)
	{
		if (piece->data[len] == '\n')
			k++;
		len++;
	}
	if (k != 0)
	{
		tmp = len;
		len--;
		while (piece->data[len] != '\n')
			len--;
		len = tmp - len - 1;
	}
	return (len);
}
/*
int ft_control(char **grid, x_list *piece, int count, int k, int position)
{
	int taille;
	int i;
	int j;
	
	taille = ft_strlen(*grid);
	i = position / taille;
	j = position % taille;
	if (count == 4)
		return (1);
	if (piece->data[k] && piece->data[k] == '.')
	{
		if ((k != 0 && k != 1) || (k == 0 && j == 0) || (k == 1 && j == 1))
			return (ft_control(grid, piece, count, k + 1, position + 1));
		return (ft_control(grid, piece, count, k + 1, position));
	}
	if ((piece->data[k] && piece->data[k] == '\n') && (position + taille - ft_lenline(piece, k) < taille * taille))
	{
		return ((ft_control(grid, piece, count, k + 1, (position + taille - ft_lenline(piece, k)))));
	}
	if (piece->data[k] && piece->data[k] != '\n' && piece->data[k] != '.' && grid[i][j] == '.')
	{	
		print_grid(grid);
		grid[i][j] = piece->data[k];
		if (j == taille - 1 && piece->data[k + 1] == piece->piece)
			return (0);
		return (ft_control(grid, piece, count + 1, k + 1, position + 1));
	}
	return (0);
}

int ft_control(char **grid, x_list *piece, int count, int k, int position)
{
	int taille;
	int i;
	int j;

	//printf("salut ma poule\n");
	//print_grid(grid);
	//printf("\n");
	//printf("count = %d\n", count);
	taille = ft_strlen(*grid);
	//printf("%c\n", piece->data[k]);
	i = position / taille;
	j = position % taille;
	//printf("grid[%d][%d]\n", i, j);
	if (count == 4)
		return (1);
	if (grid[i] && grid[i][j] != '.' && grid[i][j] != '\n')
	{
		while (grid[i] && grid[i][j] != '.')
		{
			while (grid[i][j] != '.' && grid[i][j])
			{
				printf("i = %d | j = %d\n", i, j);
				position++;
				j++;
			}
			if (grid[i][j] != '.')
			{
				j = 0;
				i++;
			}
		}
	}
	while (piece->data[k] && piece->data[k] == '.')
	{
		if ((k != 0 && k != 1) || (k == 0 && j == 0) || (k == 1 && j == 1))
		{
			k++; 
			if (j < taille)
				j++;
			else
			{
				j = 0;
				i++;
			}
		}
		k++;
		
	}
	if ((piece->data[k] && piece->data[k] == '\n') && (position + taille - ft_lenline(piece, k) < taille * taille))
	{
		printf("position avant calcul = %d | taille = %d | ft_lenline = %d\n", position, taille, ft_lenline(piece, k));
		printf("position apres calcul = %d\n", position);
				i = position / taille;
		j = position % taille;
		printf("grid[%d][%d] = %c\n", i, j, grid[i][j]);
		printf("piece = %c\n", piece->data[k]);
		return ((ft_control(grid, piece, count, k + 1, (position + taille - ft_lenline(piece, k)))));
	}
	if (piece->data[k] && piece->data[k] == '.')
	{
		if ((k != 0 && k != 1) || (k == 0 && j == 0) || (k == 1 && j == 1))
			return (ft_control(grid, piece, count, k + 1, position + 1));
		return (ft_control(grid, piece, count, k + 1, position));
	}
	if (piece->data[k] && piece->data[k] != '\n' && piece->data[k] != '.' && grid[i][j] == '.')
	{	
		print_grid(grid);
		printf("\n");
		printf("debug3\n");
		grid[i][j] = piece->data[k];
		print_grid(grid);
		printf("\n");
		printf("j est egal %d | taille = %d\n", j, taille);
		if (j == taille - 1 && piece->data[k + 1] == piece->piece)
		{
			printf("dur dur\n");
			grid[i][j] = '.';
			return (0);
		}
		if (ft_control(grid, piece, count + 1, k + 1, position + 1))
		{
			printf("debug4\n");
			return (1);
		}
	}
	printf("counturu = %c\n", piece->data[k]);
	//printf("\n");
	printf("debug5\n");
	//if (grid[i][j] == piece->piece)
		grid[i][j] = '.';
	return (0);
}*/






int ft_searchletter(char **grid, char lettre)
{
	int position;
	int i;
	int j;

	i = 0;
	j = 0;
	position = 0;
	while (grid[i])
	{
		while (grid[i][j] && grid[i][j] != lettre)
		{
			position++;
			j++;
		}
		if (grid[i][j] == lettre)
			return (position);
		j = 0;
		i++;
	}
	return (0);
}

void ft_removepoints(char **grid, char lettre)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (grid[i])
	{
		while (grid[i][j])
		{
			if (grid[i][j] == lettre)
				grid[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
}
/*
int ft_fillgrid(char **grid, x_list *piece, int taille, int count, int position, int nbpieces)
{
	int i;
	int j;

	i = position / taille;
	j = position % taille;
	if (count == nbpieces)
		return (1);
	if (grid[i] && grid[i][j] && grid[i][j] != '.')
		return (ft_fillgrid(grid, piece, taille, count, position + 1, nbpieces));
	if (grid[i] == 0)
	{
		if (count == 0)
			return (ft_fillgrid(ft_upgrid(taille, grid), piece, taille + 1, 0, 0, nbpieces));
			//return (0);
		position = ft_searchletter(grid, count - 1) + 1;
	//	printf("position = {%i}\n", position);
		ft_removepoints(grid, count - 1);
		return (ft_fillgrid(grid, piece->next, taille, count - 1, position, nbpieces));
	}
	if (grid[i][j] && grid[i][j] == '.')
	{
		if (ft_control(grid, piece, 0, 0, position))
		{
			count++;
			return (ft_fillgrid(grid, piece->prev, taille, count, 0, nbpieces));
		}
		ft_removepoints(grid, count);
		return (ft_fillgrid(grid, piece, taille, count, position + 1, nbpieces));
	}
	return (0);
}
*/

