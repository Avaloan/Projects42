/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkpiece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 02:28:06 by gquerre           #+#    #+#             */
/*   Updated: 2017/03/06 20:04:21 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_checklinksreverse(char *str)
{
	int		i;
	char	k;

	k = '1';
	i = 0;
	while (i != 20)
	{
		while (str[i] != '\n')
			i++;
		while (--i > 0 && str[i] != '\n')
		{
			//printf("i = %d\n", i);
			if (str[i] == '#')
				if ((i > 4 && (str[i - 5] == k - 1 || k == '1' || str[i - 5] == k - 2)) ||
						((i - 3) % 5 != 0 && (str [i + 1] == k - 1 || k == '1' || str[i + 1] == k - 2)) ||
						(i < 14 && (str[i + 5] == k - 1 || k == '1' || str[i + 5] == k - 2)))
					str[i] = k++;
		}
		i = (i < 4) ? i - 1 : i;
		i = (i <= 14) ? i + 6 : i;
	}
	while (--i >= 0)
		str[i] = (str[i] <= '9' && str[i] >= '0') ? '#' : str[i];
	return ((k == '5') ? 1 : 0);
}

int ft_checklinks(char *str)
{
	int		i;
	char	k;
	int		count;

	k = '1';
	i = -1;
	count = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == '#')
		{
			//printf("%s\n", str);
			count++;
			//printf("i = %d | k = %c\n", i, k);
			if ((i > 4 && (str[i - 5] >= '1' && str[i] <= '3')) ||
					(i % 5 != 0 && (str [i - 1] == k - 1 || str[i - 1] == k - 2)) ||
					(k == '1'))
				str[i] = k++;
		}
	}
	while (--i >= 0)
		if (str[i] <= '9' && str[i] >= '0')
			str[i] = '#';
	//printf("k = %c | count = %d\n", k, count);
	if ((k == '5' || ft_checklinksreverse(str)) && count == 4)
		return (1);
	return (0);
}

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
	if (count == 4 && ft_checklinks(str))
		return (1);
	return (0);
}
