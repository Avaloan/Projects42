/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillgrid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 07:56:08 by gquerre           #+#    #+#             */
/*   Updated: 2017/03/08 20:00:59 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		ft_lenline(t_tetr *piece, int i)
{
	int	len;
	int	k;
	int	tmp;

	len = 0;
	k = 0;
	while (len < i)
	{
		if (piece->data[len] == '\n')
			k++;
		len++;
	}
	if (k != 0)
	{
		tmp = len;
		len--;
		while (piece->data[len] != '\n')
			len--;
		len = tmp - len - 1;
	}
	return (len);
}

int		ft_searchletter(char **grid, char lettre)
{
	int	position;
	int	i;
	int	j;

	i = 0;
	j = 0;
	position = 0;
	while (grid[i])
	{
		while (grid[i][j] && grid[i][j] != lettre)
		{
			position++;
			j++;
		}
		if (grid[i][j] == lettre)
			return (position);
		j = 0;
		i++;
	}
	return (0);
}

void	ft_removepoints(char **grid, char lettre)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (grid[i])
	{
		while (grid[i][j])
		{
			if (grid[i][j] == lettre)
				grid[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
}
