/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_size_free.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 00:48:25 by snedir            #+#    #+#             */
/*   Updated: 2017/06/02 02:28:24 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_size_free(char const *s1, char const *s2, int size_buf, int size_stock)
{
	char*join;
	int i;
	int j;

	if (!s1 || !s2)
		return (NULL);
	if (!(join = ft_memalloc(size_buf + size_stock + 1)))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < size_buf)
		join[i] = s1[i];
	while (j < size_stock)
	{
		join[i + j] = s2[j];
		j++;
	}
	free((void *)s1);
	free((void *)s2);
	return (join);
}

