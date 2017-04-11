/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 14:29:40 by snedir            #+#    #+#             */
/*   Updated: 2017/04/11 04:27:19 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_buf				*new(int fd)
{
	t_buf			*control;

	MALLNULL((control = (t_buf*)malloc(sizeof(t_buf))));
	NEXT = NULL;
	PREV = NULL;
	STOCK = NULL;
	FD = fd;
	return (control);
}

t_buf				*add_node(t_buf *elem, int fd)
{
	t_buf			*control;

	while (elem)
	{
		if (elem->fd == fd)
			return (elem);
		if (elem->next == NULL)
		{
			while (elem)
			{
				if (elem->fd == fd)
					return (elem);
				if (elem->prev == NULL)
					break ;
				elem = elem->prev;
			}
			break ;
		}
		elem = elem->next;
	}
	control = new(fd);
	NEXT = elem;
	elem->prev = control;
	return (control);
}

int					god_like(char *buf, t_buf *control, char **line, int way)
{
	char			*tmp;
	char			*tmp2;

	if ((tmp = ft_strchr(buf, '\n')) && (way == 1))
	{
		*tmp = '\0';
		*line = ft_strjoin(STOCK, buf);
		free(STOCK);
		STOCK = ft_strdup(tmp + 1);
		return (1);
	}
	else if ((tmp = ft_strchr(STOCK, '\n')) && (way == 2))
	{
		tmp2 = ft_strdup(tmp + 1);
		*tmp = '\0';
		*line = ft_strdup(STOCK);
		free(STOCK);
		STOCK = ft_strdup(tmp2);
		free(tmp2);
		return (1);
	}
	return (0);
}

int					read_mem(int fd, char *buf, t_buf *control, char **line)
{
	int				ret;

	ret = 0;
	if (fd < 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (god_like(buf, control, line, 1))
			return (1);
		STOCK = ft_strjoinf(STOCK, buf);
	}
	if (ret == -1)
		return (-1);
	if (STOCK)
	{
		if (*STOCK == '\0')
			return (0);
		*line = ft_strdup(STOCK);
		free(STOCK);
		STOCK = NULL;
		return (1);
	}
	return (0);
}

int					get_next_line(int const fd, char **line)
{
	static t_buf	*control = NULL;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	if (!line)
		return (-1);
	if (control && fd != FD)
		control = add_node(control, fd);
	if (!control)
		control = new(fd);
	if (STOCK)
		if (god_like(buf, control, line, 2))
			return (1);
	ret = read_mem(fd, buf, control, line);
	if (ret == 1)
		return (1);
	else if (ret == -1)
		return (-1);
	else
		return (0);
}
