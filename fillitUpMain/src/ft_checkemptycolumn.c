/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkemptycolumn.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 20:13:16 by gquerre           #+#    #+#             */
/*   Updated: 2017/03/12 23:52:51 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/fillit.h"

void	ft_checkemptycolumn(char **str, int i)
{
	int j;
	int count2;

	count2 = 0;
	j = 5;
	while (j <= 15)
	{
		if (str[0][i + j] == '.')
			count2++;
		j = j + 5;
	}
	j = j - 5;
	if (count2 == 3)
	{
		while (j >= 0)
		{
			str[0][i + j] = '0';
			j = j - 5;
		}
	}
}
