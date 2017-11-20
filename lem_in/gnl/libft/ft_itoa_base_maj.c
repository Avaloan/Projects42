/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_maj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 04:51:51 by fdidelot          #+#    #+#             */
/*   Updated: 2017/06/09 04:51:53 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_base_maj(uintmax_t nb, int base, int flag)
{
	char	*str;
	int		i;
	char	*val;

	str = malloc(sizeof(char) * 66);
	if (flag == 1)
		val = ft_strdup("0123456789ABCDEF");
	else
		val = ft_strdup("0123456789abcdef");
	i = 0;
	while (nb / base)
	{
		str[i] = val[nb % base];
		nb /= base;
		i++;
	}
	str[i] = val[nb % base];
	str[i + 1] = '\0';
	free(val);
	return (ft_strrev(str));
}
