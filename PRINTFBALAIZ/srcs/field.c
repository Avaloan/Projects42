/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 02:25:40 by fdidelot          #+#    #+#             */
/*   Updated: 2017/06/09 02:28:27 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	field_p(t_print *elem, char c, int size)
{
	int		i;
	char	*space;

	i = 0;
	space = (char*)malloc(sizeof(char) * size);
	if (SPACE)
	{
		space[0] = ' ';
		i++;
	}
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

void	field(t_print *elem)
{
	int		size;
	char	c;

	c = ' ';
	if ((SPEC == 'p' && ZERO) || (SPEC == 'p' && MINUS && ZERO))
		NUM -= 2;
	if ((HASH && NUM > (int)SIZE + 1 && ZERO && !MINUS))
		NUM -= 2;
	if ((size = NUM - ft_strlen(STOCK)) < 1)
		return ;
	if (ZERO && !MINUS && NACC < 2)
		c = '0';
	if (ft_atoi_u(STOCK) < 0 && ZERO)
		field_neg(elem, c, size);
	else
		field_p(elem, c, size);
}

void	field_zero(t_print *elem)
{
	char	c;
	int		size;
	int		i;
	char	*space;

	c = ' ';
	if ((size = NUM - SIZE) < 1)
		return ;
	if (ZERO && !MINUS)
		c = '0';
	i = 0;
	space = malloc(sizeof(char) * size);
	if (MINUS)
	{
		space[i++] = '\0';
		while (i <= size)
			space[i++] = c;
	}
	else
	{
		while (i < size)
			space[i++] = c;
		space[size] = '\0';
	}
	ft_scotch(elem, space);
}

void	field_neg(t_print *elem, char c, int size)
{
	char	*space;
	int		i;

	i = 0;
	size++;
	STOCK = ft_strdup(STOCK + 1);
	space = malloc(sizeof(char) * size);
	space[size] = '\0';
	if (!MINUS)
		space[i++] = '-';
	while (i < size)
		space[i++] = c;
	if (MINUS)
	{
		STOCK = ft_strjoin_free(ft_strdup("-"), STOCK, 2);
		STOCK = ft_strjoin_free(STOCK, space, 2);
	}
	else
		STOCK = ft_strjoin_free(space, STOCK, 2);
	if ((int)SIZE < NUM)
	{
		SIZE = NUM;
		NUM = -1;
	}
}
