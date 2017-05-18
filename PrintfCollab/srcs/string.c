/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 01:48:14 by snedir            #+#    #+#             */
/*   Updated: 2017/05/16 08:23:42 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

char	*string(t_print *elem, va_list ap)
{
	STOCK = ft_strdup(va_arg(ap, char*));
	if (STOCK == 0)
		return (STOCK = "(null)");
	SIZE = ft_strlen(STOCK);
	if ((NACC < (int)SIZE && ACC))
		apply_width_string(elem);
	return (STOCK);
}
