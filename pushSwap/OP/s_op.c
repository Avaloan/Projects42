/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 18:06:22 by snedir            #+#    #+#             */
/*   Updated: 2018/07/10 14:23:06 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_env *e)
{
	int	tmp;

	if (!STACK1 || !STACK1->prev)
		return ;
	tmp = STACK1->prev->nb;
	STACK1->prev->nb = STACK1->nb;
	STACK1->nb = tmp;
}

void	sb(t_env *e)
{
	int	tmp;
	
	if (!STACK2 || !STACK2->prev)
		return ;
	tmp = STACK2->prev->nb;
	STACK2->prev->nb = STACK2->nb;
	STACK2->nb = tmp;
}

void	ss(t_env *e)
{
	sa(e);
	sb(e);
}
