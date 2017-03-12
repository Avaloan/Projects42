/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:36:05 by snedir            #+#    #+#             */
/*   Updated: 2016/12/14 13:42:38 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		b;

	if (!s)
		return (NULL);
	b = 0;
	if (!(str = ft_strnew(len)))
		return (NULL);
	while ((unsigned int)b < len)
	{
		str[b] = s[start];
		start++;
		b++;
	}
	str[b] = '\0';
	return (str);
}
