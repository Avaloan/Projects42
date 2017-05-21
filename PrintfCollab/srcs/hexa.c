/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:00:46 by snedir            #+#    #+#             */
/*   Updated: 2017/05/21 04:29:18 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char			*get_hexa_args(t_print *elem, va_list ap)
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
		data = (unsigned int)data;
	if (SPEC == 'X')
	{
		str = ft_itoa_base_maj(data, 16, 1);
		SIZE = ft_strlen(str);
		return (str);
	}
	str = ft_itoa_base_maj(data, 16, 0);
	SIZE = ft_strlen(str);
	return (str);
}

char			*get_pointer(t_print *elem, va_list ap)
{
	uintmax_t	data;
	char		*str;

	data = (uintmax_t)va_arg(ap, void*);
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
		data = (unsigned long)data;
	str = ft_itoa_base_maj(data, 16, 0);
	SIZE = ft_strlen(str);
	return (str);
}
