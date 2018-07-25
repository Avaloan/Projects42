# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gquerre <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/24 05:47:01 by gquerre           #+#    #+#              #
#    Updated: 2018/07/09 14:15:33 by snedir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		test

SRC =		./testmain.c \
			./checker.c

OP_SRC =	./OP/p_op.c \
			./OP/s_op.c \
			./OP/r_op.c \
			./OP/rr_op.c

FLAG =	-I -Wextra -Wall -Werror

SUPP =	./push_swap.h ./libft/libft.a

OBJ =	$(SRC:.c=.o) $(OP_SRC:.c=.o)

all: $(NAME)

$(NAME): ./libft/libft.a $(OBJ)
	gcc $(FLAG) -I $(SUPP) $(OBJ) -o $(NAME)

libft/libft.a:
	make fclean -C ./libft/
	make -C ./libft

clean:
	rm -f $(OBJ)
	rm -f ./libft/libft.a
	make clean -C ./libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft/

re: fclean all

