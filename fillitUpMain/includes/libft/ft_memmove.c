/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 09:09:40 by snedir            #+#    #+#             */
/*   Updated: 2016/12/08 10:44:53 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*source;
	char	*desti;
	size_t	i;

	i = -1;
	source = (char *)src;
	desti = (char *)dst;
	if (source < desti)
		while ((int)(--len) >= 0)
			*(desti + len) = *(source + len);
	else
		while (++i < len)
			*(desti + i) = *(source + i);
	return (dst);
}
