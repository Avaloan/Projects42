/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 00:18:00 by snedir            #+#    #+#             */
/*   Updated: 2017/03/25 14:58:52 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# define BUFF_SIZE 600
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"
//# define BUF control->buf
# define NEXT control->next
# define STOCK control->stock
# define FD control->fd
# define PENDING control->pending

/*
** STRUCTS
*/

typedef struct		s_buf
{
	//char			buf[BUFF_SIZE + 1];
	struct s_buf	*next;
	char			*stock;
	int				fd;
	int				pending;
}					t_buf;

/*
** PROTOTYPES
*/

/*t_buf	*new(char *buf);
t_list	*new_node(char *data);
t_list	*add_node(t_list, char *data, head *master);
void	print_list(t_list *elem);*/
int	get_next_line(int fd, char **line);
#endif
