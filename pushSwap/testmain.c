/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 16:43:43 by snedir            #+#    #+#             */
/*   Updated: 2018/08/05 05:08:10 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/get_next_line.h"
#include "push_swap.h"

int	check_input(t_env *e, char **argv, int argc)
{
	int	tmp_value;
	char	*test;
	t_stack	*tmp;

	tmp_value = 0;
	tmp = STACK1;
	test = NULL;
	while (--argc > 0)
	{
		tmp_value = ft_atoi(argv[argc]);
		test = ft_itoa(tmp_value);
		if (ft_strcmp(test, argv[argc]) != 0)
			return (printf("Error\n"));
		ft_strdel(&test);
		while (tmp)
		{
			if (tmp->nb == tmp_value)
				return (printf("Error\n"));
			tmp = tmp->prev;
		}
		push(e, (double)tmp_value, 0);
		tmp = STACK1;
	}
	return (0);
}

int	is_sorted(t_env *e)
{
	t_stack	*tmp;
	int		i;

	tmp = STACK1;
	i = 0;
	while (tmp)
	{
		if (tmp->prev != NULL && tmp->nb > tmp->prev->nb)
			return (printf("KO\n"));
		tmp = tmp->prev;
		i = 4;
	}
	return (printf("%c%c\n", 'K' + i, 'O' - i) + 1);
}

int	is_reverse_sorted(t_env *e)
{
	t_stack	*tmp;
	int		i;

	tmp = STACK1;
	i = 0;
	while (tmp->prev)
		tmp = tmp->prev;
	while (tmp)
	{
		if (tmp->next != NULL && tmp->nb > tmp->next->nb)
			return (printf("KO\n"));
		tmp = tmp->next;
		i = 4;
	}
	return (printf("%c%c\n", 'K' + i, 'O' - i) + 5);
}
int	get_user_input(t_env *e)
{
	char *line;
	int	i;
	size_t	size;
	int		valid;

	line = NULL;
	i = -1;
	valid = 0;
	while (get_next_line2(0, &line) > 0)
	{
		/*if (line == NULL)
			return (printf("Error\n"));*/
		while (++i < SIZE_ARRAY_FUNCT)
		{
			if ((ft_strcmp(line, e->op_tab[i].fnc_name) == 0))
			{
				size = ft_strlen(line);
				if (size == ft_strlen(e->op_tab[i].fnc_name))
					push(e, (double)i, 2);
				else
					return (printf("Error wtf\n"));
				valid = 1;
			}
		}
		i = -1;
				free(line);
		line = NULL;
	}
	if (valid != 1)
			return (printf("Error\n"));
	return (1);
}


int main(int argc, char **argv)
{
	t_env *e = ft_memalloc(sizeof(t_env));
	e->op_tab = init_func_array();
	op_tab_fill(e);
	if (argc < 3)
		return (0);
	if (check_input(e, argv, argc) != 0)
		return (0);
	//is_sorted(e);
	get_user_input(e);
	t_stack *tmp = e->start_instructions;
	while (tmp)
	{
		e->op_tab[tmp->nb].op(e);
		tmp = tmp->next;
	}
	print_stacks_from_stacks(e);
	is_reverse_sorted(e);
}
