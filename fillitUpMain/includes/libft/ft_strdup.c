/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 09:45:22 by snedir            #+#    #+#             */
/*   Updated: 2016/12/08 07:42:18 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(const char *str)
{
	size_t		i;
	char		*s2;

	i = ft_strlen(str);
	if (!str)
		return (NULL);
	s2 = ft_strnew(i);
	if (!s2)
		return (NULL);
	ft_strcpy(s2, str);
	return (s2);
}
