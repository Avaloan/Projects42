# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gquerre <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/14 02:23:54 by gquerre           #+#    #+#              #
#    Updated: 2017/02/04 03:26:34 by snedir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = *.c

FLAG = -Werror -Wextra -Wall

OBJ = *.o

all: $(NAME)

$(NAME):
	gcc -g $(FLAG) $(SRC) -o $(NAME) -I. -L. -lft

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
