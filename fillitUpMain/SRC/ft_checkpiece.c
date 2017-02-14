/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkpiece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 02:28:06 by gquerre           #+#    #+#             */
/*   Updated: 2017/01/14 03:46:06 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fillit.h"

int	ft_checkpiece(char *str)
{
	int i;
	int count;
	int k;

	i = -1;
	count = 0;
	while (str[++i] != '\0')
	{
		k = 0;
		if (str[i] == '#')
		{
			k = (str[i + 1] == '#') ? k + 1 : k;
			if (i > 4)
				k = (str[i - 5] == '#') ? k + 1 : k;
			if (i % 5 != 0)
				k = (str[i - 1] == '#') ? k + 1 : k;
			if (i < 14)
				k = (str[i + 5] == '#') ? k + 1 : k;
		}
		if (k != 0)
			count++;
	}
	if (count == 4)
		return (1);
	return (0);
}
