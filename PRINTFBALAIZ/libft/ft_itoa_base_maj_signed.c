/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_maj_signed.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 00:43:53 by fdidelot          #+#    #+#             */
/*   Updated: 2017/06/09 05:29:11 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*paste1(int *i, int *min, char **str)
{
	*min = 0;
	*str = (char*)malloc(sizeof(char) * 68);
	*i = 0;
	return (ft_strdup("0123456789abcdef"));
}

static void	thing(int min, char *str, int i)
{
	if (min)
	{
		str[i + 1] = '-';
		str[i + 2] = '\0';
	}
	else
		str[i + 1] = '\0';
}

char		*ft_itoa_base_maj_signed(intmax_t nb, int base)
{
	char	*str;
	int		i;
	char	*val;
	int		min;

	val = NULL;
	str = NULL;
	if (nb < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	val = paste1(&i, &min, &str);
	if (nb < 0)
	{
		min = 1;
		nb *= -1;
	}
	while (nb / base)
	{
		str[i] = val[nb % base];
		nb /= base;
		i++;
	}
	str[i] = val[nb % base];
	thing(min, str, i);
	free(val);
	return (ft_strrev(str));
}
