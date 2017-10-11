/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 03:42:35 by snedir            #+#    #+#             */
/*   Updated: 2017/10/11 05:25:39 by snedir           ###   ########.fr       */
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

typedef struct s_env
{
	char **map; //pas sur
	char *piece; //pas sur
	char player_piece;
	char player_last;
	char enemy_piece;
	char enemy_last;
	/*
	 * liste chainee de position possible pour placer les pieces
	 */
	t_lpos *head;
	int piece_x;
	int piece_y;
	int map_y;
	int map_x;
	int size_piece;
	int iter_piece;
	int check_piece;
}			t_env;


#endif
