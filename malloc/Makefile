# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snedir <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/07 01:53:42 by snedir            #+#    #+#              #
#    Updated: 2018/06/04 01:42:59 by snedir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test.out

SRCS = test.c

OBJS = $(SRCS:.c=.o)

SRCPATH = ./

FLAGS = -g -fsanitize=address

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(addprefix $(SRCPATH), $(SRCS))
	@gcc $(FLAGS) $(OBJS) -o $(NAME)

.PHONY: all clean fclean re
