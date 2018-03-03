/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_hnci.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 05:37:01 by snedir            #+#    #+#             */
/*   Updated: 2018/03/03 05:43:41 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		modif_new_ants(t_send_ants *send_ants, t_env *e)
{
	send_ants->i = 0;
	while (++send_ants->i < send_ants->new_ants)
		if (send_ants->turn >= send_ants->papp -
				e->tab_way[send_ants->i].path_master->size_path)
			send_ants->new_ants--;
	send_ants->turn++;
}

void		ft_pukutak(t_send_ants *send_ants, t_ants *tab_ants)
{
	send_ants->total += send_ants->new_ants;
	send_ants->i = 0;
	while (send_ants->i < send_ants->new_ants)
	{
		tab_ants[send_ants->ants].path = send_ants->i;
		send_ants->ants++;
		send_ants->i++;
	}
}

void		assign_pipe(t_env *e)
{
	e->matrix[e->connection[1]].tab[e->connection[0]] = 1;
	e->matrix[e->connection[0]].tab[e->connection[1]] = 1;
	e->connection[0] = -5;
	e->connection[1] = -5;
}

void		norme_delete_path(t_norme *st_l)
{
	st_l->stock_free = st_l->tmp_path->next;
	free(st_l->tmp_path);
	st_l->tmp_path->next = st_l->stock_free;
	st_l->tmp_path = st_l->tmp_path->next;
}

int			verif_pipe(char **pipe)
{
	int		i;

	i = 0;
	while (pipe[i])
		i++;
	if (i != 2)
		return (STOP_FLAG);
	return (1);
}
