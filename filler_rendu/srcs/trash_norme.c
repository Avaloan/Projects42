/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash_norme.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 04:26:35 by snedir            #+#    #+#             */
/*   Updated: 2017/10/13 06:15:05 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int enable_check_piece(t_env *e)
{
	if (e->piece_x && e->piece_y)
	{
		e->check_piece = 1;
		return (1);
	}
	return (0);
}

int reset_params(t_env *e, int flag)
{
	if (e->iter_piece == e->size_piece -1 && flag == 1)
	{		
		e->size_piece = 0;
		e->iter_piece = 0;
		e->check_piece = 0;
		e->piece_x = 0;
		e->piece_y = 0;
		//printf("%s\n\n", e->piece);
		e->check_map = 0;
		ft_strdel(&e->piece); //ce strdel est necessaire avant la nouvelle ALLOC
		return (1);
	}
	if (e->iter_map == e->map_y && flag == 0)
	{
		e->iter_map = 0;
		e->check_map = 2; //A mieux placer
		//print_map(e);
		return (1);
	}
	return (0);
}
