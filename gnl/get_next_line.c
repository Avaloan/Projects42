/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 14:29:40 by snedir            #+#    #+#             */
/*   Updated: 2017/03/17 04:29:45 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*void		**ultrafcntl(char *buf, char **line, t_buf *control)
  {
  int		i;
  int		j;
  int		less;
  char	*sub;

  i = 0;
  j = 0;
  less = 0;
  while (buf[i])
  {
  if (buf[i] == '\n')
  {
  if (j > 0)
  add_node(buf, FD); 
  sub = ft_strsub(buf, i - less, i - less);
  if (PENDING)
 *line = ft_strjoin(STOCK, sub); //attention au free
 PENDING = 0;
 if (!less)
 less += i;
 free(sub);
 j++;
 }
 i++;
 }
 if (!j)
 STOCK = ft_strdup(buf);*/ /*ici cela peut etre un join faire attention
							 a bien free puis faire strjoin(STOCK, BUF)
							 */
/*if (RET != 0)
  PENDING = 1;
  }


  int				fonctionRead()
  {
//la fonction read si il n'ya pas de '\n' relancer l'ultrafcntl recursif
int i = -1;
int ret = 0;
ret = read(fd, buf, BUFF_SIZE);
buf[ret] = '\0';
static t_buf *control = add_node;
ultrafcntl(des bonnes choses);
if (PENDING == 1)
ultrafcntl(des bonnes choses)//completer le maillon

}

static t_buf		*new(char *buf, int fd, int ret)
{
static t_buf	*control;

if (!(control = (t_buf*)malloc(sizeof(t_buf))))
return (NULL);
NEXT = NULL;
STOCK = NULL;
FD = fd;
PENDING = 0;
RET = ret;
}
*/
//int get_next_line(int fd, char **line)
//{
/*char buf[BUFF_SIZE + 1];
  static t_buf *control;
  int ret;

  while (buf[ret] != '\n'
  control = add_node;
  ultrafcntl(control);*/
//}

/*
   int main(int argc, char **argv)
   {
   int fd = open(argv[1], O_RDONLY);
   printf("fd = %d\n", fd);
   char buf[BUFF_SIZE + 1];
   int ret = 0;
   ret = read(fd, buf, BUFF_SIZE);
   printf("fd after read %d ret = %d\n", fd, ret);
   buf[ret] = '\0';
   printf("%s", buf);
   */
//int ret = 0;
//ret = read(fd, buf2, BUFF_SIZE);
//t_buf *elem = new(buf);
//int i = 0;
//char **grid = ft_strsplit(buf, '\n');
//ft_free_2d(grid, ft_strlen(*grid));
//ft_print_grid(grid);
/*printf("taille buf = {%zu}\n", elem->len_buf);
  printf("taille tableau = {%d}\n", elem->len_array);
  while (i < elem->len_array)
  {
  printf("position NL : {%d}\n", (elem->pos_array)[i]);
  printf("i = %d\n", i);
  i++;
  }
  }*/
#include "get_next_line.h"
/
static int check_stock(t_buf *control, char **line)
{
	char *tmp;
	if ((tmp = ft_strchr(STOCK, '\n')))
	{
		tmp = '\0';
		*line = ft_strdup(STOCK);
		STOCK = ft_strdup(tmp + 1);
		tmp = NULL;
		return (1);
	}
	return (0);
}


static int check_read(char *buffer, char **stock, char **line)
{
	char*tmp;
	//implementer la liste chainee
	if ((tmp = ft_strchr(buffer, '\n')))
	{
		*tmp = '\0';
		*line = ft_strjoin(*stock, buffer);
		free(*stock);
		*stock = ft_strdup(tmp + 1);
		tmp = NULL;
		free(buffer);
		return (1);
	}
	return (0);
}

static int chec_read(char *buf, t_buf *control, char **line)
{
	char *tmp;

	if ((tmp = ft_strchr(buf, '\n')))
	{
		*tmp = '\0';
		*line = ft_strjoin(STOCK, buf);
		free(STOCK);
		STOCK = ft_strdup(tmp + 1);
		tmp = NULL;
		return (1);
	}
}



int get_next_line(int const fd, char **line)
{
	static t_buf *control = NULL;
	char buffer[BUFF_SIZE + 1];
	int ret;

	//checker ici si le fd est different du dernier appel
	/*si le fd est different faire un autre maillon ou si il appartient a
	 un maillon en particulier afin de reprendre la lecture*/
	//donc parcours de liste pour rechercher le fd
	add_node;
	if (stock) //voir PENDING
		if (check_stock(&stock, line))
			return (1);
	//buffer = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (check_read(buffer, &stock, line))
			return (1);
		stock = ft_strjoin(stock, buffer);
	}
	free(buffer);
	buffer = NULL;
	if (ret == -1)
		return (-1);
	if (stock == NULL)
		return (0);
	*line = ft_strdup(stock);
	free(stock); //bien delete le stock
	stock = NULL;
	return (1);
}

