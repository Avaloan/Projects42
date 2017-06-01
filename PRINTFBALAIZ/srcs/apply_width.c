/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 05:54:24 by snedir            #+#    #+#             */
/*   Updated: 2017/06/01 01:42:28 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*apply_width_string(t_print *elem)
{
	int	i;
	int	j;

	if (NACC < 0 || STARAC < 0)
		return (STOCK);
	if (STARAC)
		i = STARAC;
	else
		i = NACC;
	j = 0;
	while (STOCK[i])
	{
		STOCK[i] = '\0';
		i++;
		j++;
	}
	SIZE -= j;
	return (STOCK);
}

char	*get_pointer(t_print *elem, va_list ap)
{
	uintmax_t	data;
	char		*str;

	data = (uintmax_t)va_arg(ap, void*);
	if (LEN == 'H')
		data = (unsigned char)data;
	if (LEN == 'h')
		data = (unsigned short)data;
	if (LEN == 'l')
		data = (unsigned long)data;
	if (LEN == 'L')
		data = (unsigned long long)data;
	if (LEN == 'z')
		data = (size_t)data;
	if (LEN == '0')
		data = (unsigned long)data;
	str = ft_itoa_base_maj(data, 16, 0);
	SIZE = ft_strlen(str);
	return (str);
}

int wide_str_trans(t_print *elem, wchar_t wide)
{
	char    *str;
	size_t  len;
	char    *mask;
	char    *fill;
	char    *tmp;

	if (!STOCK)
		STOCK = ft_memalloc(1);
	str = ft_itoa_base(wide, 2);
	len = ft_strlen(str);
	mask = create_mask(len);
	fill = fill_mask(mask, str);
	tmp = binary_to_dec(ft_strsplit(fill, ' '), countspace(mask));
	SIZE += ft_strlen(tmp);
	if ((NACC < (int)SIZE && ACC))// || (STARAC < (int)SIZE && ACC))
	{
		SIZE -= ft_strlen(tmp);
		return (0);
	}
	STOCK = ft_strjoin_free(STOCK, tmp, 2);
	return (1);
}

int wide_string(t_print *elem, va_list ap)
{
	wchar_t *data;
	int     i;

	i = 0;
	data = va_arg(ap, wchar_t*);
	if (data == NULL)
	{
		STOCK = ft_strdup("(null)");
		SIZE += 6;
		return (1);
	}
	if (!*data)
	{
		STOCK = ft_strdup("\0");
		return (1);
	}
	while (*data)
	{
		if (wide_str_trans(elem, *data) == 0)
			return (0);
		data++;
		i++;
	}
	return (1);
}
