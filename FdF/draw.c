/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 02:04:46 by snedir            #+#    #+#             */
/*   Updated: 2017/09/23 05:19:06 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void breizh_1(t_draw infos, void *mlx, void *win, int xi, int yi)
{
	int cumul;
	int x;
	int y;
	int i;

	x = xi;
	y = yi;
	cumul = infos.dx / 2;
	i = 1;
	while (i <= infos.dx)
	{
		x += infos.xinc;
		cumul += infos.dy;
		if (cumul >= infos.dx)
		{
			cumul -= infos.dx;
			y += infos.yinc;
		}
		mlx_pixel_put(mlx, win, x, y, 0xffffff);
		i++;
	}
}

void breizh_2(t_draw infos, void *mlx, void *win, int xi, int yi)
{
	int cumul;
	int x;
	int y;
	int i;

	x = xi;
	y = yi;
	cumul = infos.dy / 2;
	i = 1;
	while (i <= infos.dy)
	{
		y += infos.yinc;
		cumul += infos.dx;
		if (cumul >= infos.dy)
		{
			cumul -= infos.dy;
			x += infos.xinc;
		}
		mlx_pixel_put(mlx, win, x, y, 0xffffff);
		i++;
	}
}
/*
void assign(t_draw *infos, int i, int j, t_map **parse)
{
	infos->xi = parse[i][j].iso_x;
	infos->yi = parse[i][j].iso_y;
	infos->xf = parse[i][j + 1].iso_x;
	infos->yf = parse[i][j + 1].iso_y;
	infos->dx = infos->xf - infos->xi;
	infos->dy = infos->yf - infos->yi;
	infos->xinc = (infos->dx > 0) ? 1 : -1;
	infos->yinc = (infos->dy > 0) ? 1 : -1;
	infos->dx = abs(infos->dx);
	infos->dy = abs(infos->dy);
}

void assign2(t_draw *infos, int i, int j, t_map **parse)
{
	infos->xi = parse[i][j].iso_x;
	infos->yi = parse[i][j].iso_y;
	infos->xf = parse[i + 1][j].iso_x;
	infos->yf = parse[i + 1][j].iso_y;
	infos->dx = infos->xf - infos->xi;
	infos->dy = infos->yf - infos->yi;
	infos->xinc = (infos->dx > 0) ? 1 : -1;
	infos->yinc = (infos->dy > 0) ? 1 : -1;
	infos->dx = abs(infos->dx);
	infos->dy = abs(infos->dy);
	printf("lol\n");
}

void bresenham2(t_map **parse, int i, int j, int use, void *mlx, void *win)
{
	t_draw infos;

	if (use == 10)
		assign(&infos, i, j, parse);
	else
		assign2(&infos, i, j, parse);
	mlx_pixel_put(mlx, win, infos.xi, infos.yi, 0xffffff);
	if (infos.dx > infos.dy)
		breizh_1(infos, mlx, win);
	else
		breizh_2(infos, mlx, win);
}*/
