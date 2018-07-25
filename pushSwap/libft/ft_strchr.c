/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:34:14 by fdidelot          #+#    #+#             */
/*   Updated: 2018/03/03 02:37:57 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;

	if (!s)
		return (NULL);
	tmp = (char *)s;
	while (*tmp && (*tmp != c))
		tmp++;
	if (*tmp != c)
		return (NULL);
	return (tmp);
}
