/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 02:10:29 by snedir            #+#    #+#             */
/*   Updated: 2017/09/23 05:20:32 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_tab(char *line, t_map **map, int line_number, t_fdf *e)
{
	int i;
	int nb;
	int triche;
	int x;
	int size = size_line(line);

	i = 0;
	nb = 0;
	triche = 0;
	x = 0;
	while (i < size)
	{
		if (ft_isdigit(line[i]))
		{
			nb = ft_atoi(line + i);
			map[line_number][x].x = x;
			map[line_number][x].y = line_number;
			map[line_number][x].z = nb;
			map[line_number][x].iso_x = 0;
			map[line_number][x].iso_y = 0;
			triche = size_num(nb);
			x++;
			if (i + triche < size)
				i += triche;
			else
				break;
		}
		if (i > size)
			break ;
		i++;
	}
	if (x < e->jspc)
		fill_void(map, x, line_number, e);
}

int pre_parser(char *av, t_fdf *e)
{
	int fd;
	char *line;
	int	nb_line;
	unsigned int size;
	
	if ((fd = open(av, O_RDONLY)) == -1)
		return (-1);
	nb_line = 0;
	size = 0;
	if (check_file_type(av) != 1)
		return (-1);
	while (get_next_line(fd, &line))
	{
		if (size == 0)
			size = first_line(line);
		if (e->jspc == 0)
				e->jspc = size;
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
			return (-1);
		}
		free(line);
		nb_line++;
	}
	close(fd);
	e->size_y = nb_line;
	return (1);
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
	tab = NULL;
	size_array = pre_parser(av, e);
	if (size_array == -1)
		return (NULL);
	if ((tab = double_array(e)) == NULL)
		return (NULL);
	if ((fd = open(av, O_RDONLY)) == -1)
		return (NULL);
	while (get_next_line2(fd, &line))
	{
		fill_tab(line, tab, line_nb, e);
		free(line);
		line_nb++;
	}
	close(fd);
	return (tab);
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
	int size = size_line(line);
	while (line[i] != '\0' && line[i] != '\n' && i < size)
	{
		if ((nb = ft_atoi(line + i)) > 9)
		{
			triche = size_num(nb);
			ret += abs(1 - triche);
			i += triche;
		}
		i++;
	}
	if (ret > 0)
		ret++;
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


