/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 05:54:24 by snedir            #+#    #+#             */
/*   Updated: 2017/05/16 08:30:34 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*apply_width_string(t_print *elem)
{
	int	i;
	int	j;

	if (NACC < 0)
		return (STOCK);
	i = NACC;
	j = 0;
	while (STOCK[i])
	{
		STOCK[i] = '\0';
		i++;
		j++;
	}
	SIZE -= j;
	return (STOCK);
}
