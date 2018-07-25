/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 16:43:43 by snedir            #+#    #+#             */
/*   Updated: 2018/07/11 15:52:54 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "push_swap.h"

int main(int argc, char **argv)
{
	int i = -1;
	t_env *e = ft_memalloc(sizeof(t_env));
	int tab[] = {1,2,3,4,5,6,7,8,9,10,11};
	t_funct *new = init_func_array();
	/*while (++i < SIZE_ARRAY_FUNCT)
		printf("%s\n", new[i].fnc_name);*/
	while (++i < SIZE_ARRAY_FUNCT)
		push(e, (double)tab[i], 0);
	i = -1;
	/*t_stack *tmp = STACK1;
	t_stack *tmp2;
	//print_stacks_from_stacks(e);
	while (STACK1->prev)
	{
		printf("stack 1 addr: %p\n", STACK1);
		STACK1 = STACK1->prev;
	}
	tmp2 = STACK1->next;
	//print_stacks_from_stacks(e);
	tmp2->prev = STACK1->prev;
	ft_memdel((void**)&STACK1);
	STACK1 = tmp;
	push(e, 1, 0);*/
	rra(e);
	print_stacks_from_stacks(e);
	/*rra(e);
	rra(e);
	rra(e);
	rra(e);*/
	//rv_pop(&STACK1);
	//rv_pop(&STACK1);
	/*rv_pop(&STACK1);
	rv_pop(&STACK1);
	rv_pop(&STACK1);*/
	//print_stacks_from_stacks(e);
}
