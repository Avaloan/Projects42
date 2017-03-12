/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:24:48 by snedir            #+#    #+#             */
/*   Updated: 2016/12/14 14:42:16 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*cpy;
	char	*buf;
	size_t	length;

	buf = (char *)(s1 + n);
	length = ft_strlen(s2);
	cpy = (char *)s1;
	if (!s2 || !length)
		return ((char *)s1);
	while ((cpy = ft_strchr(cpy, *s2)) && cpy <= buf)
	{
		if ((cpy + length <= buf) && !ft_strncmp(cpy, s2, length))
			return (cpy);
		cpy++;
	}
	return (NULL);
}
