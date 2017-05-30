/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 05:44:42 by fdidelot          #+#    #+#             */
/*   Updated: 2017/05/30 07:39:04 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char            *get_hexa_args(t_print *elem, va_list ap)
{
    uintmax_t   data;
    char        *str;

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

char            *get_o_u_args(t_print *elem, va_list ap)
{
    uintmax_t   data;
    char        *str;

    data = va_arg(ap, uintmax_t);
    if (LEN == 'H' && SPEC != 'U' && SPEC != 'O')
        data = (unsigned char)data;
    if (LEN == 'h' && SPEC != 'U' && SPEC != 'O')
        data = (unsigned short)data;
    if (LEN == 'l' || SPEC == 'U' || SPEC == 'O')
		data = (unsigned long)data;
	if (LEN == 'L' && SPEC != 'U' && SPEC != 'O')
        data = (unsigned long long)data;
    if (LEN == 'z' && SPEC != 'U' && SPEC != 'O')
        data = (size_t)data;
    if (LEN == '0' && SPEC != 'U' && SPEC != 'O')
        data = (unsigned int)data;
    if (SPEC == 'o' || SPEC == 'O')
    {
		str = ft_itoa_base_maj(data, 8, 0);
        SIZE = ft_strlen(str);
        return (str);
    }
    str = ft_itoa_base_maj(data, 10, 0);
    SIZE = ft_strlen(str);
   return (str);
}

char    *string(t_print *elem, va_list ap)
{
    char *str;

	str = va_arg(ap, char*);
	if (str == NULL)
	{
		SIZE = 6;
		return (ft_strdup("(null)"));
	}
	STOCK = ft_strdup(str);
    SIZE = ft_strlen(STOCK);
    if ((NACC < (int)SIZE && ACC))
        apply_width_string(elem);
    return (STOCK);
}

char			*get_signed_number(t_print *elem, va_list ap)
{
	intmax_t	data;
	char		*str;

	data = va_arg(ap, intmax_t);
	if (LEN == 'H' && SPEC != 'D')
		data = (char)data;
	if (LEN == 'h' && SPEC != 'D')
		data = (short)data;
	if (LEN == 'l' && SPEC != 'D')
		data = (long)data;
	if (LEN == 'L' && SPEC == 'D')
		data = (long long)data;
	if (LEN == 'z' && SPEC != 'D')
		data = (ssize_t)data;
	if (LEN == '0' && SPEC != 'D')
		data = (int)data;
	str = ft_itoa_base_maj_signed(data, 10);
	SIZE = ft_strlen(str);
	return (str);
}
