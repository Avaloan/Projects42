/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 01:48:17 by fdidelot          #+#    #+#             */
/*   Updated: 2017/06/09 04:36:29 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_nether(t_print *elem)
{
	free(STOCK);
	STOCK = ft_strnew(1);
	SIZE = 0;
}

void	ft_chatterton(int i, int size, int rust, t_print *elem)
{
	char	c;
	char	*space;

	c = '0';
	space = malloc(sizeof(char) * size);
	if (rust)
		space[0] = '-';
	space[size] = '\0';
	while (i < size)
		space[i++] = c;
	STOCK = ft_strjoin_free(space, STOCK, 2);
	if ((int)SIZE < NACC)
		SIZE = NACC;
	if (rust)
		SIZE++;
}

void	ft_scotch(t_print *elem, char *space)
{
	if ((int)SIZE < NUM)
		SIZE = NUM;
	free(STOCK);
	STOCK = space;
	RUSTINE = 989;
}

int		ft_velcro(char *str, t_print *elem)
{
	if (str)
		STOCK = ft_strjoin_free(str, STOCK, 2);
	return (1);
}
