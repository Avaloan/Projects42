/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 00:30:19 by snedir            #+#    #+#             */
/*   Updated: 2018/03/06 00:32:28 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../gnl/libft/get_next_line.h"
# include "ft_printf.h"
# include <stdio.h>
# include <stdlib.h>

# define NB_ANTS e->nb_ants
# define PENDING_START e->pending_start
# define PENDING_END e->pending_end
# define FLAG_ROOM e->flag_room
# define ERROR_FLAG -2
# define STOP_FLAG -3
# define ERROR_MALLOC -4
# define DA666BEASTXBAMBOULA 666
# define I send_ants->i
# define I2 send_ants->i2
# define ROOM send_ants->room

# define E_ROOM e->e_room
# define E_LINE e->e_line

# define E_FILE e->e_file

typedef struct		s_line
{
	char			*line;
	struct s_line	*next;
}					t_line;

typedef struct		s_room
{
	char			*room_name;
	int				id;
	struct s_room	*next;
}					t_room;

typedef struct		s_send_ants
{
	int				ants;
	int				turn;
	int				total;
	int				i;
	int				i2;
	int				new_ants;
	int				room;
	int				papp;
	int				path_needed;
}					t_send_ants;

typedef struct		s_file
{
	int				id;
	struct s_file	*next;
	struct s_file	*prev;
}					t_file;

typedef struct		s_path
{
	int				node;
	struct s_path	*next;
}					t_path;

typedef struct		s_path_m
{
	struct s_path	*path;
	struct s_path_m	*next_path;
	int				size_path;
	int				selected;
}					t_path_m;

typedef struct		s_tab
{
	int				*tab;
	int				parent;
}					t_tab;

typedef struct		s_tabpath
{
	t_path_m		*path_master;
}					t_tabpath;

typedef struct		s_norme
{
	t_path_m		*tmp_master;
	t_path_m		*stock_free_master;
	t_path			*tmp_path;
	t_path			*stock_free;
	t_path_m		*good_shit;
}					t_norme;

typedef struct		s_ants
{
	int				path;
	int				deep_level;
}					t_ants;

typedef struct		s_env
{
	int				nb_ants;
	int				flag_room;
	int				start;
	int				end;
	int				pending_start;
	int				pending_end;
	int				count;
	t_path_m		*list_path;
	t_tab			*matrix;
	t_file			*e_file;
	int				connection[2];
	int				nb_path;
	t_tabpath		*tab_way;
	t_room			*e_room;
	t_line			*e_line;
	t_path_m		*current;
	int				nb_path_selected;
	int				average_turns;
	int				rustine;
	int				nb_bfs;
	char			**room_tab;
}					t_env;

t_room				*new_room(char *line, t_env *e);
void				add_elem_room(char *line, t_env *e);
t_line				*new_line(char *line);
void				add_elem_line(t_env *e, char *line);
void				add_elem_path(t_env *e, int i, int stock);
void				add_elem_node(t_env *e, int stock);

t_file				*new_queue_elem(int id);
void				add_queue_elem(t_env *e, int id);
void				dequeue(t_env *e);
void				dequeue_tmp(t_env *e);

int					check_hashtag(char *line, t_env *e);
void				exit_error(void);
int					get_infos(char *line, t_env *e);
int					parser(t_env *e);

int					get_nb_ants(char *line, t_env *e);
int					get_room(char *line, t_env *e);
void				print_room(t_env *e);
int					get_pipe(char *line, t_env *e);

void				printfourmi(t_env *e, int ants, int room, int da);
int					g_room(int turnpath, int deep_level, t_env *e);
void				print_line(t_env *e);
void				print_matrix(t_env *e);
void				print_name(t_env *e, int i);
void				print_tab_path(t_env *e);
int					check_valid_room(char *line, t_env *e);
int					get_room_name(char **name, char *line);

int					path_finding(t_env *e);
void				print_path(t_env *e);
void				assign_path_to_tab(t_env *e);
int					select_path(t_env *e);
void				wash_matrix(t_env *e);
int					nb_wrong_path(t_env *e);
void				ft_trabul(t_env *e);
void				s_ants(t_env *e, t_send_ants *s_ants, t_ants *tb_ants);
void				menu_ants(t_env *e);
void				assign_pipe(t_env *e);
void				ft_pukutak(t_send_ants *send_ants, t_ants *tab_ants);
void				modif_new_ants(t_send_ants *send_ants, t_env *e);
#endif
