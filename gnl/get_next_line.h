/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 00:18:00 by snedir            #+#    #+#             */
/*   Updated: 2017/08/23 01:45:29 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# define BUFF_SIZE 10000
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"
# define NEXT control->next
# define STOCK control->stock
# define FD control->fd
# define PREV control->prev
# define MALLNULL(x) if (!x) return (NULL);
# define MALLCHECK(x) if (!x) return (-1);

typedef struct		s_buf
{
	struct s_buf	*next;
	struct s_buf	*prev;
	char			*stock;
	int				fd;
}					t_buf;

int					get_next_line(int fd, char **line);
#endif
