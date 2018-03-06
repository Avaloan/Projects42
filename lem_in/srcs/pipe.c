/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 01:59:15 by snedir            #+#    #+#             */
/*   Updated: 2018/03/06 00:30:31 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		allocate_matrix(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	fmalloc((void**)&e->matrix, sizeof(t_tab) * e->count);
	while (++j < e->count)
		e->matrix[j].parent = -1;
	while (++i < e->count)
		if (!(e->matrix[i].tab = (int*)ft_memalloc(sizeof(int) * e->count)))
		{
			perror("Allocation Error");
			exit(0);
		}
}

void		free_map(char **pipe)
{
	int		i;

	i = -1;
	if (!pipe)
		return ;
	while (pipe[++i])
		free(pipe[i]);
	free(pipe);
}

int			verif_nb_pipe(char *line)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (line[++i])
		if (line[i] == '-')
			count++;
	if (count != 1)
		return (STOP_FLAG);
	return (1);
}

int			pipe_exist(t_env *e, char **pipe)
{
	t_room	*tmp;

	tmp = E_ROOM;
	while (tmp)
	{
		if (!(ft_strcmp(tmp->room_name, pipe[0])))
			e->connection[0] = tmp->id;
		else if (!(ft_strcmp(tmp->room_name, pipe[1])))
			e->connection[1] = tmp->id;
		tmp = tmp->next;
		if (e->connection[0] != -5 && e->connection[1] != -5)
			return (1);
	}
	return (STOP_FLAG);
}

int			get_pipe(char *line, t_env *e)
{
	char	**pipe;

	if (!e->matrix)
		allocate_matrix(e);
	if (verif_nb_pipe(line) == STOP_FLAG)
		return (STOP_FLAG);
	pipe = ft_strsplit(line, '-');
	if (pipe_exist(e, pipe) == STOP_FLAG)
	{
		free_map(pipe);
		return (STOP_FLAG);
	}
	free_map(pipe);
	assign_pipe(e);
	return (1);
}
