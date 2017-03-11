/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkemptyline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 19:08:32 by gquerre           #+#    #+#             */
/*   Updated: 2017/03/11 02:27:32 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char	*ft_checkemptyline(char *str, t_iter *var)
{
	var->count = 0;
	var->end = 0;
	var->start = 0;
	var->i = 0;
	while (var->end < 4)
	{
		while (str[var->i] != '\n')
		{
			if (str[var->i] == '#')
				var->end += 1;
			if (str[var->i] == '.' || str[var->i] == '0')
			{
				var->count += 1;
				if (var->i < 4)
					ft_checkemptycolumn(&str, var->i);
			}
			var->i += 1;
		}
		var->start = ft_checkcount(var->count, var->start);
		var->count = 0;
		var->i += 1;
	}
	return (ft_readlines(ft_strsub(str, var->start, var->i - var->start)));
}

char	*ft_readlines(char *str)
{
	int	i;

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
