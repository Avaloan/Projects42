/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:26:46 by snedir            #+#    #+#             */
/*   Updated: 2017/06/09 03:55:33 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <string.h>

void		apply_flags(t_print *elem)
{
	if (ACC && SPEC != 'c' && (SPEC == 'o' || SPEC == 'p' || SPEC == 'u' ||
						SPEC == 'U' || SPEC == 'O' || SPEC == 'd' ||
						SPEC == 'i' || SPEC == 'D' || SPEC == 'x' ||
						SPEC == 'X'))
		precision(elem);
	if (ZERO && !MINUS && *STOCK != '\0')
		field(elem);
	else if (SPEC == 'c' && *STOCK == '\0')
		field_zero(elem);
	if (ft_atoi(STOCK) == 0 && ACC && NACC == 0 && (SPEC == 'o' ||
				SPEC == 'u' || SPEC == 'U' || SPEC == 'O' || SPEC == 'd' ||
				SPEC == 'i' || SPEC == 'D' || SPEC == 'x' || SPEC == 'X'))
		ft_nether(elem);
	if (PLUS && ft_atoi(STOCK) > -1 && SPEC != '%')
		add_plus_space(elem, 0);
	else if (ft_atoi(STOCK) > 0 && SPACE && SPEC != '%' &&
			(SIZE != 1 && *STOCK != '\0'))
		add_plus_space(elem, 1);
	if ((HASH && ft_atoi(STOCK) != 0) || (HASH && (SPEC == 'o' ||
											SPEC == 'O')) || SPEC == 'p')
		apply_hash(elem);
	if ((!ZERO || (ZERO && MINUS)) && RUSTINE != 989)
		field(elem);
}

char		*place_zero(char *final, char *str, int size, int sizebuf)
{
	int		i;
	int		j;
	int		k;
	char	*filled;

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

t_print		*create_stock(t_print *elem, va_list ap)
{
	t_print	*start;
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
		if (STARAC > 0)
			NACC = va_arg(ap, int);
		ret = get_arg(elem, ap);
		if (ret == 0)
			return (NULL);
		apply_flags(elem);
		elem = NEXT;
	}
	return (start);
}

int			get_arg(t_print *elem, va_list ap)
{
	if (SPEC == 'C' || (SPEC == 'c' && LEN == 'l'))
		curmax(elem, ap);
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
		wide_string(elem, ap);
	else if (SPEC == '%')
	{
		STOCK = ft_strdup("%");
		SIZE = 1;
	}
	else if (SPEC == 'p')
		STOCK = get_pointer(elem, ap);
	return (1);
}

size_t		da_print(t_print *elem, char *fo, int i, size_t sp)
{
	int				s;
	char			*f;

	f = ft_strnew(1);
	while (fo[i])
	{
		s = i;
		while (fo[i] && fo[i] != '%')
			i++;
		if (fo[i] == '%')
		{
			if (i - s > 0)
				f = ft_strjoin_size_free(f, ft_strsub(fo, s, i - s), sp, i - s);
			sp += (size_t)i - s;
			f = ft_strjoin_size_free(f, STOCK, sp, SIZE);
			bandaid(&sp, &i, elem);
			elem = NEXT;
		}
		else if (!fo[i])
		{
			f = ft_strjoin_size_free(f, ft_strsub(fo, s, i - s), sp, i - s);
			sp += (size_t)i - (size_t)s;
		}
	}
	return (bandage(sp, f));
}
