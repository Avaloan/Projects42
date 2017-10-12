/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash_norme.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 04:26:35 by snedir            #+#    #+#             */
/*   Updated: 2017/10/12 07:12:01 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int enable_check_piece(t_env *e)
{
	if (e->piece_x && e->piece_y)
	{
		e->check_piece = 1;
		printf("ZHAT\n");
		return (1);
	}
	return (0);
}
