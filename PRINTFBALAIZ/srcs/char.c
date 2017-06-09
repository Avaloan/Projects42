/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 08:33:59 by snedir            #+#    #+#             */
/*   Updated: 2017/06/09 02:37:10 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*create_mask(int len)
{
	if (len <= 7)
		return (ft_strdup("0xxxxxxx"));
	if (len > 7 && len <= 11)
		return (ft_strdup("110xxxxx 10xxxxxx"));
	if (len > 11 && len <= 16)
		return (ft_strdup("1110xxxx 10xxxxxx 10xxxxxx"));
	else
		return (ft_strdup("11110xxx 10xxxxxx 10xxxxxx 10xxxxx"));
	return (0);
}

char	*fill_mask(char *mask, char *fill)
{
	int	i;
	int	j;
	int	zero;

	i = 0;
	j = 0;
	zero = zero_fill(ft_strlen(fill));
	while (mask[i] && fill[j])
	{
		if (mask[i] == 'x')
		{
			while (zero)
			{
				if (mask[i] == 'x')
				{
					mask[i] = '0';
					zero--;
				}
				i++;
			}
			mask[i] = fill[j++];
		}
		i++;
	}
	return (mask);
}

char	*binary_to_dec(char **split, int sizetab)
{
	char	*tab;
	int		*add;
	int		nb;
	int		i;
	int		j;

	i = 0;
	j = 0;
	nb = 0;
	add = tabnum();
	tab = (char*)ft_strnew(sizetab);
	while (split[i])
	{
		while (split[i][j])
		{
			if (split[i][j] == '1')
				nb += add[j];
			j++;
		}
		tab[i++] = nb;
		nb = 0;
		j = 0;
	}
	free(add);
	return (tab);
}

char	*wide_char(t_print *elem, va_list ap)
{
	char	*str;
	size_t	len;
	char	*mask;
	char	*fill;
	wint_t	c;

	c = (wchar_t)va_arg(ap, wint_t);
	if (c == 0)
	{
		STOCK = (char*)malloc(sizeof(char));
		STOCK[0] = c;
		SIZE = 1;
		return (STOCK);
	}
	str = ft_itoa_base(c, 2);
	len = ft_strlen(str);
	mask = create_mask(len);
	fill = fill_mask(mask, str);
	STOCK = binary_to_dec(ft_strsplit(fill, ' '), countspace(mask));
	SIZE = ft_strlen(STOCK);
	return (STOCK);
}

char	*arg_char(t_print *elem, va_list ap)
{
	int	data;

	free(STOCK);
	data = (char)va_arg(ap, int);
	STOCK = (char*)malloc(sizeof(char));
	if (data == 0)
	{
		STOCK[0] = data;
		SIZE = 1;
		return (STOCK);
	}
	STOCK[0] = data;
	SIZE = 1;
	return (STOCK);
}
