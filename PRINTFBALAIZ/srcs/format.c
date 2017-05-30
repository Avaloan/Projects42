/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:26:46 by snedir            #+#    #+#             */
/*   Updated: 2017/05/30 07:19:04 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	apply_flags(t_print *elem)
{
	field(elem);
}

char	*place_zero(char *final, char *str, int size, int sizebuf)
{
	int i;
	int j;
	int k;
	char *filled;

	filled = ft_strnew(size);
	i = 0;
	j = 0;
	k = 0;
	while (k < sizebuf)
	{
		if (str[j] && i + '0' == str[j])
		{
			filled[i] = '\0';
			j++;
			i++;
		}
		filled[i] = final[k];
		k++;
		i++;
	}
	return (filled);
}



t_print	*create_stock(t_print *elem, va_list ap)
{
	t_print *start;

	start = elem;
	while (elem)
	{
		if (STAR)
			STAR = va_arg(ap, int);
		if (STARAC)
			STARAC = va_arg(ap, int);
		get_arg(elem, ap);
		apply_flags(elem);
		elem = NEXT;
	}
	return (start);
}

void	get_arg(t_print *elem, va_list ap)
{
	if (SPEC == 'C' || (SPEC == 'c' && LEN == 'l'))
		/*STOCK = */wide_char(elem, ap);
	else if (SPEC == 'c')
		arg_char(elem, ap);
	else if (SPEC == 'x' || SPEC == 'X')
		STOCK = get_hexa_args(elem, ap);
	else if (SPEC == 'o' || SPEC == 'u' || SPEC == 'U' || SPEC == 'O')
		STOCK = get_o_u_args(elem, ap);
	else if (SPEC == 'd' || SPEC == 'i' || SPEC == 'D')
		STOCK = get_signed_number(elem, ap);
	else if (SPEC == 's' && LEN != 'l')
		STOCK = string(elem, ap);
	else if (SPEC == 'S' || (SPEC == 's' && LEN == 'l'))
		/*STOCK = */wide_string(elem, ap);
	else if (SPEC == '%')
	{
		STOCK = ft_strdup("%");
		SIZE = 1;
	}
	else if (SPEC == 'p')
	{
		STOCK = get_pointer(elem, ap);
		apply_hash(elem);
	}
}

size_t		da_print(t_print *elem, char *format)
{
	size_t	size_print;
	int		i;
	int		j;
	unsigned int		start;
	char	*final_buff;
	char	*str;

	i = 0;
	j = 0;
	size_print = 0;
	final_buff = ft_strnew(1);
	str = ft_strnew(1);
	while (format[i])
	{
		start = (unsigned int)i;
		while (format[i] && format[i] != '%')
			i++;
		if (format[i] == '%')
		{
			if (i - start  > 0)
				final_buff = ft_strjoin_free(final_buff, ft_strsub(format, start, i - start), 2);
			if (*STOCK == '\0')
				str = ft_strjoin_free(str, ft_itoa_base(i, 10), 2);
			final_buff = ft_strjoin_free(final_buff, STOCK, 2);
			size_print += (size_t)i + SIZE - start;
			i += SIZEF;
			elem = NEXT;
		}
		else if (!format[i])
		{
			final_buff = ft_strjoin_free(final_buff, ft_strsub(format, start, i - start), 2);
			size_print += (size_t)i - (size_t)start;
		}
	}
	if (size_print != ft_strlen(final_buff))
	{
		write(1, place_zero(final_buff, str, size_print, ft_strlen(final_buff)), size_print);
		free(str);
	}
	else if (size_print > 0)
		write(1, final_buff, ft_strlen(final_buff));
	free(final_buff);
	return (size_print);
}
