/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 00:37:00 by fdidelot          #+#    #+#             */
/*   Updated: 2017/05/21 04:05:07 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h> //printf use
# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
# include "../libft/libft.h"

/* FLAGS */
# define MINUS elem->minus
# define PLUS elem->plus
# define SPACE elem->space
# define HASH elem->hashtag
# define ZERO elem->zero

/* WIDTH */
# define NUM elem->number
# define STAR elem->asterix

/* PRECISION */
# define ACC elem->accuracy
# define NACC elem->num_acc
# define STARAC elem->starcuracy

/* LENGHT */
# define LEN elem->lenght

/* SPECIFIER */
# define SPEC elem->specifier

/* MISCELLANEOUS */
# define STOCK elem->stock
# define NOPE elem->nope
# define DOLL elem->priority
# define SIZE elem->content_size

/* LIST */
# define LST elem->list
# define START elem->start
# define NEXT elem->next

// Pas OUBLIER DE FREE TAMER (la liste) !!!!!!!!!!!!!!!!!!!!!!
typedef	struct		s_print
{
	int				minus;
	int				plus;
	int				space;
	int				hashtag;
	int				zero;
	int				number;
	int				asterix;
	int				accuracy;
	int				num_acc;
	int				starcuracy;
	char			lenght;
//	int				size;
	char			specifier;
//	int				nope;
	int				priority; //RAJOUT INIT
	size_t			content_size;
	char			*stock;
	struct s_print	*next;
}					t_print;


char				*string(t_print *elem, va_list ap);
char				*apply_width_string(t_print *elem);
char				*get_signed_number(t_print *elem, va_list ap);
char				*arg_char(t_print *elem, va_list ap);
char				*get_o_u_args(t_print *elem, va_list ap);
char				*get_hexa_args(t_print *elem, va_list ap);
void				parcours_liste(t_print *elem, va_list ap);
char				*wide_char(t_print *elem, va_list ap);
int					countspace(char *mask);
char				*binary_to_dec(char **split, int sizetab);
char				*create_mask(int len);
char				*fill_mask(char *mask, char *fill);
void				join(t_print *elem, t_print *news);
int					lenght(char *format, t_print *elem);
int					ft_printf(const char *format, ...);
int					create_elem(t_print *elem, char *format);
int					num_width(char *format, t_print *elem, int start);
int					num_acc(char *format, t_print *elem, int start);
t_print				*analyse(char *format, t_print *elem);
int					flags(char format, t_print *elem);
char				specifier(t_print *elem, char format);
t_print				*init();
int					print_list(t_print *elem, char *format);
int					wide_string(t_print *elem, va_list ap);
int					apply_hash(t_print *elem);
char				*get_pointer(t_print *elem, va_list ap);

#endif
