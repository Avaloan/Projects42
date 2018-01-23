# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snedir <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/07 01:53:42 by snedir            #+#    #+#              #
#    Updated: 2018/01/23 01:44:12 by snedir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

SRCS = main.c \
	   lists.c \
	   parsing.c \
	   room.c \
	   pipe.c \
	   file.c \
	   parser.c

OBJS = $(SRCS:.c=.o)

SRCPATH = ./srcs/

FLAGS = -O3 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@make -C gnl/libft
	@gcc $(FLAGS) $(OBJS) gnl/libft/libft.a -o $(NAME)

%.o: $(SRCPATH)%.c
	@gcc $(FLAGS) -c $< -I includes/

.PHONY: all clean fclean re

clean:
	@make -C gnl/libft clean
	@rm -rf $(OBJS)

fclean: clean
	@make -C gnl/libft fclean
	@rm -rf gnl/libft/libft.a $(NAME)

re: fclean all
