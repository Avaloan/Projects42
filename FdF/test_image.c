/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 01:00:13 by snedir            #+#    #+#             */
/*   Updated: 2017/09/14 06:35:31 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math.h"

t_map **double_array(t_fdf *e)
{	
	t_map **tab;
	int i;

	i = 0;
	//printf("%d %d\n", e->jspc, e->size_y);
	if (!(tab = (t_map**)malloc(sizeof(t_map*) * e->jspc)))
		return (NULL);
	while (i < e->size_y)
	{
		//printf("jspc %d\n",i);
		tab[i] = (t_map*)malloc(sizeof(t_map) * e->jspc);
		i++;
	}
	return (tab);
}

/*
void breizh_1(t_map **parse, int i, int j, char *img)
{
}

void BREIZHHHHHHHHH(t_map **parse, int i, int j, ...)
{
*/
/*
cumul dans les fonctions
x et y et i  dans les fonctions
remplacer xi et sa mere avec i et j de la boucle
*/

void breizh_1(t_draw infos, void *mlx, void *win)
{
	int cumul;
	int x;
	int y;
	int i;

	x = infos.xi;
	y = infos.yi;
	cumul = infos.dx / 2;
	i = 1;
	printf("xi = %d | yi = %d | xf = %d | yf = %d | dx = %d | dy = %d\n", infos.xi, infos.yi, infos.xf, infos.yf, infos.dx, infos.dy);
	(void)mlx;
	(void)win;
	while (i <= infos.dx)
	{
		x += infos.xinc;
		cumul += infos.dy;
		if (cumul >= infos.dx)
		{
			cumul -= infos.dx;
			y += infos.yinc;
		}
		i++;
		mlx_pixel_put(mlx, win, x, y, 0xffffff);
	}
}

void breizh_2(t_draw infos, void *mlx, void *win)
{
	int cumul;
	int x;
	int y;
	int i;

	x = infos.xi;
	y = infos.yi;
	cumul = infos.dy / 2;
	i = 1;
	//printf("xi = %d | yi = %d | xf = %d | yf = %d | dx = %d | dy = %d\n", infos.xi, infos.yi, infos.xf, infos.yf, infos.dx, infos.dy);
	(void)mlx;
	(void)win;
	printf("oioi\n");
	while (i <= infos.dy)
	{
		y += infos.xinc;
		cumul += infos.dx;
		if (cumul >= infos.dy)
		{
			cumul -= infos.dy;
			x += infos.yinc;
		}
		i++;
		mlx_pixel_put(mlx, win, x, y, 0xffffff);
	}
}

void assign(t_draw *infos, int i, int j, t_map **parse)
{
	infos->xi = parse[i][j].iso_x;
	infos->yi = parse[i][j].iso_y;
	infos->xf = parse[i][j + 1].iso_x;
	infos->yf = parse[i][j + 1].iso_y;
	infos->dx = abs(infos->xf - infos->xi);
	infos->dy = abs(infos->yf - infos->yi);
	infos->xinc = (infos->dx > 0) ? 1 : -1;
	infos->yinc = (infos->dy > 0) ? 1 : -1;
}

void assign2(t_draw *infos, int i, int j, t_map **parse)
{
	infos->xi = parse[i][j].iso_x;
	infos->yi = parse[i][j].iso_y;
	infos->xf = parse[i + 1][j].iso_x;
	infos->yf = parse[i + 1][j].iso_y;
	infos->dx = abs(infos->xf - infos->xi);
	infos->dy = abs(infos->yf - infos->yi);
	infos->xinc = (infos->dx > 0) ? 1 : -1;
	infos->yinc = (infos->dy > 0) ? 1 : -1;
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
}

void bresenham(int xi, int yi, int yf, int xf, void *mlx, void *win)
{
	int dx, dy, i, xinc, yinc, cumul, x, y;
	x = xi;
	y = yi;
	dx = xf  - xi;
	dy = yf  - yi;
	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	mlx_pixel_put(mlx, win, x, y, 0xffffff);
	printf("xi = %d | yi = %d | xf = %d | yf = %d | dx = %d | dy = %d | x = %d | y = %d\n", xi, yi, xf, yf, dx, dy, x, y);
	if (dx > dy)
	{
		cumul = dx / 2;
		for (i = 1 ; i <= dx ; i++)
		{
			x += xinc;
			cumul += dy;
			if (cumul >= dx)
			{
				cumul -= dx;
				y += yinc;
			}
			mlx_pixel_put(mlx, win, x, y, 0xffffff);
		}
	}
	else
	{
		cumul = dy / 2;
		for (i = 1 ; i <= dy ; i++)
		{
			y += yinc;
			cumul += dx;
			if (cumul >= dy)
			{
				cumul -= dy;
				x += xinc;
			}
			mlx_pixel_put(mlx, win, x, y, 0xffffff);
		}
	}
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
			parse[i][j].iso_y = ((i - j) * half_tile_size_y) + offset)) - parse[i][j].z * relative;
			j++;
		}
		j = 0;
		i++;
	}
}
*/

int			main(int argc, char **argv)
{
	//t_fdf *fdf = set_struct();

	//fill_image(img_str, sl, bpp, 600);
	//mlx_put_image_to_window(mlx, win, img_ptr, 0, 0);

	void *mlx;
	void *win;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1900, 1500, "DEMON");
	if (argc != 2)
		return (-1);
	t_fdf e;
	t_map **parse = parser(argv[1], &e);
	if (parse == NULL)
		return (-1);
	int i = 0;
	int j = 0;
	while (i < e.size_y)
	{
		while (j < e.jspc)
		{
			parse[i][j].iso_x = (i + j) * 30;
			parse[i][j].iso_y = (((i - j) * 15) + 1200) - parse[i][j].z * 2;
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	while (i < e.size_y - 1)
	{
		while (j < e.jspc - 1)
		{
			bresenham(parse[i][j].iso_x, parse[i][j].iso_y, parse[i][j + 1].iso_y, parse[i][j + 1].iso_x, mlx, win);
			//bresenham(parse[i][j].iso_x, parse[i][j].iso_y, parse[i + 1][j].iso_y, parse[i + 1][j].iso_x, mlx, win);
			//bresenham2(parse, i, j, 10, mlx, win);
			//bresenham2(parse, i, j, 0, mlx, win);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_loop(mlx);
}
