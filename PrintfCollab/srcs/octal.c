/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 05:15:15 by snedir            #+#    #+#             */
/*   Updated: 2017/05/16 09:30:35 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char			*get_o_u_args(t_print *elem, va_list ap)
{
	uintmax_t	data;
	char		*str;
	
	data = va_arg(ap, uintmax_t);
	if (LEN == 'H')
		data = (unsigned char)data;
	if (LEN == 'h')
		data = (unsigned short)data;
	if (LEN == 'l')
		data = (unsigned long)data;
	if (LEN == 'L')
		data = (unsigned long long)data;
	if (LEN == 'z')
		data = (size_t)data;
	if (LEN == '0')
		data = (int)data;
	if (SPEC == 'o')
	{
		str = ft_itoa_base_maj(data, 8, 0);
		SIZE = ft_strlen(str);
		return (str);
	}
	str = ft_itoa_base_maj(data, 10, 0);
	SIZE = ft_strlen(str);
	return (str);
}

