/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 03:42:35 by snedir            #+#    #+#             */
/*   Updated: 2017/11/07 05:47:51 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../gnl/libft/get_next_line.h"

# define REACHED e->reached
# define CLOSED e->closed
# define LOW_CLOSED e->low_closed
# define SIDE_CLOSED e->side_closed

typedef struct	s_algo
{
	int			valid_x;
	int			valid_y;
	int			nearest_enemy;
	int			near_enemy;
}				t_algo;

typedef struct	s_env
{
	char		**map;
	char		*piece;
	char		player_piece;
	char		enemy_piece;
	int			nb_possib;
	t_algo		algo[10000];
	int			piece_x;
	int			piece_y;
	int			map_y;
	int			map_x;
	int			size_piece;
	int			iter_piece;
	int			iter_map;
	int			check_piece;
	int			check_map;
	int			opti;
	int			fuite;
	int			ferme;
	int			remonte;
	int			reached;
	int			input;
	int			closed;
	int			low_closed;
	int			side_closed;
	int			cheat;
}				t_env;

char			**create_map(t_env *e);
void			fill_map(t_env *e);
int				check_space(t_env *e, char *line);
int				check_if_piece(char *line);
void			print_map(t_env *e);
int				enable_check_piece(t_env *e);
int				reset_params(t_env *e, int flag);
int				try_piece(t_env *e);
int				put_piece(t_env *e, int i, int j, int anchor);
void			norme_map_piece(t_env *e, char *str, int *size, int flag);
int				get_player_number(t_env *e, char *line);
int				get_size_map(t_env *e, char *line);
int				get_size_piece(t_env *e, char *line);
int				parse_map(t_env *e, char *line);
int				get_piece(t_env *e, char *line);
#endif
