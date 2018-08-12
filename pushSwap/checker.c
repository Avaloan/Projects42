/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 16:43:43 by snedir            #+#    #+#             */
/*   Updated: 2018/08/05 03:09:17 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		op_tab_fill(t_env *e)
{
	e->op_tab[0].op = sa;
	e->op_tab[1].op = sb;
	e->op_tab[2].op = ss;
	e->op_tab[3].op = pa;
	e->op_tab[4].op = pb;
	e->op_tab[5].op = ra;
	e->op_tab[6].op = rb;
	e->op_tab[7].op = rr;
	e->op_tab[8].op = rra;
	e->op_tab[9].op = rrb;
	e->op_tab[10].op = rrr;
}

t_funct		*init_func_array()
{
	t_funct	*new;
	int		i;
	char	*fnc_name[11];

	i = -1;
	fnc_name[0] = "sa\0\0";
	fnc_name[1] = "sb\0\0";
	fnc_name[2] = "ss\0\0";
	fnc_name[3] = "pa\0\0";
	fnc_name[4] = "pb\0\0";
	fnc_name[5] = "ra\0\0";
	fnc_name[6] = "rb\0\0";
	fnc_name[7] = "rr\0\0";
	fnc_name[8] = "rra\0";
	fnc_name[9] = "rrb\0";
	fnc_name[10] = "rrr\0";
	if (!(new = ft_memalloc(sizeof(t_funct) * SIZE_ARRAY_FUNCT)))
		return (NULL);
	while (++i < SIZE_ARRAY_FUNCT)
		new[i].fnc_name = ft_strdup(fnc_name[i]);
	return (new);
}

t_stack		*new_stack_elem(int value)
{
	t_stack	*new;

	if (!(new = ft_memalloc(sizeof(t_stack))))
		return (NULL);
	new->nb = value;
	return (new);
}

void		add_on_stack(t_stack **stack, int value)
{
	t_stack	*new_elem;
	
	new_elem = NULL;
	if (!(*stack))
	{
		if (!(*stack = new_stack_elem(value)))
			return ;
		return ;
	}
	new_elem = new_stack_elem(value);
	(*stack)->next = new_elem;
	new_elem->prev = *stack;
	*stack = new_elem;
}

void		add_instructions(t_stack **stack, int value, t_stack **start_instructions)
{
	t_stack	*new_elem;
	
	new_elem = NULL;
	if (!(*stack))
	{
		if (!(*stack = new_stack_elem(value)))
			return ;
		*start_instructions = *stack;
		return ;
	}
	new_elem = new_stack_elem(value);
	(*stack)->next = new_elem;
	new_elem->prev = *stack;
	*stack = new_elem;
}

double		pop(t_stack **stack)
{
	double		value;
	t_stack	*tmp;

	value = ERROR;
	if (!(tmp = *stack))
		return (ERROR);
	*stack = (*stack)->prev;
	if (*stack)
		(*stack)->next = NULL;
	value = tmp->nb;
	ft_memdel((void**)&tmp);
	return (value);
}

double		rv_pop(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	double	value;

	tmp = *stack;
	while (tmp->prev)
		tmp = tmp->prev;
	value = tmp->nb;
	tmp2 = tmp->next;
	if (tmp2)
		tmp2->prev = NULL;
	ft_memdel((void**)&tmp);
	return (value);
}

/*
** PEUT ADD SUR LES 2 STACKS
*/

void		push(t_env *e, double value, int flag)
{
	if (value == ERROR)
		return ;
	if (flag == 0)
		add_on_stack(&e->stack1, (int)value);
	else if (flag == 1)
		add_on_stack(&e->stack2, (int)value);
	else
		add_instructions(&e->stack_instructions, (int)value, &e->start_instructions);
}

void	print_stacks_from_stacks(t_env *e)
{
	t_stack *tmp = STACK1;
	t_stack *tmp2 = STACK2;
	while (tmp)
	{
		printf("STACK1 %d\n", tmp->nb);
		tmp = tmp->prev;
	}
	while (tmp2)
	{
		printf("JE PUE LA MERDE %d\n", tmp2->nb);
		tmp2 = tmp2->prev;
	}
}
