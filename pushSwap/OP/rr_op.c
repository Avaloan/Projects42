/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 12:07:50 by snedir            #+#    #+#             */
/*   Updated: 2018/07/11 15:52:49 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		rra(t_env *e)
{
	double	value;
	t_stack	*tmp;

	tmp = STACK1;
	if (!(tmp = STACK1))
		return ;
	while (tmp->prev)
		tmp = tmp->prev;
	if ((value = rv_pop(&tmp)) == ERROR)
		return ;
	push(e, value, 0);
}

void	rrb(t_env *e)
{
	double	value;
	t_stack	*tmp;

	if (!(tmp = STACK2))
		return ;
	while (tmp->prev)
		tmp = tmp->prev;
	if ((value = rv_pop(&tmp)) == ERROR)
		return ;
	push(e, value, 1);
}

void	rrr(t_env *e)
{
	rra(e);
	rrb(e);
}
