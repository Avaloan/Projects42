/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 02:15:39 by snedir            #+#    #+#             */
/*   Updated: 2017/05/16 08:28:37 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	flags(char format, t_print *elem)
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

// ADD STAR *****************************************
int	num_width(char *format, t_print *elem, int start)
{
	int i;
	size_t	ret;
	char *str;
	
	i = 0;
	ret = 0;
	str = NULL;
	while (ft_isdigit(format[i]))
		i++;
	if (i)
	{
		str = ft_strsub(format, 0, (size_t)i);
		NUM = ft_atoi(str);
		ret = ft_strlen(str);
		free(str);
		return ((int)ret);
	}
	return (0);
}

int	num_acc(char *format, t_print *elem, int start)
{
	int i;
	size_t	ret;
	char *str;
	
	i = 0;
	ret = 0;
	str = NULL;
	ACC = 1;
	while (ft_isdigit(format[i]))
		i++;
	if (i)
	{
		str = ft_strsub(format, 0, (size_t)i);
		NACC = ft_atoi(str);
		ret = ft_strlen(str);
		free(str);
		return ((int)ret);
	}
	return (0);
}

/*
int	parser(char *format, t_print *elem)
{
	int i;

	i = 0;
	STOCK = ft_strnew(1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			STOCK = ft_strsub(STOCK, );
		}
		i++;
	}
	return (1);
}
*/
int	lenght(char *format, t_print *elem)
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

char specifier(t_print *elem, char format)
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
	return (0);
}

int create_elem(t_print *elem, char *format)
{
	int i;
	int	j;

	i = 1;
	j = (int)ft_strlen(format);
	while (format[i] && SPEC == '1')
	{
		while (flags(format[i], elem))
			if (++i < j)
				;
		if ((i += num_width(&format[i], elem, i)) > j)
			return (0);
		if (format[i] == '.')
		{
			i++;
			if ((i += num_acc(format + i, elem, i)) > j)
				return (0);
		}
		if ((i += lenght(&format[i], elem)) > j)
			return (0);
		specifier(elem, format[i]);
		i++;
	}
	if (SPEC == '1')
		return (0);
	return (i);
}

void	join(t_print *elem, t_print *new)
{
	while (NEXT)
		elem = NEXT;
	NEXT = new;
}

t_print	*analyse(char *format, t_print *elem) //va_list *ap
{
	t_print *start;
	t_print *new;
	
	while (*format)
	{
		if (*format == '%')
		{
			if (!elem)
			{
				elem = init();
				start = elem;
				format += create_elem(elem, format);
			}
			else
			{
				new = init();
				format += create_elem(new, format);
				join(elem, new);
			}
		}
		else
			format++;
	}
	return (start);
}
