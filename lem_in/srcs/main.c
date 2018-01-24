/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 00:32:44 by snedir            #+#    #+#             */
/*   Updated: 2018/01/24 02:49:09 by snedir           ###   ########.fr       */
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
	print_line(e);
	printf("\n\n");
	print_path(e);
}
