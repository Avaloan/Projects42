/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 00:30:19 by snedir            #+#    #+#             */
/*   Updated: 2017/11/21 05:52:52 by snedir           ###   ########.fr       */
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

typedef struct		s_env
{
	int				nb_ants;
	int				flag_room;
	int				start;
	int				end;
	int				pending_start;
	int				pending_end;
	int				count;
	int				**matrix;
	int				connection[2];
	t_room			*e_room;
	t_line			*e_line;
}					t_env;

/*
 * LIST FUNCTIONS
 */

t_room				*new_room(char *line, t_env *e);
void				add_elem_room(char *line, t_env *e);
t_line				*new_line(char *line);
void				add_elem_line(t_env *e, char *line);

int					check_hashtag(char *line, t_env *e);
void				exit_error(void);

int					get_nb_ants(char *line, t_env *e);
int					get_room(char *line, t_env *e);






















#endif
