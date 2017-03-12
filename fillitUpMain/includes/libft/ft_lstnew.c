/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 09:14:31 by snedir            #+#    #+#             */
/*   Updated: 2016/12/07 09:14:34 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*link;

	link = (t_list*)malloc(sizeof(*link));
	if (!link)
		return (NULL);
	if (content == 0)
	{
		link->content = NULL;
		link->content_size = 0;
	}
	else
	{
		link->content = malloc(content_size);
		if (!content)
			return (NULL);
		ft_memcpy(link->content, content, content_size);
		link->content_size = content_size;
	}
	link->next = NULL;
	return (link);
}
