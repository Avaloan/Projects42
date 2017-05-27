/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 23:55:07 by fdidelot          #+#    #+#             */
/*   Updated: 2017/05/28 01:02:50 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_print *elem;
	char	*copy;
	int		j;

	j = 0;
	while (format[j] && j != -1)
		if (format[j++] == '%')
			j = -1;
	va_start(ap, format);
	copy = ft_strdup(format);
	elem = NULL;
	if (j == -1)
	{
		elem = analyse(copy, elem);
		elem = create_stock(elem, ap);
	}
	/*int i = 1;
	while (elem)
	{
		printf("%d : ", i++);
		printf("MIN = %d,", MINUS);
		printf("PLUS = %d,", PLUS);
		printf("SPACE = %d,", SPACE);
		printf("HASH = %d,", HASH);
		printf("ZERO = %d,", ZERO);
		printf("NUM = %d,", NUM);
		printf("STAR = %d,", STAR);
		printf("ACC = %d,", ACC);
		printf("NACC = %d,", NACC);
		printf("STARAC = %d,", STARAC);
		printf("DOLL = %d,", DOLL);
		printf("SPEC = %c,", SPEC);
		printf("LEN = %c,", LEN);
		printf("STOCK = %s,", STOCK);
		printf("SIZE = %lu,", SIZE);
		printf("SIZEF = %d\n\n", SIZEF);
		elem = NEXT;
		}*/
	va_end(ap);
	return (da_print(elem, copy));
}
