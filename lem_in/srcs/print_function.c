/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 05:02:05 by snedir            #+#    #+#             */
/*   Updated: 2018/03/02 02:44:27 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		print_path(t_env *e)
{
	t_path_m	*tmp;
	t_path		*tmp2;

	tmp = e->list_path;
	while (tmp)
	{
		tmp2 = tmp->path;
		while (tmp2)
		{
			print_name(e, tmp2->node);
			tmp2 = tmp2->next;
		}
		printf("\n");
		tmp = tmp->next_path;
	}
}

void		read_path_tab(t_env *e)
{
	int i;

	i = -1;
	while (++i < e->nb_path)
		printf("%d\n", e->tab_way[i].path_master->size_path);
}

void		print_path_for_tab(t_env *e, int i)
{
	t_path		*tmp2;

	tmp2 = e->tab_way[i].path_master->path;
	while (tmp2)
	{
		print_name(e, tmp2->node);
		tmp2 = tmp2->next;
	}
	printf("\n");
}

void		print_tab_path(t_env *e)
{
	int i;

	i = -1;
	while (++i < e->nb_path)
		if (e->tab_way[i].path_master)
			print_path_for_tab(e, i);
}

void		print_line(t_env *e)
{
	while (E_LINE)
	{
		printf("%s\n", E_LINE->line);
		E_LINE = E_LINE->next;
	}
}

void		print_room(t_env *e)
{
	while (E_ROOM)
	{
		printf("ROOM %s ID %d\n", E_ROOM->room_name, E_ROOM->id);
		E_ROOM = E_ROOM->next;
	}
}
