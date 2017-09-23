/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 01:00:13 by snedir            #+#    #+#             */
/*   Updated: 2017/09/23 05:11:39 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math.h"

t_map **double_array(t_fdf *e)
{	
	t_map **tab;
	int i;

	i = 0;
	tab = NULL;
	if (!(tab = (t_map**)malloc(sizeof(t_map*) * e->size_y)))
		return (NULL);
	while (i < e->size_y)
	{
		tab[i] = (t_map*)malloc(sizeof(t_map) * e->jspc);
		i++;
	}
	return (tab);
}

void assignass(t_draw *infos, int ddx, int ddf)
{
	infos->dx = ddx;
	infos->dy = ddf;
	infos->xinc = (infos->dx > 0) ? 1 : -1;
	infos->yinc = (infos->dy > 0) ? 1 : -1;
	infos->dx = abs(infos->dx);
	infos->dy = abs(infos->dy);
}


void bresenham(int xi, int yi, int yf, int xf, void *mlx, void *win)
{
	t_draw infos;
	int x;
	int y;
	
	x = xi;
	y = yi;
	assignass(&infos, xf - xi, yf - yi);
	mlx_pixel_put(mlx, win, x, y, 0xffffff);
	if (infos.dx > infos.dy)
		breizh_1(infos, mlx, win, xi, yi);
	else
		breizh_1(infos, mlx, win, xi, yi);
}
/*
void	iso_mod(t_fdf *e, t_map **parse)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (i < e->size_y)
	{
		while (j < e->jspc)
		{
			parse[i][j].iso_x = (i + j) * half_tile_size_x;
			parse[i][j].iso_y = ((i - j) * half_tile_size_y) + half_map_size)) - parse[i][j].z * relative;
			j++;
		}
		j = 0;
		i++;
	}
}
*/

t_fdf *init()
{
	t_fdf *elem;

	elem = (t_fdf*)malloc(sizeof(t_fdf));
	elem->mlx = NULL;
	elem->win = NULL;
	elem->img_ptr = NULL;
	elem->img = NULL;
	elem->sl = NULL;
	elem->bpp = 0;
	elem->end = 0;
	elem->zoom = 0;
	elem->jspc = 0;
	elem->size_x = 0;
	elem->size_y = 0;
	elem->total_size = 0;
	return (elem);
}

int			main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	t_fdf *e;
	e = init();
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 1000, 1000, "fdf");
	if (argc != 2)
		return (-1);
	t_map **parse = parser(argv[1], e);
	if (parse == NULL)
		return (-1);
	while (i < e->size_y)
	{
		while (j < e->jspc)
		{
			parse[i][j].iso_x = (i + j) * 7;
			parse[i][j].iso_y = (((i - j) * 3) + 500) + parse[i][j].z * 4;
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	while (i < e->size_y - 1)
	{
		while (j < e->jspc - 1)
		{
			bresenham(parse[i][j].iso_x, parse[i][j].iso_y, parse[i][j + 1].iso_y, parse[i][j + 1].iso_x, e->mlx, e->win);
			bresenham(parse[i][j].iso_x, parse[i][j].iso_y, parse[i + 1][j].iso_y, parse[i + 1][j].iso_x, e->mlx, e->win);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_loop(e->mlx);
	return (0);
}
