/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 16:43:43 by snedir            #+#    #+#             */
/*   Updated: 2018/07/11 15:51:20 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	new = ft_memalloc(sizeof(t_funct) * SIZE_ARRAY_FUNCT);
	while (++i < SIZE_ARRAY_FUNCT)
		new[i].fnc_name = ft_strdup(fnc_name[i]);
	return (new);
}


t_stack		*new_stack_elem(int value)
{
	t_stack	*new;

	new = ft_memalloc(sizeof(t_stack));
	new->nb = value;
	return (new);
}

void		add_on_stack(t_stack **stack, int value)
{
	t_stack	*new_elem;
	
	new_elem = NULL;
	if (!(*stack))
	{
		*stack = new_stack_elem(value);
		/*LOOK_OUT1.head = *stack1;
		LOOK_OUT1.last = *stack1;*/
		return ;
	}
	new_elem = new_stack_elem(value);
	(*stack)->next = new_elem;
	new_elem->prev = *stack;
	*stack = new_elem;
}

double		pop(t_stack **stack)
{
	int		value;
	t_stack	*tmp;

	if (!(tmp = *stack))
		return (ERROR);
	*stack = (*stack)->prev;
	value = tmp->nb;
	free(tmp);
	return ((double)value);
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
	tmp2->prev = NULL;
	ft_memdel((void**)&tmp);
	return (value);
}
void		push(t_env *e, double value, int flag)
{
	if (value == ERROR)
		return ;
	if (flag == 0)
		add_on_stack(&e->stack1, (int)value);
	else
		add_on_stack(&e->stack2, (int)value);
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
		printf("STACK2 %d\n", tmp2->nb);
		tmp2 = tmp2->prev;
	}
}

/*
void	print_stacks_from_control(t_env *e)
{
	t_stack *ptr1 = c1->head;
	t_stack *ptr2 = c2->head;
	while (ptr1 && ptr2)
	{
		printf("%d\n", ptr1->nb);//, ptr2->nb);
		ptr1 = ptr1->prev;
		ptr2 = ptr2->prev;
	}
}
*/
