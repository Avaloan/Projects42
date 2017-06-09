/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turashu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 03:33:06 by fdidelot          #+#    #+#             */
/*   Updated: 2017/06/09 04:40:57 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			meta_create(t_print *elem, char *format, int i)
{
	free(STOCK);
	STOCK = malloc(sizeof(char));
	*STOCK = format[i];
	SIZE += 1;
	return (i + 1);
}

int			in_create(t_print *elem, char *format, int i, int j)
{
	while (format[i] && SPEC == '1')
	{
		while (flags(format[i], elem))
			if (++i < j)
				;
		if ((i += num_width(format + i, elem)) > j)
			return (0);
		if (format[i] == '.')
		{
			i++;
			if (format[i] == '*')
			{
				i++;
				STARAC = 1;
			}
			else if ((i += num_acc(format + i, elem)) > j)
				return (0);
		}
		if ((i += length(format + i, elem)) > j)
			return (0);
		if (specifier(elem, format[i]) == 0 && !da_check(format[i]))
			return (meta_create(elem, format, i));
		i++;
	}
	return (i);
}

void		curmax(t_print *elem, va_list ap)
{
	if (MB_CUR_MAX == 1)
		arg_char(elem, ap);
	else
		wide_char(elem, ap);
}

size_t		bandage(size_t sp, char *f)
{
	if (sp > 0)
		write(1, f, sp);
	free(f);
	return (sp);
}

void		bandaid(size_t *sp, int *i, t_print *elem)
{
	*sp += SIZE;
	*i += SIZEF;
}
