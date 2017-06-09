/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 01:04:12 by fdidelot          #+#    #+#             */
/*   Updated: 2017/06/09 02:29:11 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
	return (ft_velcro(str, elem));
}

void	precision(t_print *elem)
{
	int		i;
	int		size;
	int		rust;

	rust = 0;
	i = 0;
	if ((SPEC == 'o' || SPEC == 'O') && HASH && NACC > 1)
		NACC--;
	if ((size = NACC - ft_strlen(STOCK)) < 0)
		return ;
	if (ft_atoi(STOCK) < 0)
	{
		STOCK = ft_strdup(STOCK + 1);
		rust = 1;
		size += 2;
		i++;
	}
	ft_chatterton(i, size, rust, elem);
}
