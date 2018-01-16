/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 00:30:19 by snedir            #+#    #+#             */
/*   Updated: 2018/01/16 05:38:57 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# include "../gnl/libft/get_next_line.h"
# include <stdlib.h>
# define LEM_IN_H

/*
 * FLAGS
 */

# define NB_ANTS e->nb_ants
# define PENDING_START e->pending_start
# define PENDING_END e->pending_end
# define FLAG_ROOM e->flag_room
# define ERROR_FLAG -2
# define STOP_FLAG -3
# define ERROR_MALLOC -4

/*
 * GESTION LISTE
 */

# define E_ROOM e->e_room
# define E_LINE e->e_line

/*
 * GESTION FILE
 */

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
	//t_path			*path_tab;
	int				parent;
}					t_tab;

typedef struct		s_tabpath
{
	t_path_m		*path_master;
}					t_tabpath;

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
}					t_env;

/*
 * LIST FUNCTIONS
 */

t_room				*new_room(char *line, t_env *e);
void				add_elem_room(char *line, t_env *e);
t_line				*new_line(char *line);
void				add_elem_line(t_env *e, char *line);
void				add_elem_path(t_env *e, int i, int stock);
void				add_elem_node(t_env *e, int stock);

/*
 * QUEUE FUNCTIONS
 */

t_file				*new_queue_elem(int id);
void				add_queue_elem(t_env *e, int id);
void				dequeue(t_env *e);
void				dequeue_tmp(t_env *e);

int					check_hashtag(char *line, t_env *e);
void				exit_error(t_env *e);

int					get_nb_ants(char *line, t_env *e);
int					get_room(char *line, t_env *e);
void				print_room(t_env *e);

















#endif
