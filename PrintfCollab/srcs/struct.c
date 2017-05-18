/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 05:37:09 by snedir            #+#    #+#             */
/*   Updated: 2017/05/12 13:27:24 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print		*init()
{
	t_print *elem;

	elem = (t_print*)malloc(sizeof(t_print));
	MINUS = 0;
	PLUS = 0;
	SPACE = 0;
	HASH = 0;
	ZERO = 0;
	NUM = 0;
	STAR = 0;
	ACC = 0;
	STARAC = 0;
	NACC = 0;
	LEN = '0';
	SPEC = '1';
	//NOPE = 0;
	DOLL = 0;
	SIZE = 0;
	NEXT = NULL;
	STOCK = NULL;
	return (elem);
}

