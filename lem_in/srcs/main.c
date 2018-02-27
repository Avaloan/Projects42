/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 00:32:44 by snedir            #+#    #+#             */
/*   Updated: 2018/02/27 01:08:01 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		assign_path_to_tab(t_env *e)
{
	t_path_m	*tmp;
	int			i;

	tmp = e->list_path;
	i = 0;
	while (i < e->nb_path)
	{
		e->tab_way[i].path_master = tmp;
		i++;
		if (tmp && tmp->next_path)
			tmp = tmp->next_path;
		else
			tmp = NULL;
	}
}

int			nb_wrong_path(t_env *e)
{
	int			i;
	t_path_m	*tmp;

	i = 0;
	tmp = e->list_path;
	while (tmp)
	{
		if (tmp->selected == 2)
			i++;
		tmp = tmp->next_path;
	}
	return (i);
}

void		room_mapping(t_env *e)
{
	int		i;
	t_room	*tmp;
	
	i = 0;
	if (!(e->room_tab))
		e->room_tab = (char**)ft_memalloc(sizeof(char*) * e->count);
	tmp = e->e_room;
	while (tmp && i < e->count)
	{
		e->room_tab[i] = tmp->room_name;
		tmp = tmp->next;
		i++;
	}
}

int			ghettouroom(int turn_path, int deep_level, t_env *e)
{
	t_path	*tmp;
	int		i;

	i = -1;
	tmp = e->tab_way[turn_path].path_master->path->next;
	while (tmp && ++i < deep_level)
		tmp = tmp->next;
	return (tmp->node);
}

void		printfourmi(t_env *e, int ants, int room, int da)
{
//	printf("%s\n", e->room_tab[0]);
	da == DA666BEASTXBAMBOULA ? printf("L%d-%s\n", ants, e->room_tab[room])
		: printf("L%d-%s ", ants, e->room_tab[room]);
}

int			main(void)
{
	t_env	*e;

	e = (t_env*)ft_memalloc(sizeof(t_env));
	e->start = -5;
	e->end = -5;
	e->connection[0] = -5;
	e->connection[1] = -5;
	parser(e);
	if (!path_finding(e))
		exit_error();
	//print_line(e);
	printf("\n\n");
	ft_trabul(e);
	print_tab_path(e);
	room_mapping(e);
	ants_walk(e);
	printf("%d\n", e->tab_way[0].path_master->size_path);
}
