/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checksquare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 03:22:16 by gquerre           #+#    #+#             */
/*   Updated: 2017/03/12 23:56:23 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/fillit.h"

int	ft_checksquare(char *str)
{
	int i;

	i = 0;
	if (ft_strlen(str) > 21)
		return (0);
	while (i < 20 && str[i] != '\0')
	{
		if ((i + 1) % 5 != 0 && (str[i] != '.' && str[i] != '#'))
			return (0);
		if ((i + 1) % 5 == 0 && str[i] != '\n')
			return (0);
		i++;
	}
	if (i != 20)
		return (0);
	return (1);
}
