/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 12:05:23 by snedir            #+#    #+#             */
/*   Updated: 2018/07/10 15:31:01 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		ra(t_env *e)
{
	double	value;
	t_stack	*tmp;

	if ((value = pop(&STACK1)) == ERROR)
		return ;
	tmp = STACK1;
	while (tmp->prev)
		tmp = tmp->prev;
	tmp->prev = new_stack_elem((int)value);
}

void		rb(t_env *e)
{
	double	value;
	t_stack	*tmp;

	if ((value = pop(&STACK2)) == ERROR)
		return ;
	tmp = STACK2;
	while (tmp->prev)
		tmp = tmp->prev;
	tmp->prev = new_stack_elem((int)value);
}

void	rr(t_env *e)
{
	ra(e);
	rb(e);
}
