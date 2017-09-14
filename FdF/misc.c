/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 01:09:42 by snedir            #+#    #+#             */
/*   Updated: 2017/09/13 01:23:23 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		map[line_number][x].iso_y = 0;
		map[line_number][x].iso_x = 0;
		x++;
	}
}

int size_line(char *line)
{
	int i = 0;

	while (line[i] != '\0' && line[i] != '\n')
		i++;
	return (i);
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

