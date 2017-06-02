/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 00:12:21 by fdidelot          #+#    #+#             */
/*   Updated: 2017/06/02 03:32:33 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	join(t_print *elem, t_print *new)
{
	while (NEXT)
		elem = NEXT;
	NEXT = new;
}

t_print	*init()
{
	t_print *elem;

	elem = (t_print*)malloc(sizeof(t_print));
	MINUS = 0;
	PLUS = 0;
	SPACE = 0;
	HASH = 0;
	ZERO = 0;
	NUM = 0;
	NACC = 1;
	ACC = 0;
	STAR = 0;
	STARAC = 0;
	LEN = '0';
	SPEC = '1';
	STOCK = NULL;
	NEXT = NULL;
	DOLL = 0;
	SIZE = 0;
	SIZEF = 0;
	SIZEW = 0;
	RUSTINE = 0;
	return (elem);
}
