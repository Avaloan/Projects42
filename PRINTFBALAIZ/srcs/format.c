/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:26:46 by snedir            #+#    #+#             */
/*   Updated: 2017/06/08 06:05:02 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <string.h>

void	apply_flags(t_print *elem)
{
	if (ACC && SPEC != 'c' && (SPEC == 'o' || SPEC == 'p' || SPEC == 'u' ||
				SPEC == 'U' || SPEC == 'O' || SPEC == 'd'
			|| SPEC == 'i' || SPEC == 'D' || SPEC == 'x' || SPEC == 'X'))
		precision(elem);
	if (ZERO && !MINUS && *STOCK != '\0')
		field(elem);
	else if (SPEC == 'c' && *STOCK == '\0')
		field_zero(elem);
	if (ft_atoi(STOCK) == 0 && ACC && NACC == 0 && (SPEC == 'o'
				|| SPEC == 'u'|| SPEC == 'U' || SPEC == 'O' ||SPEC == 'd' \
				|| SPEC == 'i' || SPEC == 'D' || SPEC == 'x' || SPEC == 'X'))
	{
		free(STOCK);
		STOCK = ft_strnew(1);
		SIZE = 0;
	}
	if (PLUS && ft_atoi(STOCK) > -1 && SPEC != '%')
		add_plus_space(elem, 0);
	else if (ft_atoi(STOCK) > 0 && SPACE && SPEC != '%' && (SIZE != 1 && *STOCK != '\0'))
		add_plus_space(elem, 1);
	if ((HASH && ft_atoi(STOCK) != 0) || (HASH && (SPEC == 'o' || SPEC == 'O')) || SPEC == 'p')
		apply_hash(elem);
	if ((!ZERO || (ZERO && MINUS)) && RUSTINE != 989)
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

	int		ret;
	start = elem;
	while (elem)
	{
		if (STAR)
			NUM = va_arg(ap, int);
		if (NUM < 0)
		{
			NUM *= -1;
			MINUS = 1;
		}
//		if (STARAC)
//			NACC = va_arg(ap, int);
		ret = get_arg(elem, ap);
		if (ret == 0)
			return (NULL);
		apply_flags(elem);
		elem = NEXT;
	}
	return (start);
}

int		get_arg(t_print *elem, va_list ap)
{
	if (SPEC == 'C' || (SPEC == 'c' && LEN == 'l'))
	{
		if (MB_CUR_MAX == 1)
			arg_char(elem, ap);
		else
			/*STOCK = */wide_char(elem, ap);
	}
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
		STOCK = get_pointer(elem, ap);
	return (1);
}

size_t		da_print(t_print *elem, char *format)
{
	size_t	size_print;
	int		i;
	int		j;
	unsigned int		start;
	char	*final_buff;

	i = 0;
	j = 0;
	size_print = 0;
	final_buff = ft_strnew(1);
	while (format[i])
	{
		start = (unsigned int)i;
		while (format[i] && format[i] != '%')
			i++;
		if (format[i] == '%')
		{
			if (i - start  > 0)
				final_buff = ft_strjoin_size_free(final_buff, ft_strsub(format, start, i - start), size_print, i - start);
			size_print += (size_t)i - start;
			final_buff = ft_strjoin_size_free(final_buff, STOCK, size_print, SIZE);
			size_print += SIZE;
			i += SIZEF;
			elem = NEXT;
		}
		else if (!format[i])
		{
			final_buff = ft_strjoin_size_free(final_buff, ft_strsub(format, start, i - start), size_print, i - start);
			size_print += (size_t)i - (size_t)start;
		}
	}
	if (size_print > 0)
		write(1, final_buff, size_print);//ft_strlen(final_buff));
	free(final_buff);
	return (size_print);
}
