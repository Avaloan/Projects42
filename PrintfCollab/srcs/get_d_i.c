/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_d_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 01:01:46 by snedir            #+#    #+#             */
/*   Updated: 2017/05/15 05:42:40 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char			*get_signed_number(t_print *elem, va_list ap)
{
	intmax_t	data;
	char		*str;

	data = va_arg(ap, intmax_t);
	if (LEN == 'H')
		data = (char)data;
	if (LEN == 'h')
		data = (short)data;
	if (LEN == 'l')
		data = (long)data;
	if (LEN == 'L')
		data = (long long)data;
	if (LEN == 'z')
		data = (ssize_t)data;
	if (LEN == '0')
		data = (int)data;
	str = ft_itoa_base_maj_signed(data, 10);
	SIZE = ft_strlen(str);
	return (str);
}
