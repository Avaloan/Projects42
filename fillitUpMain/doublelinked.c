/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublelinked.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 09:57:30 by snedir            #+#    #+#             */
/*   Updated: 2017/03/06 20:40:51 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"

typedef struct v_list
{
	char *data;
	char piece;
	struct v_list *prev;
	struct v_list *next;
}				x_list;

typedef struct head
{
	struct v_list *first_element;
	int lenght;
}head;

int		ft_checkcount(int count, int start);
void	ft_checkemptycolumn(char **str, int i);
char	*ft_checkemptyline (char *str);
int		ft_checkpiece(char *str);
int		ft_checksquare(char *str);
int		ft_lenline(x_list *piece, int i);
int		put_piece(char **grid, char *piece, int i, int j, int count, int place);
int		ft_control(char **grid, x_list *piece, int count, int k, int position);
char	**create_grid(int taille);
void	format_grid(char **grid, int taille);
void	ft_removepoints(char **grid, int count);
int		ft_fillgrid(char **grid, x_list *piece, int taille, int count, int position, int nbpieces);
int		ft_rabbit_hole(char **grid, x_list *piece, int pos);
int		ft_grid(char **grid, x_list *piece, int count, int nbpieces);

x_list *new_node(char *data)
{
	x_list *elem;

	elem = NULL;
	elem = (x_list*)malloc(sizeof(x_list));
	elem->data = data;
	elem->next = NULL;
	elem->prev = NULL;

	return (elem);
}

x_list *add_node(x_list *elem, char *data, head *master)
{
	x_list *new;

	if (elem)
	{
		new = new_node(data);
		new->next = elem;
		elem->prev = new;
		master->lenght += 1;
	}
	else
	{
		new = new_node(data);
		master->first_element = new;
		master->lenght += 1;
	}
	return (new);
}

int count_points(x_list *piece, int k)
{
	int i;

	i = 0;
	while (piece->data[k] && piece->data[k] != '\n')
	{
		k--;
		i++;
	}
	printf("i = %d\n", i);
	return (i);
}

void print_list(x_list *elem)
{
	while (elem)
	{
		ft_putstr(elem->data);
		ft_putstr("\n");
		elem = elem->prev;
	}
}

char *modify_piece(char *piece)
{
	int size;
	int i;
	char *str;
	int j;

	i = 0;
	size = 0;
	j = 0;
	while (piece[i])
	{
		if (piece[i] == '\n' || piece[i] == '#' || piece[i] == '.')
			size++;
		//ft_putchar(piece[i]);
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

x_list *read_and_copy(char *argv, head *sentinel, x_list *elem)
{
	int fd;
	int ret;
	char buf[21];
	char *str;
	char *str2;
	char c = 'a';

	if((fd = open(argv, O_RDONLY)) != -1)
	{
		while ((ret = read(fd, buf, 21)))
		{
			//printf("%s\n", buf);
			//printf("checksquare = %d | checkpiece = %d\n",ft_checksquare(buf), ft_checkpiece(buf));
			if (ft_checksquare(buf) == 1 && ft_checkpiece(buf) == 1)
			{
				str = ft_checkemptyline(buf);
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

void hashtag_to_alpha(x_list *elem)
{
	int i = 0;
	while (elem)
	{
		while(elem->data[i])
		{
			if (elem->data[i] == '#')
				elem->data[i] = elem->piece;
			i++;
		}
		i = 0;
		elem = elem->prev;
	}
}
char **ft_upgrid(int taille, char **grid, int i)
{
	int w;
	int j;

	w = 0;
	j = 0;
	//printf("le bon i = %d\n", i);
	while (w < taille - i)
	{
		free(grid[w]);
		w++;
	}
	free(grid);
	grid = create_grid(taille + i);
	return (grid);
}


char **create_grid(int taille)
{
	char **grid;
	int i;

	i = 0;
	grid = (char**)malloc(sizeof(char*) * taille + 1);
	while (i < taille)
	{
		grid[i] = (char*)malloc(sizeof(char) * taille + 1);
		i++;
	}
	grid[i] = 0;
	format_grid(grid, taille);
	return (grid);
}

void	format_grid(char **grid, int taille)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (grid[i])
	{
		while (j < taille)
		{
			grid[i][j] = '.';
			j++;
		}
		grid[i][j] = '\0';
		j = 0;
		i++;
	}
}

void print_grid(char **grid)
{
	int i = 0;
	int j = 0;
	while (grid[i])
	{
		while (grid[i][j])
		{
			ft_putchar(grid[i][j]);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
	ft_putchar('\n');
}

int ft_size(int lenght)
{
	int i;

	i = 1;
	while (i * i < lenght * 4)
		i++;
	//printf("taille de la grille = %d\n", i);
	return (i);
}
/*
int truc(char **grid, x_list *elem, int count, int taille, int nbpieces)
{
	int i = 0;
	int res = 0;
	while (elem && i < taille * taille)
	{
		//printf("coucou\n");
		//if (i < ft_size(sentinel.lenght) * ft_size(sentinel.lenght))
		res = ft_control(grid, elem, 0, 0, i);
		printf("res = %d\n", res);
		printf("position = %d\n", i);
		if (res == 0)
			i++;
		else
		{
			elem = elem->prev;
			count++;
		}
	}
	if (count == nbpieces)
		return (1);
	return (0);
}
*/
int main(int argc, char **argv)
{
	(void)argc;
	x_list *elem;
	head sentinel;
	char **grid;
	elem = NULL;
	int i = 0;
	//int res = 0;
	if ((elem = read_and_copy(argv[1], &sentinel, elem)))
	{
		//print_list(elem);
		grid = create_grid(ft_size(sentinel.lenght));
		//print_grid(grid);
		hashtag_to_alpha(elem);
		
		/*while (res == 0)
		  {
		  res = truc(grid, elem, 0, ft_size(sentinel.lenght + i), sentinel.lenght);
		  if (res == 1)
		  {
		  print_grid(grid);
		  return (1);
		  }
		  i++;
		  grid = ft_upgrid(ft_size(sentinel.lenght), grid, i);
		  }*/
		/*while (truc(grid, elem, 0, ft_size(sentinel.lenght + i), sentinel.lenght) == 0)
		  {
		  i++;
		  grid = ft_upgrid(ft_size(sentinel.lenght + i), grid, i);
		  }*/
/*
		while (elem && i < ft_size(sentinel.lenght))
		{
			//printf("coucou\n");
			if (i < ft_size(sentinel.lenght) * ft_size(sentinel.lenght))
				res = ft_control(grid, elem, 0, 0, i);
			//printf("res = %d\n", res);
			if (res == 0)
				i++;
			else
				elem = elem->prev;
		}*/
		//ft_fillgrid(grid, elem, ft_size(sentinel.lenght) + i, 0, 0, sentinel.lenght);
		/*printf("salut\n");
		  grid = ft_upgrid(ft_size(sentinel.lenght), grid);
		  if (ft_fillgrid(grid, elem, ft_size(sentinel.lenght) + i, 0, 0, sentinel.lenght))
		  {
		  print_grid(grid);
		  return (1);
		  }
		  }*/
		//print_grid(grid);
		/*int k = 0;
		while (elem)
		{
			printf("\n");
			printf("%s\n", elem->data);
			while (elem->data[k])
			{
				while (elem->data[k] != '\n' && elem->data[k])
					k++;
				printf("ft_lenline : %d\n", ft_lenline(elem, k));
				k++;
			}
			k = 0;
			elem = elem->prev;
		}*/
		while (ft_grid(grid, elem, 0, sentinel.lenght) == 0)
		{
			i++;
			grid = ft_upgrid((ft_size(sentinel.lenght)), grid, i);
		}
		print_grid(grid);
}
	return (0);
}
