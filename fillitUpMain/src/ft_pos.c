/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:56:32 by snedir            #+#    #+#             */
/*   Updated: 2017/03/12 23:40:01 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int	dv_p(int pos, int taille)
{
	return (pos / taille);
}

int	md_p(int pos, int taille)
{
	return (pos % taille);
}
