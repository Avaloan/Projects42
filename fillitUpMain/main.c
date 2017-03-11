/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:40:08 by snedir            #+#    #+#             */
/*   Updated: 2017/03/11 06:39:48 by snedir           ###   ########.fr       */
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

	i = -1;
	size = 0;
	j = 0;
	while (piece[++i])
		if (piece[i] == '\n' || piece[i] == '#' || piece[i] == '.')
			size++;
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

t_tetr		*read_and_copy(char *argv, t_head *sent, t_tetr *elem, t_iter *var)
{
	t_buf	stock;
	char	c;

	c = 'a';
	if ((FD = open(argv, O_RDONLY)) != -1)
	{
		while ((RET = read(FD, BUF, 21)))
		{
			BUF[RET] = '\0';
			if (ft_checksquare(BUF) == 1 && ft_checkpiece(BUF) == 1)
			{
				ft_final(&STR, &STR2, BUF, var);
				elem = add_node(elem, STR2, sent);
				ft_multi(&c, BUF, sent, elem);
				ft_strclr(BUF);
			}
			else
				return (NULL);
		}
		if (c == '\0')
			return (sent->first_element);
	}
	close(FD);
	return (NULL);
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
	t_map	map;
	t_tetr	*elem;
	t_head	sentinel;
	int		i;
	t_iter	var;

	elem = NULL;
	ELEM = elem;
	i = 0;
	if (ft_argc(argc))
		return (0);
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
	else
		ft_putstr("error\n");
	return (0);
}
