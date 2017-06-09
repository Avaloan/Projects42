/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 23:55:07 by fdidelot          #+#    #+#             */
/*   Updated: 2017/06/09 05:37:06 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_print *elem;
	char	*copy;
	int		j;

	j = 0;
	while (format[j] && j != -1)
		if (format[j++] == '%')
			j = -1;
	va_start(ap, format);
	copy = ft_strdup(format);
	elem = NULL;
	if (j == -1)
	{
		elem = analyse(copy, elem);
		elem = create_stock(elem, ap);
		if (elem == NULL)
			return (-1);
	}
	va_end(ap);
	j = (int)da_print(elem, copy, 0, (size_t)0);
	return (j);
}
