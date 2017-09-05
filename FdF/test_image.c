/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 01:00:13 by snedir            #+#    #+#             */
/*   Updated: 2017/09/05 21:51:29 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math.h"

/*
void		set_struct(void)
{
	t_fdf	*fdf;

	if (fdf = (t_fdf*)malloc(sizeof(t_fdf)))
		return (NULL);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, x, y, "titre");
	IMG_PTR = mlx_new_image(MLX, x, y);
	IMG = mlx_get_data_addr(IMG, &BPP, &SL, &END);
}*/

//char		**line
//


/*
void parser()
{
	faire 2 open (preparsing : ->analyse validite fichier (type .fdf));
	-> regarder si un espace separe les digit (ft_is_digit);
	-> premiere ligne en etalon ignorer le + fill le -;
}*/

int size_num(int nb)
{
	int i;

	i = 0;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int count_spaces(char *line)
{
	int i;
	int b;

	i = 0;
	b = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] == ' ')
			b++;
		i++;
	}
	return (b);
}

void	fill_tab(char *line, t_map **map, int line_number, int *j)
{
	int i;
	int nb;
	int triche;
	int x;

	i = 0;
	nb = 0;
	triche = 0;
	x = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (ft_isdigit(line[i]))
		{
			nb = ft_atoi(line + i);
			(*map)[*j].x = x;
			(*map)[*j].y = line_number;
			(*map)[*j].z = nb;
			triche = size_num(nb);
			i += triche;
			*j += 1;
			x++;
		}
		i++;
	}
}

int	first_line(char *line)
{
	int i;
	int nb;
	int ret;
	int triche;

	i = 0;
	nb = 0;
	ret = 0;
	triche = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if ((nb = ft_atoi(line + i)) > 9)
		{
			triche = size_num(nb);
			ret += abs(1 - triche);
			i += triche;
		}
		i++;
	}
	return (i - ret - count_spaces(line));
}

int	check_line(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (!ft_isdigit(line[i]) && line[i] != ' ' && line[i] != '\n' && line[i] != '\0')
			return (-1);
		i++;
	}
	return (1);
}

int check_file_type(char *line)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '.')
		{
			if (ft_strcmp(line + i, ".fdf") == 0)
				return (1);
		}
	}
	return (-1);
}

int pre_parser(char *av)
{
	int fd;
	char *line;
	int	nb_line;
	unsigned int size;
	
	fd = open(av, O_RDONLY);
	nb_line = 0;
	size = 0;
	
	if (check_file_type(av) != 1)
		return (-1);
	while (get_next_line(fd, &line))
	{
		if (size == 0)
		{
			size = first_line(line);
			if (size == 0)
			{
				free(line);
				close(fd);
				return (-1);
			}
		}
		if (check_line(line) != 1)
		{
			free(line);
			close(fd);
			return (-1);
		}
		free(line);
		nb_line++;
	}
	close(fd);
	printf("size = %d || nb_line = %d\n", size, nb_line);
	return (size * nb_line);
}

t_map *parser(char *av)
{
	int size_array;
	int fd;
	char *line;
	int line_nb;
	t_map *tab;
	int j;

	line_nb = 0;
	j = 0;
	line = NULL;
	size_array = pre_parser(av);
	if (size_array == -1)
		return (NULL);
	if (!(tab = (t_map*)malloc(sizeof(t_map) * size_array)))
		return (NULL);
	fd = open(av, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		fill_tab(line, &tab, line_nb, &j);
		//printf("j = %d\n", j);
		free(line);
		line_nb++;
	}
	close(fd);
	return (tab);
}


void bresenham(int xi, int yi, int yf, int xf, void *mlx, void *win)
{
	int dx, dy, i, xinc, yinc, cumul, x, y;
	x = xi;
	y = yi;
	dx = xf - xi;
	dy = yf - yi;
	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	mlx_pixel_put(mlx, win, x, y, 0xffffff);
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
void straight_line(int xi, int yi, int yf, int xf, void *mlx, void *win)
{
	x = xi;
	y = 
*/




int			main(int argc, char **argv)
{
	//t_fdf *fdf = set_struct();

	//fill_image(img_str, sl, bpp, 600);
	//mlx_put_image_to_window(mlx, win, img_ptr, 0, 0);

	/*void *mlx;
	void *win;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 200, 200, "troll");
	int xi = 100, yi = 50, xf = 44, yf = 144;
	ligne(xi, yi, yf, xf, mlx, win);
	mlx_loop(mlx);*/
	t_map *parse = parser(argv[1]);
	int i = 0;
	while (i < 70)
	{
		printf("map.x = %d | map.z = %d | map.y %d\n", parse[i].x, parse[i].z, parse[i].y);
		i++;
	}
}
