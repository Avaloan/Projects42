/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 19:13:06 by snedir            #+#    #+#             */
/*   Updated: 2016/11/21 20:00:36 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	unsigned char		*source;
	unsigned char		*dest;
	size_t				i;
	unsigned char		x;

	source = (unsigned char *)src;
	dest = (unsigned char *)dst;
	x = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if ((*dest++ = *source++) == x)
			return (dest);
		i++;
	}
	return (NULL);
}
