/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:40:08 by snedir            #+#    #+#             */
/*   Updated: 2017/03/11 01:55:40 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "fillit.h"

int			count_points(t_tetr *piece, int k)
{
	int		i;

	i = 0;
	while (piece->data[k] && piece->data[k] != '\n')
	{
		k--;
		i++;
	}
	return (i);
}

char		*modify_piece(char *piece)
{
	int		size;
	int		i;
	char	*str;
	int		j;

	i = 0;
	size = 0;
	j = 0;
	while (piece[i])
	{
		if (piece[i] == '\n' || piece[i] == '#' || piece[i] == '.')
			size++;
		i++;
	}
	str = (char*)malloc(sizeof(char) * size + 1);
	i = 0;
	while (piece[i])
	{
		if (piece[i] == '\n' || piece[i] == '#' || piece[i] == '.')
		{
			str[j] = piece[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

t_tetr		*read_and_copy(char *argv, t_head *sentinel, t_tetr *elem, t_iter *var)
{
	int		fd;
	int		ret;
	char	buf[21];
	char	*str;
	char	*str2;
	char	c;

	c = '\0';
	if ((fd = open(argv, O_RDONLY)) != -1)
	{
		while ((ret = read(fd, buf, 21)))
		{
			buf[ret] = '\0';
			if (ft_checksquare(buf) == 1 && ft_checkpiece(buf) == 1)
			{
				str = ft_checkemptyline(buf, var);
				str2 = modify_piece(str);
				free(str);
				elem = add_node(elem, str2, sentinel);
				elem->piece = (sentinel->lenght + 64);
				c = buf[20];
				ft_strclr(buf);
			}
			else
			{
				ft_putstr("error\n");
				return (NULL);
			}
		}
	}
	if (c != '\0')
	{
		ft_putstr("error\n");
		return (NULL);
	}
	close(fd);
	return (sentinel->first_element);
}

void		hashtag_to_alpha(t_tetr *elem)
{
	int		i;

	i = 0;
	while (elem)
	{
		while (elem->data[i])
		{
			if (elem->data[i] == '#')
				elem->data[i] = elem->piece;
			i++;
		}
		i = 0;
		elem = elem->prev;
	}
}

int			main(int argc, char **argv)
{
	(void)argc;
	t_map	map;
	t_tetr	*elem;
	t_head	sentinel;
//	char	**grid;
	int		i;
	t_iter	var;

	elem = NULL;
	ELEM = elem;
	i = 0;
	if ((ELEM = read_and_copy(argv[1], &sentinel, ELEM, &var)))
	{
		GRID = create_grid(ft_size(sentinel.lenght));
		hashtag_to_alpha(ELEM);
		while (ft_grid(&map, 0, sentinel.lenght) == 0)
		{
			i++;
			GRID = ft_upgrid((ft_size(sentinel.lenght)), GRID, i);
		}
		print_grid(GRID);
	}
	return (0);
}
