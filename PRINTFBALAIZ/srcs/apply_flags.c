/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 01:04:12 by fdidelot          #+#    #+#             */
/*   Updated: 2017/05/27 05:40:49 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void    field(t_print *elem)
{
    char    *space;
    int     i;
    int     size;
	char	c;

	c = ' ';
    if ((size = NUM - ft_strlen(STOCK)) < 1)
        return ;
	if (ZERO)
		c = '0';
    i = 0;
    space = malloc(sizeof(char) * size);
    space[size] = '\0';
    while (i < size)
        space[i++] = c;
    if (MINUS)
        STOCK = ft_strjoin_free(STOCK, space, 2);
    else
        STOCK = ft_strjoin_free(space, STOCK, 2);
	if ((int)SIZE < NUM)
		SIZE = NUM;
}

void	add_plus_space(t_print *elem, int id)
{
	char *str;

	if (id < 1)
		str = ft_strdup("+");
	else
		str = ft_strdup(" ");
	STOCK = ft_strjoin_free(str, STOCK, 2);
	SIZE += 1;
}

int		apply_hash(t_print *elem)
{
	char *str;

	str = ft_strdup("0x");
	STOCK = ft_strjoin_free(str, STOCK, 2);
	SIZE += 2;
	return (1);
}
