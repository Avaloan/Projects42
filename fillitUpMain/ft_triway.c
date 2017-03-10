/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triway.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 20:51:13 by snedir            #+#    #+#             */
/*   Updated: 2017/03/11 00:49:15 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_iter	*f1(t_iter *cmp)
{
	//printf("cmp i %d\n", cmp->i);
	cmp->i += 1;
	printf("cmp i2 %d\n", cmp->i);
	return (cmp);
}

t_iter *f3(t_iter *cmp)
{
	cmp->i += 1;
	cmp->count += 1;
	return (cmp);
}
