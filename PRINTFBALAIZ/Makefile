#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/25 04:13:00 by fdidelot          #+#    #+#              #
#    Updated: 2017/06/08 02:45:12 by snedir           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a
FLAGS = -g -Wall -Wextra -Werror
PRINTFSRC =	ft_printf.c \
			apply_flags.c \
			apply_width.c \
			char.c \
			check.c \
			format.c \
			get_spec.c \
			parser.c \
			struct.c

LFTSRC =	ft_strwdup.c \
			ft_atoi_u.c \
			ft_atoi.c \
			ft_itoa.c \
			ft_itoa_base.c \
			ft_itoa_base_maj.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strjoin_free.c \
			ft_strlen.c \
			ft_strnew.c \
			ft_strsub.c \
			ft_memalloc.c \
			ft_putchar.c \
			ft_memset.c \
			ft_strchr.c \
			ft_strdel.c \
			ft_memdel.c \
			ft_strcmp.c \
			ft_isdigit.c \
			ft_itoa_base_maj_signed.c \
			ft_strrev.c \
			ft_strsplit.c \
			ft_strjoin_size_free.c \

OBJS1 = $(LFTSRC:.c=.o)
	OBJS2 = $(PRINTFSRC:.c=.o)
	OBJS = $(OBJS2) $(OBJS1)

all: $(NAME)

$(NAME): $(addprefix objs/, $(OBJS2)) $(addprefix objs/, $(OBJS1))
		@printf "\033[0;35m> Compiling libftprintf.a\033[0m"
			@ar rc $(NAME) $(addprefix objs/, $(OBJS))
				@printf "\033[0;32m > OK\n\033[0m"

$(addprefix objs/, $(OBJS1)): $(addprefix libft/, $(LFTSRC))
		@printf "\033[0;35m.\033[0m"
			@gcc $(FLAGS) -c $(addprefix libft/, $(addsuffix .c, $(basename $(notdir $@)))) -o objs/$(notdir $@) -I includes/

$(addprefix objs/, $(OBJS2)): $(addprefix srcs/, $(PRINTFSRC))
		@test -d objs || mkdir objs
			@printf "\033[0;35m.\033[0m"
				@gcc $(FLAGS) -c $(addprefix srcs/, $(addsuffix .c, $(basename $(notdir $@)))) -o objs/$(notdir $@) -I includes/

main: a.out
		@printf "\033[0;31m- Executing a.out -\n\033[0m"
			@./a.out
				@printf "\033[0;31m-- End of a.out --\n\033[0m"

a.out: $(NAME) main.c
		@gcc -Wall -Wextra main.c -L. -lftprintf -I includes/

test: test.out
		@printf "\033[0;31m- Executing test.out -\n\033[0m"
			@./test.out $(ARGS)
				@printf "\033[0;31m-- End of test.out --\n\033[0m"

test.out: $(NAME) test.c
		@gcc -Wall -Wextra test.c -L. -lftprintf -I includes/ -o test.out

clean:
		@rm -rdf objs/

fclean: clean
		@rm -f $(NAME)

mainclean:
		@rm -f a.out

testclean:
		@rm -f test.out

cleanall: mainclean testclean fclean

re: fclean all
