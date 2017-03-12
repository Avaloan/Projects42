/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:56:42 by snedir            #+#    #+#             */
/*   Updated: 2016/12/14 13:38:41 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				i;
	unsigned int	count;
	char			*str;

	if (!s && !f)
		return (NULL);
	i = ft_strlen(s);
	count = 0;
	if (!(str = (char*)malloc(i * sizeof(*s) + 1)))
		return (NULL);
	while (count < (unsigned int)i)
	{
		str[count] = f(count, *s);
		count++;
		s++;
	}
	str[count] = '\0';
	return (str);
}
