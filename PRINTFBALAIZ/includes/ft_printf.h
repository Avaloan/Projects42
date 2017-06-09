/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 00:37:00 by fdidelot          #+#    #+#             */
/*   Updated: 2017/06/09 05:39:17 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
# include "../libft/libft.h"

# define MINUS elem->minus
# define PLUS elem->plus
# define SPACE elem->space
# define HASH elem->hashtag
# define ZERO elem->zero

# define NUM elem->number
# define STAR elem->asterix

# define ACC elem->accuracy
# define NACC elem->num_acc
# define STARAC elem->starcuracy

# define LEN elem->lenght

# define SPEC elem->specifier

# define STOCK elem->stock
# define DOLL elem->priority
# define SIZE elem->content_size
# define SIZEF elem->size_flags
# define SIZEW elem->wide_size
# define RUSTINE elem->rustine

# define LST elem->list
# define START elem->start
# define NEXT elem->next

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
	int				priority;
	int				size_flags;
	int				wide_size;
	int				rustine;
	char			specifier;
	char			lenght;
	char			*stock;
	size_t			content_size;
	struct s_print	*next;
}					t_print;

int					ft_printf(const char *format, ...);

int					num_width(char *format, t_print *elem);
int					num_acc(char *format, t_print *elem);
int					create_elem(t_print *elem, char *format);
t_print				*analyse(char *format, t_print *elem);

char				specifier(t_print *elem, char format);
char				spe2(t_print *elem, char format);
int					flags(char format, t_print *elem);
int					length(char *format, t_print *elem);
int					da_check(char format);

t_print				*init(void);
void				join(t_print *elem, t_print *news);

char				*apply_width_string(t_print *elem);
char				*get_pointer(t_print *elem, va_list ap);
int					wide_string(t_print *elem, va_list ap);
int					wide_str_trans(t_print *elem, wchar_t wide);

void				add_plus_space(t_print *elem, int id);
void				precision(t_print *elem);
int					apply_hash(t_print *elem);

char				*create_mask(int len);
char				*fill_mask(char *mask, char *fill);
char				*wide_char(t_print *elem, va_list ap);
char				*binary_to_dec(char **split, int sizetab);
char				*arg_char(t_print *elem, va_list ap);

char				*string(t_print *elem, va_list ap);
char				*get_o_u_args(t_print *elem, va_list ap);
char				*get_hexa_args(t_print *elem, va_list ap);
char				*get_signed_number(t_print *elem, va_list ap);
char				*da_string(t_print *elem, char *str);

t_print				*create_stock(t_print *elem, va_list ap);
int					get_arg(t_print *elem, va_list ap);
void				apply_flags(t_print *elem);
int					print_list(t_print *elem, char *format);
size_t				da_print(t_print *elem, char *format, int i, size_t sp);

void				field(t_print *elem);
void				field_p(t_print *elem, char c, int size);
void				field_neg(t_print *elem, char c, int size);
void				field_zero(t_print *elem);

int					ft_velcro(char *str, t_print *elem);
void				ft_scotch(t_print *elem, char *space);
void				ft_chatterton(int i, int size, int rust, t_print *elem);
void				ft_nether(t_print *elem);

int					*tabnum(void);
int					zero_fill(int len);
int					countspace(char *mask);
int					length2(char *format, t_print *elem);

void				bandaid(size_t *sp, int *i, t_print *elem);
int					meta_create(t_print *elem, char *format, int i);
size_t				bandage(size_t sp, char *f);
void				curmax(t_print *elem, va_list ap);
int					in_create(t_print *elem, char *format, int i, int j);

#endif
