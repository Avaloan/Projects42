/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 02:04:46 by snedir            #+#    #+#             */
/*   Updated: 2017/09/26 06:40:35 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void assign_img(t_fdf *e, int i, int j)
{
	int pos;

	pos = (i * e->sl) + (j * e->sl);
	e->img[pos] = 125;
	e->img[pos + 1] = 6;
	e->img[pos + 2] = 50;
	e->img[pos + 3] = 0;
}

void breizh_1(t_draw infos, int xi, int yi, t_fdf *e)
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
		assign_img(e, x, y);
		//mlx_pixel_put(e->mlx, e->win, x, y, 0xffffff);
		i++;
	}
}

void breizh_2(t_draw infos, int xi, int yi, t_fdf *e)
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
		assign_img(e, x, y);
		i++;
	}
}

void bresenham(int xi, int yi, int yf, int xf, t_fdf *e)
{
	int x;
	int	y;
	t_draw infos;

	x = xi;
	y = yi;
	infos.dx = xf  - xi;
	infos.dy = yf  - yi;
	infos.xinc = (infos.dx > 0) ? 1 : -1;
	infos.yinc = (infos.dy > 0) ? 1 : -1;
	infos.dx = abs(infos.dx);
	infos.dy = abs(infos.dy);
	//mlx_pixel_put(e->mlx, e->win, x, y, 0xffffff);
	assign_img(e, x, y);
	if (infos.dx > infos.dy)
		breizh_1(infos, xi, yi, e);
	else
		breizh_2(infos, xi, yi, e);
}

void render(t_fdf *e, t_map **parse)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < e->size_y - 1)
	{
		while (j < e->jspc - 1)
		{
			bresenham(parse[i][j].iso_x, parse[i][j].iso_y, parse[i][j + 1].iso_y, parse[i][j + 1].iso_x, e);
			bresenham(parse[i][j].iso_x, parse[i][j].iso_y, parse[i + 1][j].iso_y, parse[i + 1][j].iso_x, e);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
}

