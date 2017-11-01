/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 03:42:35 by snedir            #+#    #+#             */
/*   Updated: 2017/11/01 01:12:08 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../gnl/libft/get_next_line.h"



typedef struct s_lpos
{
	int pos_x;
	int pos_y;
	int abs_dist;
	struct s_lpos *next;
}			t_lpos;

typedef struct s_algo
{
	int valid_x;
	int valid_y;
	int nearest_enemy;
	int near_enemy;
}				t_algo;

typedef struct s_env
{
	char **map; //pas sur
	char *piece; //pas sur
	char player_piece;
	char enemy_piece;
	int nb_possib;
	t_algo algo[50000];
	t_lpos *head;
	int carli;
	int piece_x;
	int piece_y;
	int map_y;
	int map_x;
	int size_piece;
	int iter_piece;
	int iter_map;
	int check_piece;
	int check_map;
	int opti;
}			t_env;

char **create_map(t_env *e);
void fill_map(t_env *e);
int check_space(t_env *e, char *line);
int check_if_piece(char *line);
void print_map(t_env *e);
int enable_check_piece(t_env *e);
int reset_params(t_env *e, int flag);
int try_piece(t_env *e);
int put_piece(t_env *e, int i, int j, int anchor);

#endif
