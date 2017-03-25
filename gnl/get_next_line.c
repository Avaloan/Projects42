/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 14:29:40 by snedir            #+#    #+#             */
/*   Updated: 2017/03/25 15:40:22 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int check_stock(t_buf *control, char **line)
{
	char *tmp;
	char *tmp2;

	if ((tmp = ft_strchr(STOCK, '\n')))
	{
		tmp2 = ft_strdup(tmp + 1);
		//printf("%s", tmp2);
		*tmp = '\0';
		//printf("%s", STOCK);
		*line = ft_strdup(STOCK);
		//printf("%s", STOCK);
		free(STOCK);
		STOCK = NULL;
		STOCK = ft_strdup(tmp2);
		//tmp += 1;
		//printf("%s\n", STOCK);
		tmp = NULL;
		free(tmp2);
		return (1);
	}
	return (0);
}

static int	check_read(char *buf, t_buf *control, char **line)
{
	char			*tmp;

	if ((tmp = ft_strchr(buf, '\n')))
	{
		*tmp = '\0';
		*line = ft_strjoin(STOCK, buf);
		//printf("%s", *line);
		free(STOCK);
		//printf("read %s\n", *line);
		STOCK = NULL;
		STOCK = ft_strdup(tmp + 1);
		//printf("%s", ft_strdup(tmp + 1));
		tmp = NULL;
		return (1);
	}
	return (0);
}

t_buf		*new(int fd)
{

	t_buf	*control;

	if (!(control = (t_buf*)malloc(sizeof(t_buf))))
		return (NULL);
	NEXT = NULL;
	STOCK = NULL;
	FD = fd;
	return (control);
}

int					get_next_line(int const fd, char **line)
{
	static t_buf	*control = NULL;
	char			buf[BUFF_SIZE + 1];
	int				ret = 0;

	if (!control)
		control = new(fd);
	//printf("coucou\n");
	/*if (fd != FD)
	  faire le parcours;*/
	if (STOCK) //voir PENDING
	{
		//printf("1\n");
		if (check_stock(control, line))
			return (1);
	}
	//printf("tamer\n");
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		//printf("ooooo\n");
		buf[ret] = '\0';
		if (check_read(buf, control, line))
			return (1);
		STOCK = ft_strjoin(STOCK, buf);
	}
	if (ret < BUFF_SIZE && !ft_strchr(STOCK, '\n'))
	{
		*line = ft_strdup(STOCK);
		free(STOCK);
		return (0);
	}
	if (ret == -1)
		return (-1);
	if (STOCK == NULL)
		return (0);
	*line = ft_strdup(STOCK);
	free(STOCK); //bien delete le stock
	STOCK = NULL;
	return (1);
}/*
static int proceed(int const fd, char *buff, char *s[fd])
{
	char *tmp;
	char *p;
	int i;

	i = 0;
	while (!(p = ft_strchr(s[fd], '\n')) &&
			(i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[i] = '\0';
		tmp = s[fd];
		s[fd] = ft_strjoin(tmp, buff);
		ft_strdel(&tmp);
	}
	if (i == -1)
		return (-1);
	if (i == 0 && !p)
		return (0);
	return (1);
}*/
