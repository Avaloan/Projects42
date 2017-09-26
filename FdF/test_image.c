/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 01:00:13 by snedir            #+#    #+#             */
/*   Updated: 2017/09/26 06:44:56 by snedir           ###   ########.fr       */
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

void determinate_tile(t_fdf *elem)
{
	if (elem->total_size < 100)
	{
		elem->tile_x = 40;
		elem->tile_y = 20;
	}
	else if (elem->total_size < 500)
	{
		elem->tile_x = 30;
		elem->tile_y = 15;
	}
	else if (elem->total_size < 1000)
	{
		elem->tile_x = 20;
		elem->tile_y = 10;
	}
	else if (elem->total_size < 2000)
	{
		elem->tile_x = 13;
		elem->tile_y = 7;
	}
	else if (elem->total_size < 4000)
	{
		elem->tile_x = 10;
		elem->tile_y = 5;
	}
	else if (elem->total_size < 10000)
	{
		elem->tile_x = 8;
		elem->tile_y = 4;
	}
	else if (elem->total_size < 14000)
	{
		elem->tile_x = 6;
		elem->tile_y = 3;
	}
	else
	{
		elem->tile_x = 2;
		elem->tile_y = 1;
	}
	elem->win_x = (elem->size_y + elem->jspc) * elem->tile_x;
	elem->win_y = (elem->size_y + elem->jspc) * elem->tile_y;
}

void	iso_mod(t_fdf *e, t_map **parse)
{
	int i;
	int j;

	i = 0;
	j = 0;
	determinate_tile(e);
	while (i < e->size_y)
	{
		while (j < e->jspc)
		{
			parse[i][j].iso_x = (i + j) * e->tile_x + e->offset_x;
			parse[i][j].iso_y = ((i - j) * e->tile_y + (e->win_y / 2 + e->win_y / 5) \
					- parse[i][j].z * e->tile_y / 2) + e->offset_y;
			j++;
		}
		j = 0;
		i++;
	}
}

t_fdf *init()
{
	t_fdf *elem;

	elem = (t_fdf*)malloc(sizeof(t_fdf));
	elem->mlx = NULL;
	elem->win = NULL;
	elem->img_ptr = NULL;
	elem->img = NULL;
	elem->sl = 0;
	elem->bpp = 0;
	elem->end = 0;
	elem->zoom = 0;
	elem->jspc = 0;
	elem->size_x = 0;
	elem->size_y = 0;
	elem->total_size = 0;
	elem->tile_x = 0;
	elem->tile_y = 0;
	elem->z_relative = 0;
	elem->offset_x = 0;
	elem->offset_y = 0;
	elem->win_x = 0;
	elem->win_y = 0;
	elem->opt = 0;
	return (elem);
}

int			main(int argc, char **argv)
{
	t_fdf *e;
	e = init();
	e->mlx = mlx_init();

	if (argc != 2)
		return (-1);
	t_map **parse = parser(argv[1], e);
	if (parse == NULL)
		return (-1);
	//iso_mod(e, parse);
	//e->win = mlx_new_window(e->mlx, e->win_x, e->win_y + 100, "fdf");
	//e->img_ptr = mlx_new_image(e->mlx, e->win_x, e->win_y);
	//e->img = mlx_get_data_addr(e->img_ptr, &e->bpp, &e->sl, &e->end);
	
	//render(e, parse);
	mlx_loop(e->mlx);
	return (0);
}
