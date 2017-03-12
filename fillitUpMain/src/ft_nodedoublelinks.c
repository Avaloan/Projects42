/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodedoublelinks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:17:50 by snedir            #+#    #+#             */
/*   Updated: 2017/03/12 23:58:08 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/fillit.h"

t_tetr		*new_node(char *data)
{
	t_tetr	*elem;

	elem = NULL;
	elem = (t_tetr*)malloc(sizeof(t_tetr));
	elem->data = data;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

t_tetr		*add_node(t_tetr *elem, char *data, t_head *master)
{
	t_tetr	*new;

	if (elem)
	{
		new = new_node(data);
		new->next = elem;
		elem->prev = new;
		master->lenght += 1;
	}
	else
	{
		new = new_node(data);
		master->first_element = new;
		master->lenght += 1;
	}
	return (new);
}
