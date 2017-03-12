/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:30:01 by snedir            #+#    #+#             */
/*   Updated: 2016/12/14 13:37:40 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;
	int		count;

	if (s && f)
	{
		i = ft_strlen(s);
		count = 0;
		if (!(str = (char*)malloc(i * sizeof(*s) + 1)))
			return (NULL);
		while (count < i)
		{
			str[count] = f(*s);
			s++;
			count++;
		}
		str[count] = '\0';
		return (str);
	}
	return (NULL);
}
