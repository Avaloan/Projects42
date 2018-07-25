/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 18:13:16 by snedir            #+#    #+#             */
/*   Updated: 2018/07/10 14:16:29 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_env *e)
{
	push(e, pop(&STACK2), 0);
}

void	pb(t_env *e)
{
	push(e, pop(&STACK1), 1);
}
