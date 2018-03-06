/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 01:24:15 by snedir            #+#    #+#             */
/*   Updated: 2018/03/06 00:16:48 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_file		*new_queue_elem(int id)
{
	t_file	*elem;

	fmalloc((void**)&elem, sizeof(t_file));
	elem->id = id;
	elem->prev = NULL;
	elem->next = NULL;
	return (elem);
}

void		add_queue_elem(t_env *e, int id)
{
	t_file	*tmp;

	tmp = E_FILE;
	if (!E_FILE)
	{
		E_FILE = new_queue_elem(id);
		return ;
	}
	while (tmp->prev)
		tmp = tmp->prev;
	tmp->prev = new_queue_elem(id);
	tmp->prev->next = tmp;
}

void		dequeue(t_env *e)
{
	t_file	*tmp;

	tmp = E_FILE->prev;
	if (!E_FILE)
		return ;
	free(E_FILE);
	E_FILE = tmp;
	if (tmp)
		tmp->next = NULL;
}
