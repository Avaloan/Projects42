/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 19:56:47 by snedir            #+#    #+#             */
/*   Updated: 2017/03/12 23:43:10 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define ELEM map.node
# define GRID map.grid
# define SIZE map->size
# define ELEMP map->node
# define GRIDP map->grid
# define PIECE ELEMP->piece
# define EDATA ELEMP->data
# define STR stock.str
# define STR2 stock.str2
# define BUF stock.buf
# define FD stock.fd
# define C stock.c
# define RET stock.ret
# define SELEM stock.elem
# define PELEM stock.elem
# include <fcntl.h>

typedef struct		s_tetr
{
	char			*data;
	char			piece;
	struct s_tetr	*prev;
	struct s_tetr	*next;
}					t_tetr;

typedef struct		s_head
{
	t_tetr			*first_element;
	int				lenght;
}					t_head;

typedef struct		s_map
{
	t_tetr			*node;
	char			**grid;
	int				size;
}					t_map;

typedef struct		s_iter
{
	int				start;
	int				i;
	int				count;
	int				end;
}					t_iter;

typedef struct		s_buf
{
	char			buf[21];
	char			c;
	int				fd;
	int				ret;
	char			*str;
	char			*str2;
	t_tetr			*elem;
}					t_buf;

char				*modify_piece(char *piece);
void				ft_final(char **str, char **str2, char *buf, t_iter *var);
int					ft_put(char c);
int					ft_lenline(t_tetr *piece, int i);
int					ft_searchletter(char **grid, char lettre);
void				ft_removepoints(char **grid, char lettre);
int					dv_p(int pos, int taille);
int					md_p(int pos, int taille);
int					ft_place(t_map *map, int pos, int k, int count);
int					ft_rabbithole(char **grid, t_tetr *piece, int *pos);
int					ft_grid(t_map *map, int count, int nbpieces);
int					ft_checkcount(int count, int start);
void				ft_checkemptycolumn(char **str, int i);
char				*ft_checkemptyline (char *str, t_iter *var);
int					ft_checkpiece(char *str);
int					ft_checksquare(char *str);
int					ft_lenline(t_tetr *piece, int i);
int					put_piece(char **grid, char *piece, int i, int j,
					int count, int place);
char				**create_grid(int taille);
void				format_grid(char **grid, int taille);
int					ft_size(int lenght);
void				ft_multi(char *c, char *buf, t_head *sent, t_tetr *elem);
void				format_grid(char **grid, int taille);
void				print_grid(char **grid);
char				**ft_upgrid(int taille, char **grid, int i);
t_tetr				*new_node(char *data);
t_tetr				*add_node(t_tetr *elem, char *data, t_head *master);
int					count_points(t_tetr *piece, int k);
t_tetr				*read_and_copy(char *argv, t_head *sent, t_tetr *elem,
					t_iter *var);
void				hashtag_to_alpha(t_tetr *elem);
void				ft_points(t_tetr *piece, int *pos, int *k, int size);
void				ft_checkemptycolumn(char **str, int i);
int					ft_checkcount(int count, int start);
char				*ft_readlines(char *str);
int					ft_checklinksreverse(char *str);
int					ft_checklinks(char *str);
int					ft_argc(int argc);

#endif
