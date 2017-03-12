/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 03:21:58 by snedir            #+#    #+#             */
/*   Updated: 2017/03/12 23:59:06 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/fillit.h"

void	ft_multi(char *c, char *buf, t_head *sent, t_tetr *elem)
{
	elem->piece = (sent->lenght + 64);
	*c = buf[20];
}

void	ft_final(char **str, char **str2, char *buf, t_iter *var)
{
	*str = ft_checkemptyline(buf, var);
	*str2 = modify_piece(*str);
	free(*str);
}

int		ft_argc(int argc)
{
	if (argc != 2)
	{
		ft_putstr("usage : mettre seulement 1 et uniquement 1 fichier\n");
		return (1);
	}
	return (0);
}
