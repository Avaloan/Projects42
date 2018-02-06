/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ants.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 04:20:49 by snedir            #+#    #+#             */
/*   Updated: 2018/02/06 05:39:16 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	send_ants(t_env *e)
{
	int	nb_ants_send = 0;
	int	i = 0;
	int	current_ant = 0;
	while (nb_ants_send < e->nb_ants)
	{
		while (i < e->nb_path)
		{
			if (e->tab_way[i].ants_per_path > 0)
			{
				add_kyuuh_elem();
				//enqueue_ants(current_ant);
				print_kyuuh();
				if (ants == end)
					//dequeue_ant;
					dekyuuh();
			e->tab_way[i].ants_per_path--;
			}
			i++;
			current_ant++;
		}
		fonction_affichage();
		printf("\n");
		nb_ants_send += i;
		i = 0;
	}
}


void	send_ants()
{
}

void	move_ants(int id_tab_way)
{
	t_kyuuh *tmp;
	
	tmp = e->tab_way[id_tab_way].ants_in_path;
	if (e->tab_way[id_tab_way].ants_per_path > 0)
	{
		while (tmp)
		{
			tmp->current_room = tmp->current_room->next;
			tmp = tmp->prev
		}
	}
}
