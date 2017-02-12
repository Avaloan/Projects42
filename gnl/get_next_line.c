/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 14:29:40 by snedir            #+#    #+#             */
/*   Updated: 2017/02/12 16:56:40 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdio.h>
#define BUFF_SIZE 32
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"


typedef struct s_buf
{
	size_t len_buf;
	int iter;
	int *pos_array;
	int len_array;
}				t_buf;

t_buf *new(char *buf)
{
	t_buf *elem;
	int j;
	int i;
	
	j = 0;
	i = 0;
	if (!(elem = (t_buf*)malloc(sizeof(*elem))))
		return (0);
	elem->len_buf = ft_strlen(buf);
	elem->iter = -1;
	while (buf[++elem->iter])
		if (buf[elem->iter] == '\n')
			j++;
	if (!(elem->pos_array = (int*)malloc(sizeof(int) * j)))
		return (0);
	elem->len_array = j;
	elem->iter = -1;
	while (buf[++elem->iter])
		if (buf[elem->iter] == '\n')
		{
			elem->pos_array[i] = elem->iter;
			i++;
		}
	return (elem);
}
/*
int parse_buf(char *buf)
{
	int i;
	int nb_nl;
	size_t len;
	int pos_nl;

	i = 0;
	nb_nl = 0;
	len = strlen(buf);
	while (buf[i])&& buf[i] != '\n')
	{
		if (buf[i] == '\n')
		{
			nb_nl++;
			pos_nl = i;
		}
		i++;
	}
	if (nb_nl == 1 && i == len)
		ft_strcpy(buf, stockage);
	if (
			}
*/








/*
int get_next_line(const int fd, char **line)
{
	int		ret;
	char	buf[BUFF_SIZE];

	while ((ret = read(fd, buf, BUFF_SIZE)))
		buf[ret] = '\0';
}*/

int main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY);
	char buf[4];
	int ret = 0;
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	t_buf *elem = new(buf);
	int i = 0;
	printf("taille buf = {%zu}\n", elem->len_buf);
	printf("taille tableau = {%d}\n", elem->len_array);
	while (i < elem->len_array)
	{
		printf("position NL : {%d}\n", (elem->pos_array)[i]);
		i++;
	}
}
