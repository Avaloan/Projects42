/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 18:48:09 by snedir            #+#    #+#             */
/*   Updated: 2017/05/10 20:07:16 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


void	create_stock(t_print *elem)
{
	while (elem)
	{
		field(elem);
		//check_flags(elem);
		elem = NEXT;
	}
}




void	field(t_print *elem)
{
	if (NUM)
	{

