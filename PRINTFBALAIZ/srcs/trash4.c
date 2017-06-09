/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 02:34:33 by fdidelot          #+#    #+#             */
/*   Updated: 2017/06/09 02:43:36 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		zero_fill(int len)
{
	if (len <= 7)
		return (7 - len);
	if (len > 7 && len <= 11)
		return (11 - len);
	if (len > 11 && len <= 16)
		return (16 - len);
	else
		return (21 - len);
	return (0);
}

int		*tabnum(void)
{
	int *tab;
	int i;
	int nb;

	i = 0;
	nb = 128;
	tab = (int*)malloc(sizeof(int) * 8);
	while (i < 8)
	{
		tab[i] = nb;
		nb /= 2;
		i++;
	}
	return (tab);
}

int		countspace(char *mask)
{
	int	i;

	i = 0;
	while (*mask)
	{
		if (*mask == ' ')
			i++;
		mask++;
	}
	return (1 + i);
}

int		length2(char *format, t_print *elem)
{
	if (*format == 'j')
	{
		LEN = 'j';
		return (1);
	}
	if (*format == 'z')
	{
		LEN = 'z';
		return (1);
	}
	return (0);
}
