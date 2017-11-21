/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 01:59:15 by snedir            #+#    #+#             */
/*   Updated: 2017/11/21 06:31:11 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		allocate_matrix(t_env *e)
{
	int		i;

	i = -1;
	e->matrix = (int**)ft_memalloc(sizeof(int*) * e->count);
	while (++i < e->count)
		e->matrix[i] = (int*)ft_memalloc(sizeof(int) * e->count);
}

void		free_map(t_env *e)
{
	int		i;

	i = -1;
	if (!e->matrix)
		return ;
	while (e->matrix[++i])
		free(e->matrix[i]);
	free(e->matrix);
}

int			verif_pipe(t_env *e, char **pipe)
{
	int		i;

	i = 0;
	while (pipe[i])
		i++;
	if (i != 2)
		return (STOP_FLAG);
	return (1);
}

int			pipe_exist(t_env *e, char **pipe)
{
	t_room	*tmp;
	while (
