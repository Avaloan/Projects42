/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 08:33:59 by snedir            #+#    #+#             */
/*   Updated: 2017/05/25 04:26:27 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


/* BEAUCOUP DE FREE A FAIRE */


char			*create_mask(int len)
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

int				zero_fill(int len)
{
	if (len <= 7)
		return (7 - len);
	if (len > 7 && len <= 11)
		return (11 - len);
	if (len > 11 && len <= 16)
		return (16 - len);
	else
		return (21 - len);
	return (0);
}

char			*fill_mask(char *mask, char *fill)
{
	int i;
	int j;
	int zero;

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
			mask[i] = fill[j];
			j++;
		}
		i++;
	}
	return (mask);
}

int				*tabnum()
{
	int *tab;
	int i = 0;
	int nb = 128;

	tab = (int*)malloc(sizeof(int) * 8);
	while (i < 8)
	{
		tab[i] = nb;
		nb /= 2;
		i++;
	}
	return (tab);
}

int					countspace(char *mask)
{
	int				i;

	i = 0;
	while (*mask)
	{
		if (*mask == ' ')
			i++;
		mask++;
	}
	return (1 + i);
}

char		*binary_to_dec(char **split, int sizetab)
{
	char *tab;
	int *add;
	int nb;
	int i;
	int j;

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
		tab[i] = nb;
		nb = 0;
		j = 0;
		i++;
	}
	free(add);
	return (tab);
}

char			*wide_char(t_print *elem, va_list ap)
{
	char	*str;
	size_t	len;
	char	*mask;
	char	*fill;
	wint_t	c;
	
	c = (wchar_t)va_arg(ap, wint_t);
	str = ft_itoa_base(c, 2);
	len = ft_strlen(str);
	mask = create_mask(len);
	fill = fill_mask(mask, str);
	STOCK = binary_to_dec(ft_strsplit(fill, ' '), countspace(mask));
	SIZE = ft_strlen(STOCK);
	return (STOCK);
}

char			*arg_char(t_print *elem, va_list ap)
{
	int		data;

	data = (char)va_arg(ap, int);
	STOCK = (char*)malloc(sizeof(char));
	STOCK[0] = data;
	SIZE = 1;
	return (STOCK);
}




