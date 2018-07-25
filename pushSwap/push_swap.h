/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 17:11:22 by snedir            #+#    #+#             */
/*   Updated: 2018/07/10 15:47:40 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef				PUSH_SWAP_H
# define			PUSH_SWAP_H
# define			SIZE_ARRAY_FUNCT 11
# define			LOOK_OUT1 e->st_pointers_1
# define			LOOK_OUT2 e->st_pointers_2
# define			STACK1 e->stack1
# define			STACK2 e->stack2
# define			OP_TAB e->op_tab
# define			ERROR 0.987654321
# include			"libft/libft.h"


typedef struct		s_control
{
	struct s_stack	*head;
	struct s_stack	*last;
}					t_control;

typedef struct		s_stack
{
	int				nb;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct		s_env
{
	t_control		st_pointers_1;
	t_control		st_pointers_2;
	t_stack			*stack1;
	t_stack			*stack2;
	struct s_funct	*op_tab;
}					t_env;

typedef struct		s_funct
{
	void			(*op)(t_env *e);
	char			*fnc_name;
}					t_funct;

/*
** MISC FNC
*/

t_funct				*init_func_array();
void				print_stacks_from_control(t_env *e);
void				print_stacks_from_stacks(t_env *e);

/*
** STACK HANDLERS
*/

double				pop(t_stack **stack);
double				rv_pop(t_stack **stack);
void				push(t_env *e, double value, int flag);
t_stack				*new_stack_elem(int value);

/*
** SWAP OPE
*/

void				sa(t_env *e);
void				sb(t_env *e);
void				ss(t_env *e);

/*
** PUSH OPE
*/

void				pa(t_env *e);
void				pb(t_env *e);

/*
** ROTATE UP OPE
*/

void				ra(t_env *e);
void				rb(t_env *e);
void				rr(t_env *e);

/*
** ROTATE DOWN OPE
*/

void				rra(t_env *e);
void				rrb(t_env *e);
void				rrr(t_env *e);
#endif
