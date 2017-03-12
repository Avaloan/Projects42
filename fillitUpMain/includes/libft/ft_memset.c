/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:54:09 by snedir            #+#    #+#             */
/*   Updated: 2016/11/12 18:38:10 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memset(void *b, int c, size_t len)
{
	char		*string;
	size_t		i;

	i = 0;
	string = b;
	while (i < len)
	{
		*string = (char)c;
		i++;
		string++;
	}
	return (b);
}
