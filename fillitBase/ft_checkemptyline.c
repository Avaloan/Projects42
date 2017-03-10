/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkemptyline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 19:08:32 by gquerre           #+#    #+#             */
/*   Updated: 2017/01/19 11:16:30 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void ft_checkemptycolumn(char **str, int i);
int  ft_checkcount(int count, int start);
char *ft_readlines(char *str);

char	*ft_checkemptyline(char *str)
{
	int start;
	int i;
	int count;
	int end;

	count = 0;
	end = 0;
	start = 0;
	i = 0;
	while (end < 4)
	{
		while (str[i] != '\n')
		{
			if (str[i] == '#')
				end++;
			if (str[i] == '.' || str[i] == '0')
			{
				count++;
				if (i < 4)
					ft_checkemptycolumn(&str, i);
			}
			i++;
		}
		start = ft_checkcount(count, start);
		count = 0;
		i++;
	}
	return (ft_readlines(ft_strsub(str, start, i - start)));
}

char *ft_readlines(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\n')
			i++;
		while (str[--i] != '#')
			str[i] = '0';
		while (str[i] != '\n')
			i++;
		i++;
	}
	return (str);
}
