/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 01:04:12 by fdidelot          #+#    #+#             */
/*   Updated: 2017/06/01 04:35:00 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void    field(t_print *elem)
{
	char	*space;
	int		i;
	int		size;
	char	c;

	c = ' ';
	if (HASH && NUM > (int)SIZE + 1 && ZERO && !MINUS)
		NUM -= 2;
	if ((size = NUM - ft_strlen(STOCK)) < 1)
		return ;
	if (ZERO && !MINUS)
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
	{
		SIZE = NUM;
		NUM = -1;
	}
}

void	add_plus_space(t_print *elem, int id)
{
	char *str;

	if (NUM != -1)
	{
		if (id < 1)
			str = ft_strdup("+");
		else
			str = ft_strdup(" ");
		STOCK = ft_strjoin_free(str, STOCK, 2);
		SIZE += 1;
	}
	else
	{
		if (id < 1)
			STOCK[0] = '+';
		else
			STOCK[0] = ' ';
	}
}

int		apply_hash(t_print *elem)
{
	char *str;

	str = NULL;
	if (SPEC == 'X' || (SPEC == 'x' && LEN == 'l'))
	{
		str = ft_strdup("0X");
		SIZE += 2;
	}
	else if (SPEC == 'x' || SPEC == 'p')
	{
		str = ft_strdup("0x");
		SIZE += 2;
	}
	else if (SPEC == 'O' || (SPEC == 'o' && LEN == 'l') || SPEC == 'o')
	{
		str = ft_strdup("0");
		SIZE += 1;
	}
	if (str)
		STOCK = ft_strjoin_free(str, STOCK, 2);
	return (1);
}
