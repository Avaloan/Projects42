/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 01:09:12 by fdidelot          #+#    #+#             */
/*   Updated: 2017/06/08 05:57:20 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		length(char *format, t_print *elem)
{
	if (*format == 'h')
	{
		if (*(format + 1) == 'h')
		{
			LEN = 'H';
			return (2);
		}
		LEN = 'h';
		return (1);
	}
	if (*format == 'l')
	{
		if (*(format + 1) == 'l')
		{
			LEN = 'L';
			return (2);
		}
		LEN = 'l';
		return (1);
	}
	if (*format == 'j')
	{
		LEN = 'j';
		return (1);
	}
	if (*format == 'z')
	{
		LEN = 'z';
		return (1);
	}
	return (0);
}

char	specifier(t_print *elem, char format)
{
	if (format == 's')
		return (SPEC = 's');
	if (format == 'S')
		return (SPEC = 'S');
	if (format == 'p')
		return (SPEC = 'p');
	if (format == 'd' || format == 'i')
		return (SPEC = 'd');
	if (format == 'D')
		return (SPEC = 'D');
	if (format == 'o')
		return (SPEC = 'o');
	if (format == 'O')
		return (SPEC = 'O');
	if (format == 'u')
		return (SPEC = 'u');
	if (format == 'U')
		return (SPEC = 'U');
	if (format == 'x')
		return (SPEC = 'x');
	if (format == 'X')
		return (SPEC = 'X');
	if (format == 'c')
		return (SPEC = 'c');
	if (format == 'C')
		return (SPEC = 'C');
	if (format == '%')
		return (SPEC = '%');
	if (format == '$')
		return (SPEC = '$');
	return (0);
}

int		flags(char format, t_print *elem)
{
	if (format == '-')
		return (MINUS = 1);
	if (format == '+')
		return (PLUS = 1);
	if (format == ' ')
		return (SPACE = 1);
	if (format == '#')
		return (HASH = 1);
	if (format == '0')
		return (ZERO = 1);
	if (format == '*')
		return (STAR = 1);
	return (0);
}

int	da_check(char format)
{
	if (format == '-')
		return (1);
	if (format == '+')
		return (1);
	if (format == ' ')
		return (1);
	if (format == '#')
		return (1);
	if (format == '0')
		return (1);
	if (format == '*')
		return (1);
	if (format == 'h')
		return (1);
	if (format == 'l')
		return (1);
	if (format == 'j')
		return (1);
	if (format == 'z')
		return (1);
	if (ft_isdigit(format))
		return (1);
	return (0);
}
