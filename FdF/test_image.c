/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 01:00:13 by snedir            #+#    #+#             */
/*   Updated: 2017/09/07 06:26:54 by snedir           ###   ########.fr       */
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

void	fill_void(t_map **map, int x, int line_number, t_fdf *e)
{
	while (x < e->jspc)
	{
		map[line_number][x].x = x;
		map[line_number][x].y = line_number;
		map[line_number][x].z = 0;
		x++;
	}
}


void	fill_tab(char *line, t_map **map, int line_number, t_fdf *e)
{
	int i;
	int nb;
	int triche;
	int x;

	i = 0;
	nb = 0;
	triche = 0;
	x = 0;
	//printf("jspc %d\n", e->jspc);
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (ft_isdigit(line[i]))
		{
			nb = ft_atoi(line + i);
			map[line_number][x].x = x;
			map[line_number][x].y = line_number;
			map[line_number][x].z = nb;
			triche = size_num(nb);
			x++;
			i += triche;
		}
		i++;
	}
	if (x < e->jspc)
		fill_void(map, x, line_number, e);
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
	//printf("i = = %d\n", i);
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

int pre_parser(char *av, t_fdf *e)
{
	int fd;
	char *line;
	int	nb_line;
	unsigned int size;
	
	fd = open(av, O_RDONLY);
	nb_line = 0;
	size = 0;
	e->size_x = 0;
	e->jspc = 0;
	if (check_file_type(av) != 1)
		return (-1);
	while (get_next_line(fd, &line))
	{
		size = first_line(line);
			if (e->jspc == 0)
				e->jspc = size;
			e->size_x += size;
			if (size == 0)
			{
				free(line);
				close(fd);
				return (-1);
			}
		if (check_line(line) != 1)
		{
			free(line);
			close(fd);
		//	printf("coucou\n");
			return (-1);
		}
		free(line);
		nb_line++;
	}
	close(fd);
	e->size_y = nb_line;
	//printf("size = %d || nb_line = %d\n", e->jspc, e->jspc * nb_line);
	return (1);
}

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

t_map **parser(char *av, t_fdf *e)
{
	int size_array;
	int fd;
	char *line;
	int line_nb;
	t_map **tab;
	int j;

	line_nb = 0;
	j = 0;
	line = NULL;
	size_array = pre_parser(av, e);
	if (size_array == -1)
		return (NULL);
	tab = double_array(e);
	fd = open(av, O_RDONLY);
	while (get_next_line2(fd, &line))
	{
		printf("j = %s\n", line);
		fill_tab(line, tab, line_nb, e);
		free(line);
		line_nb++;
	}
	close(fd);
	return (tab);
}

void bresenham(int xi, int yi, int yf, int xf, void *mlx, void *win)
{
	printf("xi %d -> xf %d | yi %d -> yf %d\n", xi, xf, yi, yf);
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
		for (i = 1 ; i <= dx + 100 ; i++)
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
		for (i = 1 ; i <= dy + 100 ; i++)
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

int			main(int argc, char **argv)
{
	//t_fdf *fdf = set_struct();

	//fill_image(img_str, sl, bpp, 600);
	//mlx_put_image_to_window(mlx, win, img_ptr, 0, 0);

	/*void *mlx;
	void *win;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 2000, 2000, "troll");
	*/t_fdf e;
	t_map **parse = parser(argv[1], &e);
	if (parse == NULL)
		return (-1);
	int i = 0;
	int j = 0;
	//bresenham(0, 0, 0, 100, mlx, win);
	/*		printf("x %d y %d z %d j %d\n", parse[0][0].x, parse[0][0].y, parse[0][0].z, j);
			printf("x %d y %d z %d j %d\n", parse[0][1].x, parse[0][1].y, parse[0][1].z, j);
			printf("x %d y %d z %d j %d\n", parse[0][2].x, parse[0][2].y, parse[0][3].z, j);
			printf("x %d y %d z %d j %d\n", parse[1][0].x, parse[1][0].y, parse[1][0].z, j);
			printf("x %d y %d z %d j %d\n", parse[1][1].x, parse[1][1].y, parse[1][1].z, j);
			printf("x %d y %d z %d j %d\n", parse[1][2].x, parse[1][2].y, parse[1][2].z, j);
			printf("x %d y %d z %d j %d\n", parse[2][0].x, parse[2][0].y, parse[2][0].z, j);
			printf("x %d y %d z %d j %d\n", parse[2][1].x, parse[2][1].y, parse[2][1].z, j);
			printf("x %d y %d z %d j %d\n", parse[2][2].x, parse[2][2].y, parse[2][2].z, j);
	*/while (i < e.size_y)
	{
		while (j < e.jspc)
		{
			//printf("j = %d\n", e.jspc);
			if (parse[i][j + 1].z > 9)
				printf("%d ", parse[i][j].z);
			else if (parse[i][j].z > 9 && parse[i][j + 1].z < 9)
				printf("%d  ", parse[i][j].z);
			//else if (parse[i][j].z < 9 && parse[i][j + 1].z < 9)
			else
				printf("%d  ", parse[i][j].z);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
	/*mlx_loop(mlx);*/
}
