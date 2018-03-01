/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 05:18:43 by snedir            #+#    #+#             */
/*   Updated: 2018/02/27 05:21:30 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_path		*new_node(int path)
{
	t_path	*elem;

	elem = (t_path*)ft_memalloc(sizeof(t_path));
	elem->node = path;
	elem->next = NULL;
	return (elem);
}

void		add_elem_node(t_env *e, int path)
{
	t_path	*tmp;

	tmp = e->current->path;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new_node(path);
}

t_path_m	*new_elem_path(int size_path, int path)
{
	t_path_m	*new_path;

	new_path = (t_path_m*)ft_memalloc(sizeof(t_path_m));
	new_path->next_path = NULL;
	new_path->path = new_node(path);
	new_path->size_path = size_path;
	new_path->selected = -1;
	return (new_path);
}

void		add_elem_path(t_env *e, int size_path, int path)
{
	int			i;

	i = 0;
	if (!e->list_path)
	{
		e->list_path = new_elem_path(size_path, path);
		e->current = e->list_path;
		return ;
	}
	else if (!e->current->next_path)
	{
		e->current->next_path = new_elem_path(size_path, path);
		e->current = e->current->next_path;
	}
}
