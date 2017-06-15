/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 02:16:43 by snedir            #+#    #+#             */
/*   Updated: 2017/06/15 01:05:37 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "gnl/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>

# define PLAYER_NB player->player_number
# define PIECE player->piece
# define ENEMY_LAST player->last_enemy_piece
# define INPUT player->input
# define CHECK_P player->check_p
# define SIZE_X player->size_x
# define SIZE_Y player->size_y
# define ITER player->iter_piece

# define X map->x
# define Y map->y
# define Z map->z
# define MAP map->map
# define CHECK map->check

typedef struct s_map
{
	int x;
	int y;
	char **map;
	int z;
	int check;
	/*int size_x;
	int size_y;*/
}			t_map;

typedef struct s_play
{
	int player_number;
	int iter_piece;
	char piece;
	//char **map;
	char **input;
	char last_enemy_piece;
	int check_p;
	int size_x;
	int size_y;
}			t_play;
#endif
