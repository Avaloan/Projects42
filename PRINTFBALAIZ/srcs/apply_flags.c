/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 01:04:12 by fdidelot          #+#    #+#             */
/*   Updated: 2017/06/08 05:37:06 by snedir           ###   ########.fr       */
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
	if (ZERO && !MINUS && !ACC)
		c = '0';
	if (ft_atoi_u(STOCK) < 0 && ZERO)
		field_neg(elem, c, size);
	else
		field_p(elem, c, size);
}

void	add_plus_space(t_print *elem, int id)
{
	char *str;

	if ((SPEC == '1') || (PLUS && (SPEC == 'o' || SPEC == 'O' || SPEC == 'c'
					|| SPEC == 'C' || SPEC == 's')) || (SPACE && SPEC == 'u'))
		return ;
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
		if (SPEC == 'p' && ft_atoi(STOCK) == 0 && ACC && NACC == 0 && NUM == 0)
		{
			free(STOCK);
			STOCK = ft_strnew(0);
			SIZE -= 1;
		}
		str = ft_strdup("0x");
		SIZE += 2;
	}
	else if ((ACC || ft_atoi(STOCK) != 0) && (SPEC == 'O' || SPEC == 'o'))
	{
		str = ft_strdup("0");
		SIZE += 1;
	}
	if (str)
		STOCK = ft_strjoin_free(str, STOCK, 2);
	return (1);
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
	if ((int)SIZE < NUM)
		SIZE = NUM;
	free(STOCK);
	STOCK = space;
	RUSTINE = 989;
}

void	precision(t_print *elem)
{
	char	*space;
	int		i;
	int		size;
	char	c;
	int		rust;

	rust = 0;
	i = 0;
	if ((size = NACC - ft_strlen(STOCK)) < 0)
		return ;
	if (ft_atoi(STOCK) < 0)
	{
		STOCK = ft_strdup(STOCK + 1);
		rust = 1;
		size += 2;
		i++;
	}
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
