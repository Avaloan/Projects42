/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 06:16:15 by snedir            #+#    #+#             */
/*   Updated: 2017/10/19 01:20:33 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

char		**create_map(t_env *e)
{
	char	**ptr;
	int		i;

	ptr = (char**)ft_memalloc(sizeof(char*) * (e->map_y + 1));
	i = 0;
	while (i < e->map_y)
	{
		ptr[i] = (char*)ft_memalloc(sizeof(char) * (e->map_x + 1));
		i++;
	}
	return (ptr);
}

void		fill_map(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < e->map_y)
	{
		while (j < e->map_x)
		{
			e->map[i][j] = '.';
			j++;
		}
		e->map[i][j] = '\0';
		j = 0;
		i++;
	}
	e->map[i] = NULL;
}


int			check_space(t_env *e, char *line)
{
	int		i;

	i = -1;
	while (++i < 4)
		if (line[i] != ' ')
			return (-1);
	e->check_map = 1;
	return (1);
}


int			check_if_piece(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '.' && line[i] != '*' && line[i] != '\0')
			return (-1);
		i++;
	}
	return (1);
}

void		print_map(t_env *e)
{
	int		i = 0;
	while (i < e->map_y)
	{
		printf("%s\n", e->map[i]);
		i++;
	}
	printf("\n");
}
